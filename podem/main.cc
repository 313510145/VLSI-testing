#include <iostream>
#include <ctime>
#include "circuit.h"
#include "GetLongOpt.h"
#include "ReadPattern.h"
using namespace std;

// All defined in readcircuit.l
extern char* yytext;
extern FILE *yyin;
extern CIRCUIT Circuit;
extern int yyparse (void);
extern bool ParseError;

extern void Interactive();

GetLongOpt option;

int SetupOption(int argc, char ** argv)
{
    option.usage("[options] input_circuit_file");
    option.enroll("help", GetLongOpt::NoValue,
            "print this help summary", 0);
    option.enroll("logicsim", GetLongOpt::NoValue,
            "run logic simulation", 0);
    option.enroll("plogicsim", GetLongOpt::NoValue,
            "run parallel logic simulation", 0);
    option.enroll("fsim", GetLongOpt::NoValue,
            "run stuck-at fault simulation", 0);
    option.enroll("stfsim", GetLongOpt::NoValue,
            "run single pattern single transition-fault simulation", 0);
    option.enroll("transition", GetLongOpt::NoValue,
            "run transition-fault ATPG", 0);
    option.enroll("input", GetLongOpt::MandatoryValue,
            "set the input pattern file", 0);
    option.enroll("output", GetLongOpt::MandatoryValue,
            "set the output pattern file", 0);
    option.enroll("bt", GetLongOpt::OptionalValue,
            "set the backtrack limit", 0);
    option.enroll("ass0", GetLongOpt::NoValue,
            "assignment 0", 0);
    option.enroll("path", GetLongOpt::NoValue,
            "assignment 1", 0);
    option.enroll("start", GetLongOpt::MandatoryValue,
            "set the primary input", 0);
    option.enroll("end", GetLongOpt::MandatoryValue,
            "set the primary output", 0);
    option.enroll("pattern", GetLongOpt::NoValue,
            "assignment 2", 0);
    option.enroll("num", GetLongOpt::MandatoryValue,
            "set the number of random patterns", 0);
    option.enroll("unknown", GetLongOpt::NoValue,
            "consider unknown values", 0);
    option.enroll("mod_logicsim", GetLongOpt::NoValue,
            "assignment 2", 0);
    option.enroll("simulator", GetLongOpt::MandatoryValue,
            "assignment 3", 0);
    option.enroll("check_point", GetLongOpt::NoValue,
            "assignment 4", 0);
    option.enroll("bridging", GetLongOpt::NoValue,
            "assignment 4", 0);
    option.enroll("checkpoint", GetLongOpt::NoValue,
            "run for checkpoint fault list", 0);
    option.enroll("bridging_fsim", GetLongOpt::NoValue,
            "assignment 5", 0);
    option.enroll("trace", GetLongOpt::NoValue,
            "print PODEM implementation", 0);
    option.enroll("random_pattern", GetLongOpt::NoValue,
            "assignment 6", 0);
    option.enroll("bridging_atpg", GetLongOpt::NoValue,
            "assignment 6", 0);
    int optind = option.parse(argc, argv);
    if ( optind < 1 ) { exit(0); }
    if ( option.retrieve("help") ) {
        option.usage();
        exit(0);
    }
    return optind;
}

int main(int argc, char ** argv)
{
    int optind = SetupOption(argc, argv);
    clock_t time_init, time_end;
    time_init = clock();
    //Setup File
    if (optind < argc) {
        if ((yyin = fopen(argv[optind], "r")) == NULL) {
            cout << "Can't open circuit file: " << argv[optind] << endl;
            exit( -1);
        }
        else {
            string circuit_name = argv[optind];
            string::size_type idx = circuit_name.rfind('/');
            if (idx != string::npos) { circuit_name = circuit_name.substr(idx+1); }
            idx = circuit_name.find(".bench");
            if (idx != string::npos) { circuit_name = circuit_name.substr(0,idx); }
            Circuit.SetName(circuit_name);
        }
    }
    else {
        cout << "Input circuit file missing" << endl;
        option.usage();
        return -1;
    }
    cout << "Start parsing input file\n";
    yyparse();
    if (ParseError) {
        cerr << "Please correct error and try Again.\n";
        return -1;
    }
    fclose(yyin);
    Circuit.FanoutList();
    Circuit.SetupIO_ID();
    Circuit.Levelize();
    Circuit.Check_Levelization();
    Circuit.InitializeQueue();

    if (option.retrieve("logicsim")) {
        //logic simulator
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.LogicSimVectors();
    }
    else if (option.retrieve("plogicsim")) {
        //parallel logic simulator
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.ParallelLogicSimVectors();
    }
    else if (option.retrieve("stfsim")) {
        //single pattern single transition-fault simulation
        Circuit.MarkOutputGate();
        Circuit.GenerateAllTFaultList();
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.TFaultSimVectors();
    }
    else if (option.retrieve("transition")) {
        Circuit.MarkOutputGate();
        Circuit.GenerateAllTFaultList();
        Circuit.SortFaninByLevel();
        if (option.retrieve("bt")) {
            Circuit.SetBackTrackLimit(atoi(option.retrieve("bt")));
        }
        Circuit.TFAtpg();
    }
    else if (option.retrieve("ass0")) {
        cout << "number of inputs: " << Circuit.No_PI() << endl
             << "number of outputs: " << Circuit.No_PO() << endl;
        Circuit.PrintNo_GateEachType();
        cout << "number of flip-flops (PPIs): " << Circuit.No_PPI() << endl;
        Circuit.PrintNo_Net();
        cout << "average number of fanouts of each gate (all types): " << Circuit.AverageNo_Fanout() << endl;
    }
    else if (option.retrieve("path")) {
        Circuit.PrintAllPath(option.retrieve("start"), option.retrieve("end"));
    }
    else if (option.retrieve("pattern")) {
        Circuit.GenerateRandomPattern(option.retrieve("num"), option.retrieve("output"), option.retrieve("unknown"));
    }
    else if (option.retrieve("mod_logicsim")) {
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.ModifiedLogicSimVectors();
    }
    else if (option.retrieve("simulator")) {
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.CompiledCodeSimulator(option.retrieve("simulator"));
    }
    else if (option.retrieve("check_point")) {
        Circuit.GenerateAllFaultList();
        Circuit.GenerateCheckPointFaultList();
        Circuit.CompareNo_Fault();
    }
    else if (option.retrieve("bridging")) {
        Circuit.GenerateBridgingFaultList();
        Circuit.OutputBridgingFaultList(option.retrieve("output"));
    }
    else if (option.retrieve("bridging_fsim")) {
        Circuit.GenerateBridgingFaultList();
        Circuit.SortFaninByLevel();
        Circuit.MarkOutputGate();
        Circuit.InitPattern(option.retrieve("input"));
        Circuit.ParallelBFaultSimVectors();
    }
    else if (option.retrieve("random_pattern")) {
        Circuit.GenerateAllFaultList();
        Circuit.SortFaninByLevel();
        Circuit.MarkOutputGate();
        if (option.retrieve("bt")) {
            Circuit.SetBackTrackLimit(atoi(option.retrieve("bt")));
        }
        Circuit.RandomPatternAtpg(option.retrieve("output"));
    }
    else if (option.retrieve("bridging_atpg")) {
        Circuit.GenerateBridgingFaultList();
        Circuit.SortFaninByLevel();
        Circuit.MarkOutputGate();
        if (option.retrieve("bt")) {
            Circuit.SetBackTrackLimit(atoi(option.retrieve("bt")));
        }
        Circuit.BFaultAtpg();
    }
    else {
        if (option.retrieve("checkpoint")) {
            Circuit.GenerateCheckPointFaultList();
            Circuit.AssignCheckPointFaultList();
        }
        else if (option.retrieve("trace")) {
            Circuit.SelectFaultList();
        }
        else {
            Circuit.GenerateAllFaultList();
        }
        Circuit.SortFaninByLevel();
        Circuit.MarkOutputGate();
        if (option.retrieve("fsim")) {
            //stuck-at fault simulator
            Circuit.InitPattern(option.retrieve("input"));
            Circuit.FaultSimVectors(option.retrieve("trace"));
        }
        else {
            if (option.retrieve("bt")) {
                Circuit.SetBackTrackLimit(atoi(option.retrieve("bt")));
            }
            //stuck-at fault ATPG
            Circuit.Atpg(false, option.retrieve("trace"));
        }
    }
    time_end = clock();
    cout << "total CPU time = " << double(time_end - time_init)/CLOCKS_PER_SEC << endl;
    cout << endl;
    return 0;
}
