#include <iostream>
#include "circuit.h"
#include "GetLongOpt.h"
using namespace std;

extern GetLongOpt option;

// Event-driven Parallel Pattern Logic simulation
void CIRCUIT::ParallelLogicSimVectors() {
    cout << "Run Parallel Logic simulation" << endl;
    unsigned int pattern_num = 0;
    unsigned int pattern_idx;
    unsigned int evaluation_num = 0;
    while (!Pattern.eof()) {
        for (pattern_idx = 0; pattern_idx < PatternNum; pattern_idx++) {
            if (!Pattern.eof()) {
                ++pattern_num;
                Pattern.ReadNextPattern(pattern_idx);
            }
            else break;
        }
        ScheduleAllPIs();
        evaluation_num += ParallelLogicSim();
        PrintParallelIOs(pattern_idx);
    }
    cout << "average number of gate evaluations for different number of packed patterns: " << static_cast<double>(evaluation_num) / pattern_num << endl
         << "percentage of average gate evaluations over the total number of gates: " << static_cast<double>(evaluation_num) / pattern_num / No_Gate() * 100 << "%\n";
}

//Assign next input pattern to PI's idx'th bits
void PATTERN::ReadNextPattern(unsigned idx)
{
    char V;
    for (int i = 0; i < no_pi_infile; i++) {
        patterninput >> V;
        if (V == '0') {
            inlist[i]->ResetWireValue(0, idx);
            inlist[i]->ResetWireValue(1, idx);
        }
        else if (V == '1') {
            inlist[i]->SetWireValue(0, idx);
            inlist[i]->SetWireValue(1, idx);
        }
        else if (V == 'X') {
            inlist[i]->SetWireValue(0, idx);
            inlist[i]->ResetWireValue(1, idx);
        }
    }
    //Take care of newline to force eof() function correctly
    patterninput >> V;
    if (!patterninput.eof()) patterninput.unget();
    return;
}

//Simulate PatternNum vectors
unsigned int CIRCUIT::ParallelLogicSim() {
    GATE* gptr;
    unsigned int evaluation_num = 0;
    for (unsigned int i = 0; i <= MaxLevel; i++) {
        while (!Queue[i].empty()) {
            gptr = Queue[i].front();
            Queue[i].pop_front();
            gptr->ResetFlag(SCHEDULED);
            evaluation_num += ParallelEvaluate(gptr);
        }
    }
    return evaluation_num;
}

//Evaluate parallel value of gptr
unsigned int CIRCUIT::ParallelEvaluate(GATEPTR gptr) {
    register unsigned i;
    bitset<PatternNum> new_value1(gptr->Fanin(0)->GetValue1());
    bitset<PatternNum> new_value2(gptr->Fanin(0)->GetValue2());
    switch (gptr->GetFunction()) {
        case G_AND:
        case G_NAND:
            for (i = 1; i < gptr->No_Fanin(); ++i) {
                new_value1 &= gptr->Fanin(i)->GetValue1();
                new_value2 &= gptr->Fanin(i)->GetValue2();
            }
            break;
        case G_OR:
        case G_NOR:
            for (i = 1; i < gptr->No_Fanin(); ++i) {
                new_value1 |= gptr->Fanin(i)->GetValue1();
                new_value2 |= gptr->Fanin(i)->GetValue2();
            }
            break;
        default: break;
    } 
    //swap new_value1 and new_value2 to avoid unknown value masked
    if (gptr->Is_Inversion()) {
        new_value1.flip(); new_value2.flip();
        bitset<PatternNum> value(new_value1);
        new_value1 = new_value2; new_value2 = value;
    }
    if (gptr->GetValue1() != new_value1 || gptr->GetValue2() != new_value2) {
        gptr->SetValue1(new_value1);
        gptr->SetValue2(new_value2);
        ScheduleFanout(gptr);
    }
    return gptr->No_Fanin();
}

void CIRCUIT::CompiledParallelEvaluate(ostream& os, GATEPTR gptr) {
    register unsigned int i;
    os << "\tG_" << gptr->GetName() << "[0] = G_" << gptr->Fanin(0)->GetName() << "[0];\n"
       << "\tG_" << gptr->GetName() << "[1] = G_" << gptr->Fanin(0)->GetName() << "[1];\n";
    switch (gptr->GetFunction()) {
        case G_AND:
        case G_NAND:
            for (i = 1; i < gptr->No_Fanin(); ++i) {
                os << "\tG_" << gptr->GetName() << "[0] &= G_" << gptr->Fanin(i)->GetName() << "[0];\n"
                   << "\tG_" << gptr->GetName() << "[1] &= G_" << gptr->Fanin(i)->GetName() << "[1];\n";
            }
            break;
        case G_OR:
        case G_NOR:
            for (i = 1; i < gptr->No_Fanin(); ++i) {
                os << "\tG_" << gptr->GetName() << "[0] |= G_" << gptr->Fanin(i)->GetName() << "[0];\n"
                   << "\tG_" << gptr->GetName() << "[1] |= G_" << gptr->Fanin(i)->GetName() << "[1];\n";
            }
            break;
        default: break;
    } 
    if (gptr->Is_Inversion()) {
        os << "\ttemp = G_" << gptr->GetName() << "[0];\n"
           << "\tG_" << gptr->GetName() << "[0] = ~G_" << gptr->GetName() << "[1];\n"
           << "\tG_" << gptr->GetName() << "[1] = ~temp;\n";
    }
    ScheduleFanout(gptr);
    return;
}

void CIRCUIT::PrintParallelIOs(unsigned idx)
{
    register unsigned i;
    for (unsigned j=0; j<idx; j++){
	    for (i = 0;i<No_PI();++i) { 
		    if(PIGate(i)->GetWireValue(0, j)==0){ 
			   if(PIGate(i)->GetWireValue(1, j)==1){
	    			cout << "F";
			   }
			   else cout << "0";
		    }
		    else{
			   if(PIGate(i)->GetWireValue(1, j)==1){
	    			cout << "1";
			   }
			   else cout << "X";
		    }

	    }
	    cout << " ";
	    for (i = 0;i<No_PO();++i) { 
		    if(POGate(i)->GetWireValue(0, j)==0){ 
			   if(POGate(i)->GetWireValue(1, j)==1){
	    			cout << "F";
			   }
			   else cout << "0";
		    }
		    else{
			   if(POGate(i)->GetWireValue(1, j)==1){
	    			cout << "1";
			   }
			   else cout << "X";
		    }
	    }
	    cout << endl;
    }
    return;
}

void CIRCUIT::ScheduleAllPIs()
{
    for (unsigned i = 0;i < No_PI();i++) {
        ScheduleFanout(PIGate(i));
    }
    return;
}

void CIRCUIT::CompiledCodeSimulator(const string& output) {
    cout << "Run compiled code simulation" << endl;
    ofstream output_file(output);
    if (!output_file) {
        cout << "Can't open output file: " << output << endl;
        exit(-1);
    }
    output_file << "#include <iostream>\n"
                << "#include <ctime>\n"
                << "#include <bitset>\n"
                << "#include <cstdlib>\n"
                << "#include <fstream>\n\n"
                << "const unsigned int PatternNum = " << PatternNum << ";\n\n"
                << "void evaluate();\n"
                << "void printIO(unsigned int idx);\n\n";
    for (unsigned int i = 0; i < No_Gate(); i++) {
        output_file << "std::bitset<PatternNum> G_" << this->Gate(i)->GetName() << "[2];\n";
    }
    output_file << "std::bitset<PatternNum> temp;\n\n"
                << "std::ofstream fout(\"" << this->Name << ".out\");\n\n"
                << "int main() {\n"
                << "\tclock_t time_init, time_end;\n"
                << "\ttime_init = clock();\n";
    unsigned int pattern_idx;
    while (!Pattern.eof()) {
        for (pattern_idx = 0; pattern_idx < PatternNum; pattern_idx++) {
            if (!Pattern.eof()) {
                Pattern.ReadNextPattern(pattern_idx);
            }
            else break;
        }
        for (unsigned int i = 0; i < No_PI(); i++) {
            output_file << "\tG_" << this->PIGate(i)->GetName() << "[0] = 0b" << this->PIGate(i)->GetWireValue(0) << ";\n"
                        << "\tG_" << this->PIGate(i)->GetName() << "[1] = 0b" << this->PIGate(i)->GetWireValue(1) << ";\n";
        }
        output_file << "\tevaluate();\n"
                    << "\tprintIO(" << pattern_idx << ");\n";
    }
    output_file << "\ttime_end = clock();\n"
                << "\tstd::cout << \"Total CPU Time = \" << double(time_end - time_init) / CLOCKS_PER_SEC << std::endl;\n"
                << "\treturn 0;\n"
                << "}\n\n";
	ScheduleAllPIs();
    output_file << "void evaluate() {\n";
    GATE* gptr;
    for (unsigned int i = 0; i <= MaxLevel; i++) {
        while (!Queue[i].empty()) {
            gptr = Queue[i].front();
            Queue[i].pop_front();
            gptr->ResetFlag(SCHEDULED);
            CompiledParallelEvaluate(output_file, gptr);
        }
    }
    output_file << "}\n\n"
                << "void printIO(unsigned int idx) {\n"
                << "\tfor (unsigned int i = 0; i < idx; i++) {\n";
    for (unsigned int i = 0; i < No_PI(); i++) {
        output_file << "\t\tif (G_" << this->PIGate(i)->GetName() << "[0][i] == 0) {\n"
                    << "\t\t\tif (G_" << this->PIGate(i)->GetName() << "[1][i] == 1) {\n"
                    << "\t\t\t\tfout << \"F\";\n"
                    << "\t\t\t}\n"
                    << "\t\t\telse {\n"
                    << "\t\t\t\tfout << \"0\";\n"
                    << "\t\t\t}\n"
                    << "\t\t}\n"
                    << "\t\telse {\n"
                    << "\t\t\tif (G_" << this->PIGate(i)->GetName() << "[1][i] == 1) {\n"
                    << "\t\t\t\tfout << \"1\";\n"
                    << "\t\t\t}\n"
                    << "\t\t\telse {\n"
                    << "\t\t\t\tfout << \"2\";\n"
                    << "\t\t\t}\n"
                    << "\t\t}\n";
    }
    output_file << "\t\tfout << \" \";\n";
    for (unsigned int i = 0; i < No_PO(); i++) {
        output_file << "\t\tif (G_" << this->POGate(i)->GetName() << "[0][i] == 0) {\n"
                    << "\t\t\tif (G_" << this->POGate(i)->GetName() << "[1][i] == 1) {\n"
                    << "\t\t\t\tfout << \"F\";\n"
                    << "\t\t\t}\n"
                    << "\t\t\telse {\n"
                    << "\t\t\t\tfout << \"0\";\n"
                    << "\t\t\t}\n"
                    << "\t\t}\n"
                    << "\t\telse {\n"
                    << "\t\t\tif (G_" << this->POGate(i)->GetName() << "[1][i] == 1) {\n"
                    << "\t\t\t\tfout << \"1\";\n"
                    << "\t\t\t}\n"
                    << "\t\t\telse {\n"
                    << "\t\t\t\tfout << \"2\";\n"
                    << "\t\t\t}\n"
                    << "\t\t}\n";
    }
    output_file << "\t\tfout << std::endl;\n"
                << "\t}\n"
                << "}\n";
    output_file.close();
}
