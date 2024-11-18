/* stuck-at fault ATPG for combinational circuit
 * Last update: 2006/12/09 */
#include <iostream>
#include "circuit.h"
#include "GetLongOpt.h"
#include <algorithm>
using namespace std;

extern GetLongOpt option;

void CIRCUIT::AddStuckAt0Fault(GATE* gptr) {
    FAULT* fptr = new FAULT(gptr, gptr, S0);
    this->Flist.push_back(fptr);
    if (gptr->No_Fanout() > 1) {
        GATE* fanout;
        for (unsigned int i = 0; i < gptr->No_Fanout(); ++i) {
            fanout = gptr->Fanout(i);
            fptr = new FAULT(gptr, fanout, S0);
            fptr->SetBranch(true);
            this->Flist.push_back(fptr);
        }
    }
    return;
}

void CIRCUIT::AddStuckAt1Fault(GATE* gptr) {
    FAULT* fptr = new FAULT(gptr, gptr, S1);
    this->Flist.push_back(fptr);
    if (gptr->No_Fanout() > 1) {
        GATE* fanout;
        for (unsigned int i = 0; i < gptr->No_Fanout(); ++i) {
            fanout = gptr->Fanout(i);
            fptr = new FAULT(gptr, fanout, S1);
            fptr->SetBranch(true);
            this->Flist.push_back(fptr);
        }
    }
    return;
}

//generate all stuck-at fault list
void CIRCUIT::GenerateAllFaultList() {
    cout << "Generate stuck-at fault list" << endl;
    register unsigned i, j;
    GATEFUNC fun;
    GATEPTR gptr, fanout;
    FAULT *fptr;
    for (i = 0; i < No_Gate(); ++i) {
        gptr = Netlist[i];
        fun = gptr->GetFunction();
        if (fun == G_PO) {
            continue;
        } //skip PO
        //add stem stuck-at 0 fault to Flist
        fptr = new FAULT(gptr, gptr, S0);
        Flist.push_front(fptr);
        //add stem stuck-at 1 fault to Flist
        fptr = new FAULT(gptr, gptr, S1);
        Flist.push_front(fptr);

        if (gptr->No_Fanout() == 1) {
            continue;
        } //no branch faults

        //add branch fault
        for (j = 0; j < gptr->No_Fanout(); ++j) {
            fanout = gptr->Fanout(j);
            fptr = new FAULT(gptr, fanout, S0);
            fptr->SetBranch(true);
            Flist.push_front(fptr);
            fptr = new FAULT(gptr, fanout, S1);
            fptr->SetBranch(true);
            Flist.push_front(fptr);
        } //end all fanouts
    } //end all gates
    //copy Flist to undetected Flist (for fault simulation)
    UFlist = Flist;
    return;
}

void CIRCUIT::GenerateCheckPointFaultList() {
    cout << "Generate stuck-at fault list with checkpoint theorem" << endl;
    register unsigned i, j;
    GATEFUNC fun;
    GATEPTR gptr, fanout;
    FAULT *fptr;
    for (i = 0; i < No_Gate(); ++i) {
        gptr = Netlist[i];
        fun = gptr->GetFunction();
        if (fun == G_PI) {
            fptr = new FAULT(gptr, gptr, S0);
            FlistCP.push_front(fptr);
            fptr = new FAULT(gptr, gptr, S1);
            FlistCP.push_front(fptr);
        }
        if (gptr->No_Fanout() == 1) {
            continue;
        }
        for (j = 0; j < gptr->No_Fanout(); ++j) {
            fanout = gptr->Fanout(j);
            fptr = new FAULT(gptr, fanout, S0);
            fptr->SetBranch(true);
            FlistCP.push_front(fptr);
            fptr = new FAULT(gptr, fanout, S1);
            fptr->SetBranch(true);
            FlistCP.push_front(fptr);
        }
    }
    UFlistCP = FlistCP;
    return;
}

void CIRCUIT::AssignCheckPointFaultList() {
    Flist = FlistCP;
    UFlist = UFlistCP;
    return;
}

void CIRCUIT::SelectFaultList() {
    //iscas85/c17.bench
    string temp;
    vector<GATE*>::iterator gptr;
    temp = "net17";
    gptr = find_if(
        this->Netlist.begin(),
        this->Netlist.end(),
        [&temp](GATE* g) {
            return (g->GetName() == temp);
        }
    );
    if (gptr != this->Netlist.end()) {
        AddStuckAt0Fault(*gptr);
    }
    temp = "n60";
    gptr = find_if(
        this->Netlist.begin(),
        this->Netlist.end(),
        [&temp](GATE* g) {
            return (g->GetName() == temp);
        }
    );
    if (gptr != this->Netlist.end()) {
        AddStuckAt1Fault(*gptr);
    }
    this->UFlist = this->Flist;
    return;
}

void CIRCUIT::GenerateBridgingFaultList() {
    cout << "Generate bridging fault list" << endl;
    register unsigned i;
    GATE* gptr;
    BFAULT* bfptr;
    for (i = 0; i < No_Gate(); i++) {
        this->Queue[this->Gate(i)->GetLevel()].push_back(this->Gate(i));
    }
    for (i = 0; i < this->MaxLevel; i++) {
        while (!Queue[i].empty()) {
            gptr = Queue[i].front();
            Queue[i].pop_front();
            if (!Queue[i].empty()) {
                if (
                    gptr->GetFunction() != G_PO &&
                    Queue[i].front()->GetFunction() != G_PO
                ) {
                    bfptr = new BFAULT(gptr, Queue[i].front(), S0);
                    this->BFlist.push_back(bfptr);
                    bfptr = new BFAULT(gptr, Queue[i].front(), S1);
                    this->BFlist.push_back(bfptr);
                }
            }
        }
    }
    UBFlist = BFlist;
    return;
}

void CIRCUIT::OutputBridgingFaultList(const string& output) {
    ofstream output_file(output);
    if (!output_file) {
        cout << "Can't open output file: " << output << endl;
        exit(-1);
    }
    for (list<BFAULT*>::iterator it = this->BFlist.begin(); it != this->BFlist.end(); ++it) {
        if ((*it)->GetValue() == S0) {
            output_file << "(" << (*it)->GetInputGate1()->GetName() << ", " << (*it)->GetInputGate2()->GetName() << ", AND)\n";
        }
        else {
            output_file << "(" << (*it)->GetInputGate1()->GetName() << ", " << (*it)->GetInputGate2()->GetName() << ", OR)\n";
        }
    }
    output_file.close();
    return;
}

void CIRCUIT::ParallelBFaultSimVectors() {
    cout << "Run bridging fault simulation" << endl;
    unsigned pattern_num(0);
    if (!Pattern.eof()) {
        while (!Pattern.eof()) {
            ++pattern_num;
            Pattern.ReadNextPattern();
            SchedulePI();
            LogicSim();
            BFaultSim();
        }
    }
    unsigned total_num(0);
    unsigned undetected_num(0), detected_num(0);
    unsigned eqv_undetected_num(0), eqv_detected_num(0);
    BFAULT* bfptr;
    list<BFAULT*>::iterator bfite;
    for (bfite = BFlist.begin(); bfite != BFlist.end(); ++bfite) {
        bfptr = *bfite;
        switch (bfptr->GetStatus()) {
            case DETECTED:
                ++eqv_detected_num;
                detected_num += bfptr->GetEqvFaultNum();
                break;
            default:
                ++eqv_undetected_num;
                undetected_num += bfptr->GetEqvFaultNum();
                break;
        }
    }
    total_num = detected_num + undetected_num;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---------------------------------------" << endl
         << "Test pattern number = " << pattern_num << endl
         << "---------------------------------------" << endl
         << "Total fault number = " << total_num << endl
         << "Detected fault number = " << detected_num << endl
         << "Undetected fault number = " << undetected_num << endl
         << "---------------------------------------" << endl
         << "Equivalent fault number = " << BFlist.size() << endl
         << "Equivalent detected fault number = " << eqv_detected_num << endl
         << "Equivalent undetected fault number = " << eqv_undetected_num << endl
         << "---------------------------------------" << endl
         << "Fault Coverge = " << 100 * detected_num / double(total_num) << "%" << endl
         << "Equivalent FC = " << 100 * eqv_detected_num / double(BFlist.size()) << "%" << endl
         << "---------------------------------------" << endl;
    return;
}

void CIRCUIT::BFaultSim() {
    register unsigned i, fault_idx(0);
    GATEPTR gptr = nullptr, gptr1, gptr2;
    BFAULT *bfptr;
    BFAULT *simulate_flist[PatternNum];
    list<GATEPTR>::iterator gite;
    for (i = 0; i < Netlist.size(); ++i) {
        Netlist[i]->SetFaultFreeValue();
    }
    list<BFAULT*>::iterator fite;
    for (fite = UBFlist.begin(); fite != UBFlist.end(); ++fite) {
        bfptr = *fite;
        if (bfptr->GetStatus() == REDUNDANT || bfptr->GetStatus() == DETECTED) {
            continue;
        }
        if (bfptr->GetInputGate1()->GetValue() == bfptr->GetInputGate2()->GetValue()) {
            continue;
        }
        gptr1 = bfptr->GetInputGate1();
        gptr2 = bfptr->GetInputGate2();
        if (bfptr->GetValue() == S0) {
            if (gptr1->GetValue() == S1) {
                gptr = gptr1;
            }
            else if (gptr2->GetValue() == S1) {
                gptr = gptr2;
            }
        }
        else if (bfptr->GetValue() == S1) {
            if (gptr1->GetValue() == S0) {
                gptr = gptr1;
            }
            else if (gptr2->GetValue() == S0) {
                gptr = gptr2;
            }
        }
        if (gptr != nullptr) {
            if (gptr->GetFlag(OUTPUT)) {
                bfptr->SetStatus(DETECTED);
                continue;
            }
            if (!gptr->GetFlag(FAULTY)) {
                gptr->SetFlag(FAULTY);
                GateStack.push_front(gptr);
            }
            InjectFaultValue(gptr, fault_idx, bfptr->GetValue());
            gptr->SetFlag(FAULT_INJECTED);
            ScheduleFanout(gptr);
            simulate_flist[fault_idx++] = bfptr;
        }
        if (fault_idx == PatternNum) {
            for (i = 0; i <= MaxLevel; ++i) {
                while (!Queue[i].empty()) {
                    gptr = Queue[i].front();
                    Queue[i].pop_front();
                    gptr->ResetFlag(SCHEDULED);
                    FaultSimEvaluate(gptr);
                }
            }
            for (gite = GateStack.begin(); gite != GateStack.end(); ++gite) {
                gptr = *gite;
                gptr->ResetFlag(FAULTY);
                gptr->ResetFlag(FAULT_INJECTED);
                gptr->ResetFaultFlag();
                if (gptr->GetFlag(OUTPUT)) {
                    for (i = 0; i < fault_idx; ++i) {
                        if (simulate_flist[i]->GetStatus() == DETECTED) {
                            continue;
                        }
                        if (
                            gptr->GetValue() != VALUE(gptr->GetValue1(i)) &&
                            gptr->GetValue() != X &&
                            gptr->GetValue1(i) == gptr->GetValue2(i)
                        ) {
                            simulate_flist[i]->SetStatus(DETECTED);
                        }
                    }
                }
                gptr->SetFaultFreeValue();    
            }
            GateStack.clear();
            fault_idx = 0;
        }
    }
    if (fault_idx) {
        for (i = 0; i <= MaxLevel; ++i) {
            while (!Queue[i].empty()) {
                gptr = Queue[i].front();
                Queue[i].pop_front();
                gptr->ResetFlag(SCHEDULED);
                FaultSimEvaluate(gptr);
            }
        }
        for (gite = GateStack.begin(); gite != GateStack.end(); ++gite) {
            gptr = *gite;
            gptr->ResetFlag(FAULTY);
            gptr->ResetFlag(FAULT_INJECTED);
            gptr->ResetFaultFlag();
            if (gptr->GetFlag(OUTPUT)) {
                for (i = 0; i < fault_idx; ++i) {
                    if (simulate_flist[i]->GetStatus() == DETECTED) {
                        continue;
                    }
                    if (
                        gptr->GetValue() != VALUE(gptr->GetValue1(i)) &&
                        gptr->GetValue() != X &&
                        gptr->GetValue1(i) == gptr->GetValue2(i)
                    ) {
                        simulate_flist[i]->SetStatus(DETECTED);
                    }
                }
            }
            gptr->SetFaultFreeValue();    
        }
        GateStack.clear();
        fault_idx = 0;
    }
    for (fite = UBFlist.begin(); fite != UBFlist.end();) {
        bfptr = *fite;
        if (bfptr->GetStatus() == DETECTED || bfptr->GetStatus() == REDUNDANT) {
            fite = UBFlist.erase(fite);
        }
        else {
            ++fite;
        }
    }
    return;
}

//stuck-at fault PODEM ATPG (fault dropping)
void CIRCUIT::Atpg(const bool& append, const bool& trace) {
    cout << "Run stuck-at fault ATPG" << endl;
    unsigned i, total_backtrack_num(0), pattern_num(0);
    ATPG_STATUS status;
    FAULT* fptr;
    list<FAULT*>::iterator fite;
    //prepare the output files
    ofstream OutputStrm;
    if (option.retrieve("output")) {
        if (append) {
            OutputStrm.open((char*)option.retrieve("output"), ios::app);
        }
        else {
            OutputStrm.open((char*)option.retrieve("output"), ios::out);
        }
        if (!OutputStrm) {
            cout << "Unable to open output file: " << option.retrieve("output") << endl
                 << "Unsaved output!\n";
            exit(-1);
        }
    }
    if (option.retrieve("output")) {
        if (!append) {
            for (i = 0; i < PIlist.size(); ++i) {
                if (i != 0) {
                    OutputStrm << " ";
                }
                OutputStrm << "PI " << PIlist[i]->GetName();
            }
            OutputStrm << endl;
        }
    }
    for (fite = Flist.begin(); fite != Flist.end(); ++fite) {
        fptr = *fite;
        if (fptr->GetStatus() == DETECTED) {
            continue;
        }
        //run podem algorithm
        status = Podem(fptr, total_backtrack_num, trace);
        switch (status) {
            case TRUE:
                fptr->SetStatus(DETECTED);
                ++pattern_num;
                //run fault simulation for fault dropping
                for (i = 0; i < PIlist.size(); ++i) {
                    ScheduleFanout(PIlist[i]); 
                    if (option.retrieve("output")) {
                        OutputStrm << PIlist[i]->GetValue();
                    }
		        }
                if (option.retrieve("output")) {
                    OutputStrm << endl;
                }
                for (i = PIlist.size(); i < Netlist.size(); ++i) {
                    Netlist[i]->SetValue(X);
                }
                LogicSim();
                if (trace) {
                    cout << "\tlogic simulation:\n";
                    for (unsigned int i = 0; i < No_Gate(); i++) {
                        cout << "\t\t" << Gate(i)->GetName() << " = " << VALUE_NAME[Gate(i)->GetValue()] << endl;
                    }
                }
                FaultSim(trace);
                break;
            case CONFLICT:
                fptr->SetStatus(REDUNDANT);
                break;
            case FALSE:
                fptr->SetStatus(ABORT);
                break;
        }
    } //end all faults
    OutputStrm.close();
    //compute fault coverage
    unsigned total_num(0);
    unsigned abort_num(0), redundant_num(0), detected_num(0);
    unsigned eqv_abort_num(0), eqv_redundant_num(0), eqv_detected_num(0);
    for (fite = Flist.begin(); fite != Flist.end(); ++fite) {
        fptr = *fite;
        switch (fptr->GetStatus()) {
            case DETECTED:
                ++eqv_detected_num;
                detected_num += fptr->GetEqvFaultNum();
                break;
            case REDUNDANT:
                ++eqv_redundant_num;
                redundant_num += fptr->GetEqvFaultNum();
                break;
            case ABORT:
                ++eqv_abort_num;
                abort_num += fptr->GetEqvFaultNum();
                break;
            default:
                cerr << "Unknown fault type exists" << endl;
                break;
        }
    }
    total_num = detected_num + abort_num + redundant_num;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---------------------------------------" << endl
         << "Test pattern number = " << pattern_num << endl
         << "Total backtrack number = " << total_backtrack_num << endl
         << "---------------------------------------" << endl
         << "Total fault number = " << total_num << endl
         << "Detected fault number = " << detected_num << endl
         << "Undetected fault number = " << abort_num + redundant_num << endl
         << "Abort fault number = " << abort_num << endl
         << "Redundant fault number = " << redundant_num << endl
         << "---------------------------------------" << endl
         << "Total equivalent fault number = " << Flist.size() << endl
         << "Equivalent detected fault number = " << eqv_detected_num << endl
         << "Equivalent undetected fault number = " << eqv_abort_num + eqv_redundant_num << endl
         << "Equivalent abort fault number = " << eqv_abort_num << endl
         << "Equivalent redundant fault number = " << eqv_redundant_num << endl
         << "---------------------------------------" << endl
         << "Fault Coverge = " << 100 * detected_num / double(total_num) << "%" << endl
         << "Equivalent FC = " << 100 * eqv_detected_num / double(Flist.size()) << "%" << endl
         << "Fault Efficiency = " << 100 * detected_num / double(total_num - redundant_num) << "%" << endl
         << "---------------------------------------" << endl;
    return;
}

void CIRCUIT::RandomPatternAtpg(const string& output) {
    cout << "Run stuck-at fault simulation with up to 1000 random patterns without unknown values or 90% fault coverage" << endl;
    ofstream output_file(output);
    if (!output_file) {
        cout << "Can't open pattern file: " << output << endl;
        exit(-1);
    }
    for (vector<GATE*>::iterator it = this->PIlist.begin(); it != this->PIlist.end(); it++) {
        if (it != this->PIlist.begin()) {
            output_file << " ";
        }
        output_file << "PI " << (*it)->GetName();
    }
    output_file << endl;
    output_file.close();
    srand(time(NULL));
    InitPattern(output.c_str());
    unsigned int pattern_num = 0;
    unsigned int total_num, undetected_num, detected_num;
    unsigned int eqv_undetected_num, eqv_detected_num;
    do {
        ++pattern_num;
        Pattern.FeedNextPattern();
        output_file.open(output, ios::app);
        if (!output_file) {
            cout << "Can't open pattern file: " << output << endl;
            exit(-1);
        }
        for (vector<GATE*>::iterator it = this->PIlist.begin(); it != this->PIlist.end(); it++) {
            output_file << (*it)->GetValue();
        }
        output_file << endl;
        output_file.close();
        SchedulePI();
        LogicSim();
        FaultSim();
        total_num = 0;
        undetected_num = 0;
        detected_num = 0;
        eqv_undetected_num = 0;
        eqv_detected_num = 0;
        FAULT* fptr;
        list<FAULT*>::iterator fite;
        for (fite = Flist.begin(); fite != Flist.end(); ++fite) {
            fptr = *fite;
            switch (fptr->GetStatus()) {
                case DETECTED:
                    ++eqv_detected_num;
                    detected_num += fptr->GetEqvFaultNum();
                    break;
                default:
                    ++eqv_undetected_num;
                    undetected_num += fptr->GetEqvFaultNum();
                    break;
            }
        }
        total_num = detected_num + undetected_num;
    } while (pattern_num < 1000 && static_cast<double>(detected_num) / total_num < 0.9);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---------------------------------------" << endl
         << "Test pattern number = " << pattern_num << endl
         << "---------------------------------------" << endl
         << "Total fault number = " << total_num << endl
         << "Detected fault number = " << detected_num << endl
         << "Undetected fault number = " << undetected_num << endl
         << "---------------------------------------" << endl
         << "Equivalent fault number = " << Flist.size() << endl
         << "Equivalent detected fault number = " << eqv_detected_num << endl 
         << "Equivalent undetected fault number = " << eqv_undetected_num << endl 
         << "---------------------------------------" << endl
         << "Fault Coverge = " << 100 * detected_num / double(total_num) << "%" << endl
         << "Equivalent FC = " << 100 * eqv_detected_num / double(Flist.size()) << "%" << endl
         << "---------------------------------------" << endl;
    Atpg(true);
    return;
}

void CIRCUIT::BFaultAtpg() {
    cout << "Run bridging fault ATPG" << endl;
    unsigned i, total_backtrack_num(0), pattern_num(0);
    ATPG_STATUS status;
    BFAULT* bfptr;
    list<BFAULT*>::iterator fite;
    ofstream OutputStrm;
    if (option.retrieve("output")) {
        OutputStrm.open((char*)option.retrieve("output"), ios::out);
        if (!OutputStrm) {
            cout << "Unable to open output file: " << option.retrieve("output") << endl
                 << "Unsaved output!\n";
            exit(-1);
        }
    }
    if (option.retrieve("output")) {
        for (i = 0; i < PIlist.size(); ++i) {
            if (i != 0) {
                OutputStrm << " ";
            }
            OutputStrm << "PI " << PIlist[i]->GetName();
        }
        OutputStrm << endl;
    }
    for (fite = BFlist.begin(); fite != BFlist.end(); ++fite) {
        bfptr = *fite;
        if (bfptr->GetStatus() == DETECTED) {
            continue;
        }
        FAULT* fptr = new FAULT((*fite)->GetInputGate1(), (*fite)->GetInputGate1(), (*fite)->GetValue());
        status = BFaultPodem(fptr, total_backtrack_num, (*fite)->GetInputGate2());
        delete fptr;
        if (status == TRUE) {
            bfptr->SetStatus(DETECTED);
            ++pattern_num;
            for (i = 0; i < PIlist.size(); ++i) {
                ScheduleFanout(PIlist[i]); 
                if (option.retrieve("output")) {
                    OutputStrm << PIlist[i]->GetValue();
                }
            }
            if (option.retrieve("output")) {
                OutputStrm << endl;
            }
            for (i = PIlist.size(); i < Netlist.size(); ++i) {
                Netlist[i]->SetValue(X);
            }
            LogicSim();
            BFaultSim();
        }
        else {
            FAULT* fptr = new FAULT((*fite)->GetInputGate2(), (*fite)->GetInputGate2(), (*fite)->GetValue());
            status = BFaultPodem(fptr, total_backtrack_num, (*fite)->GetInputGate1());
            delete fptr;
            switch (status) {
                case TRUE:
                    bfptr->SetStatus(DETECTED);
                    ++pattern_num;
                    for (i = 0; i < PIlist.size(); ++i) {
                        ScheduleFanout(PIlist[i]); 
                        if (option.retrieve("output")) {
                            OutputStrm << PIlist[i]->GetValue();
                        }
                    }
                    if (option.retrieve("output")) {
                        OutputStrm << endl;
                    }
                    for (i = PIlist.size(); i < Netlist.size(); ++i) {
                        Netlist[i]->SetValue(X);
                    }
                    LogicSim();
                    BFaultSim();
                    break;
                case CONFLICT:
                    bfptr->SetStatus(REDUNDANT);
                    break;
                case FALSE:
                    bfptr->SetStatus(ABORT);
                    break;
            }

        }
    }
    OutputStrm.close();
    unsigned total_num(0);
    unsigned abort_num(0), redundant_num(0), detected_num(0);
    unsigned eqv_abort_num(0), eqv_redundant_num(0), eqv_detected_num(0);
    for (fite = BFlist.begin(); fite != BFlist.end(); ++fite) {
        bfptr = *fite;
        switch (bfptr->GetStatus()) {
            case DETECTED:
                ++eqv_detected_num;
                detected_num += bfptr->GetEqvFaultNum();
                break;
            case REDUNDANT:
                ++eqv_redundant_num;
                redundant_num += bfptr->GetEqvFaultNum();
                break;
            case ABORT:
                ++eqv_abort_num;
                abort_num += bfptr->GetEqvFaultNum();
                break;
            default:
                cerr << "Unknown fault type exists" << endl;
                break;
        }
    }
    total_num = detected_num + abort_num + redundant_num;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---------------------------------------" << endl
         << "Test pattern number = " << pattern_num << endl
         << "Total backtrack number = " << total_backtrack_num << endl
         << "---------------------------------------" << endl
         << "Total fault number = " << total_num << endl
         << "Detected fault number = " << detected_num << endl
         << "Undetected fault number = " << abort_num + redundant_num << endl
         << "Abort fault number = " << abort_num << endl
         << "Redundant fault number = " << redundant_num << endl
         << "---------------------------------------" << endl
         << "Total equivalent fault number = " << BFlist.size() << endl
         << "Equivalent detected fault number = " << eqv_detected_num << endl
         << "Equivalent undetected fault number = " << eqv_abort_num + eqv_redundant_num << endl
         << "Equivalent abort fault number = " << eqv_abort_num << endl
         << "Equivalent redundant fault number = " << eqv_redundant_num << endl
         << "---------------------------------------" << endl
         << "Fault Coverge = " << 100 * detected_num / double(total_num) << "%" << endl
         << "Equivalent FC = " << 100 * eqv_detected_num / double(BFlist.size()) << "%" << endl
         << "Fault Efficiency = " << 100 * detected_num / double(total_num - redundant_num) << "%" << endl
         << "---------------------------------------" << endl;
    return;
}

//run PODEM for target fault
//TRUE: test pattern found
//CONFLICT: no test pattern
//FALSE: abort
ATPG_STATUS CIRCUIT::Podem(FAULT* fptr, unsigned &total_backtrack_num, const bool& trace) {
    unsigned i, backtrack_num(0);
    GATEPTR pi_gptr(0), decision_gptr(0);
    ATPG_STATUS status;

    //set all values as unknown
    for (i = 0; i < Netlist.size(); ++i) {
        Netlist[i]->SetValue(X);
    }
    if (trace) {
        cout << fptr->GetInputGate()->GetName() << " to " << fptr->GetOutputGate()->GetName() << " (stuck-at-" << fptr->GetValue() << ")\n"
             << "\tset all values as unknown\n";
    }
    //mark propagate paths
    MarkPropagateTree(fptr->GetOutputGate());
    if (trace) {
        cout << "\tpropagate paths: ";
        for (list<GATE*>::iterator gite = this->PropagateTree.begin(); gite != this->PropagateTree.end(); ++gite) {
            if (gite != this->PropagateTree.begin()) {
                cout << " -> ";
            }
            cout << (*gite)->GetName();
        }
        cout << endl;
    }
    //propagate fault free value
    status = SetUniqueImpliedValue(fptr, trace);
    switch (status) {
        case TRUE:
            LogicSim();
            if (trace) {
                cout << "\tlogic simulation:\n";
                for (unsigned int i = 0; i < No_Gate(); i++) {
                    cout << "\t\t" << Gate(i)->GetName() << " = " << VALUE_NAME[Gate(i)->GetValue()] << endl;
                }
            }
            //inject faulty value
            if (FaultEvaluate(fptr)) {
                if (trace) {
                    cout << "\tfault is injected successfully and need to do fault propagation\n";
                }
                //forward implication
                ScheduleFanout(fptr->GetOutputGate());
                LogicSim();
                if (trace) {
                    cout << "\tlogic simulation:\n";
                    for (unsigned int i = 0; i < No_Gate(); i++) {
                        cout << "\t\t" << Gate(i)->GetName() << " = " << VALUE_NAME[Gate(i)->GetValue()] << endl;
                    }
                }
            }
            //check if the fault has propagated to PO
            if (!CheckTest()) {
                status = FALSE;
            }
            break;
        case CONFLICT:
            status = CONFLICT;
            break;
        case FALSE:
            break;
    }

    while (backtrack_num < BackTrackLimit && status == FALSE) {
        //search possible PI decision
        pi_gptr = TestPossible(fptr, trace);
        if (pi_gptr) { //decision found
            ScheduleFanout(pi_gptr);
            //push to decision tree
            GateStack.push_back(pi_gptr);
            decision_gptr = pi_gptr;
            if (trace) {
                cout << "\tdecision tree add " << decision_gptr->GetName() << " = " << decision_gptr->GetValue() << endl;
            }
        }
        else { //backtrack previous decision
            while (!GateStack.empty() && !pi_gptr) {
                //all decision tried (1 and 0)
                if (decision_gptr->GetFlag(ALL_ASSIGNED)) {
                    if (trace) {
                        cout << "\tall decision tried for " << decision_gptr->GetName() << endl;
                    }
                    decision_gptr->ResetFlag(ALL_ASSIGNED);
                    decision_gptr->SetValue(X);
                    ScheduleFanout(decision_gptr);
                    //remove decision from decision tree
                    GateStack.pop_back();
                    decision_gptr = GateStack.back();
                }
                //inverse current decision value
                else {
                    decision_gptr->InverseValue();
                    if (trace) {
                        cout << "\tinverse current decision value " << decision_gptr->GetName() << " = " << decision_gptr->GetValue() << endl;
                    }
                    ScheduleFanout(decision_gptr);
                    decision_gptr->SetFlag(ALL_ASSIGNED);
                    ++backtrack_num;
                    pi_gptr = decision_gptr;
                }
            }
            //no other decision
            if (!pi_gptr) {
                status = CONFLICT;
            }
        }
        if (pi_gptr) {
            LogicSim();
            if (trace) {
                cout << "\tlogic simulation:\n";
                for (unsigned int i = 0; i < No_Gate(); i++) {
                    cout << "\t\t" << Gate(i)->GetName() << " = " << VALUE_NAME[Gate(i)->GetValue()] << endl;
                }
            }
            //fault injection
            if(FaultEvaluate(fptr)) {
                if (trace) {
                    cout << "\tfault is injected successfully and need to do fault propagation\n";
                }
                //forward implication
                ScheduleFanout(fptr->GetOutputGate());
                LogicSim();
                if (trace) {
                    cout << "\tlogic simulation:\n";
                    for (unsigned int i = 0; i < No_Gate(); i++) {
                        cout << "\t\t" << Gate(i)->GetName() << " = " << VALUE_NAME[Gate(i)->GetValue()] << endl;
                    }
                }
            }
            if (CheckTest()) {
                status = TRUE;
            }
        }
    } //end while loop

    //clean ALL_ASSIGNED and MARKED flags
    list<GATEPTR>::iterator gite;
    for (gite = GateStack.begin(); gite != GateStack.end(); ++gite) {
        (*gite)->ResetFlag(ALL_ASSIGNED);
    }
    for (gite = PropagateTree.begin(); gite != PropagateTree.end(); ++gite) {
        (*gite)->ResetFlag(MARKED);
    }

    //clear stacks
    GateStack.clear();
    PropagateTree.clear();
    
    //assign true values to PIs
    if (trace) {
        cout << "\tassign true values to PIs\n";
    }
    if (status ==  TRUE) {
		for (i = 0; i < PIlist.size(); ++i) {
		    switch (PIlist[i]->GetValue()) {
                case S1:
                    break;
                case S0:
                    break;
                case D:
                    PIlist[i]->SetValue(S1);
                    break;
                case B:
                    PIlist[i]->SetValue(S0);
                    break;
                case X:
                    PIlist[i]->SetValue(VALUE(2.0 * rand() / (RAND_MAX + 1.0)));
                    break;
                default:
                    cerr << "Illigal value" << endl;
                    break;
		    }
		} //end for all PI
    } //end status == TRUE

    total_backtrack_num += backtrack_num;
    if (trace) {
        cout << "\tPODEM returns that " << ATPG_STATUS_NAME[status] << endl;
    }
    return status;
}

ATPG_STATUS CIRCUIT::BFaultPodem(FAULT* fptr, unsigned &total_backtrack_num, GATE* gptr) {
    unsigned i, backtrack_num(0);
    GATEPTR pi_gptr(0), decision_gptr(0);
    ATPG_STATUS status;
    for (i = 0; i < Netlist.size(); ++i) {
        Netlist[i]->SetValue(X);
    }
    MarkPropagateTree(fptr->GetOutputGate());
    status = SetUniqueImpliedValue(fptr);
    switch (status) {
        case TRUE:
            LogicSim();
            if (FaultEvaluate(fptr)) {
                ScheduleFanout(fptr->GetOutputGate());
                LogicSim();
            }
            if (!CheckTest()) {
                status = FALSE;
            }
            break;
        case CONFLICT:
            status = CONFLICT;
            break;
        case FALSE: break;
    }
    while (backtrack_num < BackTrackLimit && status == FALSE) {
        pi_gptr = TestPossible(fptr);
        if (pi_gptr) {
            ScheduleFanout(pi_gptr);
            GateStack.push_back(pi_gptr);
            decision_gptr = pi_gptr;
        }
        else {
            while (!GateStack.empty() && !pi_gptr) {
                if (decision_gptr->GetFlag(ALL_ASSIGNED)) {
                    decision_gptr->ResetFlag(ALL_ASSIGNED);
                    decision_gptr->SetValue(X);
                    ScheduleFanout(decision_gptr);
                    GateStack.pop_back();
                    decision_gptr = GateStack.back();
                }
                else {
                    decision_gptr->InverseValue();
                    ScheduleFanout(decision_gptr);
                    decision_gptr->SetFlag(ALL_ASSIGNED);
                    ++backtrack_num;
                    pi_gptr = decision_gptr;
                }
            }
            if (!pi_gptr) {
                status = CONFLICT;
            }
        }
        if (pi_gptr) {
            LogicSim();
            if (FaultEvaluate(fptr)) {
                ScheduleFanout(fptr->GetOutputGate());
                LogicSim();
            }
            if (CheckTest()) {
                status = TRUE;
            }
        }
    }
    list<GATEPTR>::iterator gite;
    for (gite = GateStack.begin(); gite != GateStack.end(); ++gite) {
        (*gite)->ResetFlag(ALL_ASSIGNED);
    }
    for (gite = PropagateTree.begin(); gite != PropagateTree.end(); ++gite) {
        (*gite)->ResetFlag(MARKED);
    }
    GateStack.clear();
    PropagateTree.clear();
    if (status ==  TRUE) {
        if (gptr->GetValue() == X || gptr->GetValue() == fptr->GetValue()) {
            gptr->SetValue(fptr->GetValue());
        }
        else {
            return CONFLICT;
        }
		for (i = 0; i < PIlist.size(); ++i) {
		    switch (PIlist[i]->GetValue()) {
			case S1:
                break;
			case S0:
                break;
			case D:
                PIlist[i]->SetValue(S1);
                break;
			case B:
                PIlist[i]->SetValue(S0);
                break;
			case X:
                PIlist[i]->SetValue(VALUE(2.0 * rand() / (RAND_MAX + 1.0)));
                break;
			default:
                cerr << "Illigal value" << endl;
                break;
		    }
		}
    }
    total_backtrack_num += backtrack_num;
    return status;
}

//inject fault-free value and do simple backward implication
//TRUE: fault can be backward propagated to PI
//CONFLICT: conflict assignment
//FALSE: fault can not be propagated to PI
ATPG_STATUS CIRCUIT::SetUniqueImpliedValue(FAULT* fptr, const bool& trace) {
    register ATPG_STATUS status(FALSE);
    GATEPTR igptr(fptr->GetInputGate());
    //backward implication fault-free value
    switch (BackwardImply(igptr, NotTable[fptr->GetValue()], trace)) {
        case TRUE:
            status = TRUE;
            break;
        case CONFLICT:
            return CONFLICT;
            break;
        case FALSE:
            break;
    }
    if (!fptr->Is_Branch()) {
        if (trace) {
            cout << "\tnot branch, " << ATPG_STATUS_NAME[status] << endl;
        }
        return status;
    }
    //if branch, need to check side inputs of the output gate
    GATEPTR ogptr(fptr->GetOutputGate());
    VALUE ncv(NCV[ogptr->GetFunction()]);
    //set side inputs as non-controlling value
    for (unsigned int i = 0; i < ogptr->No_Fanin(); ++i) {
        if (igptr == ogptr->Fanin(i)) {
            continue;
        }
        switch (BackwardImply(ogptr->Fanin(i), ncv, trace)) {
            case TRUE:
                status = TRUE;
                break;
            case CONFLICT:
                return CONFLICT;
                break;
            case FALSE:
                break;
        }
    }
    if (trace) {
        cout << "\tis branch, " << ATPG_STATUS_NAME[status] << endl;
    }
    return status;
}

//apply the input values of gate according to its output value
//TRUE: fault can be backward propagated to PI
//CONFLICT: conflict assignment
//FALSE: fault can not be propagated to PI
ATPG_STATUS CIRCUIT::BackwardImply(GATEPTR gptr, VALUE value, const bool& trace) {
    register unsigned i;
    register ATPG_STATUS status(FALSE);
    GATEFUNC fun(gptr->GetFunction());
    if (trace) {
        cout << "\tbackward implication: " << gptr->GetName() << " = " << VALUE_NAME[value] << endl;
    }
    if (fun == G_PI) { //reach PI
        //conflict assignment
        if (gptr->GetValue() != X && gptr->GetValue() != value) {
            return CONFLICT;
        }
        gptr->SetValue(value);
        ScheduleFanout(gptr);
        return TRUE;
    }
    //not PI gate
    switch (fun) {
        case G_NOT:
            switch (BackwardImply(gptr->Fanin(0), NotTable[value], trace)) {
                case TRUE:
                    status = TRUE;
                    break;
                case FALSE:
                    break;
                case CONFLICT:
                    return CONFLICT;
                    break;
            }
            break;
        case G_BUF:
            switch (BackwardImply(gptr->Fanin(0), value, trace)) {
                case TRUE:
                    status = TRUE;
                    break;
                case FALSE:
                    break;
                case CONFLICT:
                    return CONFLICT;
                    break;
            }
            break;
        case G_AND:
        case G_OR:
            if (value != NCV[fun]) {
                break;
            }
            for (i = 0; i < gptr->No_Fanin(); ++i) {
                switch (BackwardImply(gptr->Fanin(i), NCV[fun], trace)) {
                    case TRUE:
                        status = TRUE;
                        break;
                    case FALSE:
                        break;
                    case CONFLICT:
                        return CONFLICT;
                        break;
                }
            }
            break;
        case G_NAND:
        case G_NOR:
            if (value != CV[fun]) {
                break;
            }
            for (i = 0; i < gptr->No_Fanin(); ++i) {
                switch (BackwardImply(gptr->Fanin(i), NCV[fun], trace)) {
                    case TRUE:
                        status = TRUE;
                        break;
                    case FALSE:
                        break;
                    case CONFLICT:
                        return CONFLICT;
                        break;
                }
            }
            break;
        default:
            break;
    }
    if (trace) {
        cout << "\tbackward implication returns that " << ATPG_STATUS_NAME[status] << endl;
    }
    return status;
}

//mark and push propagate tree to stack PropagateTree
void CIRCUIT::MarkPropagateTree(GATEPTR gptr) {
    PropagateTree.push_back(gptr);
    gptr->SetFlag(MARKED);
    for (unsigned int i = 0; i < gptr->No_Fanout(); ++i) {
        if (gptr->Fanout(i)->GetFlag(MARKED)) {
            continue;
        }
        MarkPropagateTree(gptr->Fanout(i));
    }
    return;
}

//fault injection
//true: fault is injected successfully and need to do fault propagation
//false: output value is the same with original one or fault is injected in PO
bool CIRCUIT::FaultEvaluate(FAULT* fptr) {
    GATEPTR igptr(fptr->GetInputGate());
    //store input value
    VALUE ivalue(igptr->GetValue());
    //can not do fault injection
    if (ivalue == X || ivalue == fptr->GetValue()) {
        return false;
    }
    else if (ivalue == S1) {
        igptr->SetValue(D);
    }
    else if (ivalue == S0) {
        igptr->SetValue(B);
    }
    else {
        return false;
    } //fault has been injected

    if (!fptr->Is_Branch()) {
        return true;
    }
    //for branch fault, the fault has to be propagated to output gate
    GATEPTR ogptr(fptr->GetOutputGate());
    if (ogptr->GetFunction() == G_PO) {
        return false;
    }
    VALUE value(Evaluate(ogptr));
    //backup original value to input gate
    igptr->SetValue(ivalue);
    //fault has propagated to output gate
    if (value != ogptr->GetValue()) {
        ogptr->SetValue(value);
        return true;
    }
    return false;
}

//return possible PI decision
GATEPTR CIRCUIT::TestPossible(FAULT* fptr, const bool& trace) {
    GATEPTR decision_gptr;
    GATEPTR ogptr(fptr->GetOutputGate());
    VALUE decision_value;
    if (!ogptr->GetFlag(OUTPUT)) {
        if (ogptr->GetValue() != X) {
            //if no fault injected, return 0
            if (ogptr->GetValue() != B && ogptr->GetValue() != D) {
                return 0;
            }
            //search D-frontier
            decision_gptr = FindPropagateGate();
            if (!decision_gptr) {
                return 0;
            }
            switch (decision_gptr->GetFunction()) {
                case G_AND:
                case G_NOR:
                    decision_value = S1;
                    break;
                case G_NAND:
                case G_OR:
                    decision_value = S0;
                    break;
                default:
                    return 0;
            }
        }
        else { //output gate == X
            //test if any unknown path can propagate the fault
            if (!TraceUnknownPath(ogptr)) {
                return 0;
            }
            if (!fptr->Is_Branch()) { //stem
                decision_value = NotTable[fptr->GetValue()];
                decision_gptr = ogptr;
            }
            else { //branch
                //output gate value is masked by side inputs
                if (fptr->GetInputGate()->GetValue() != X) {
                    switch (ogptr->GetFunction()) {
                        case G_AND:
                        case G_NOR:
                            decision_value = S1;
                            break;
                        case G_NAND:
                        case G_OR:
                            decision_value = S0;
                            break;
                        default:
                            return 0;
                    }
                    decision_gptr = fptr->GetOutputGate();
                }
                //both input and output values are X
                else {
                    decision_value = NotTable[fptr->GetValue()];
                    decision_gptr = fptr->GetInputGate();
                }
            } //end branch
        } //end output gate == X
    } //end if output gate is PO
    else { //reach PO
        if (fptr->GetInputGate()->GetValue() == X) {
            decision_value = NotTable[fptr->GetValue()];
            decision_gptr = fptr->GetInputGate();
        }
        else {
            return 0;
        }
    }
    return FindPIAssignment(decision_gptr, decision_value, trace);
}

//find PI decision to set gptr = value
//success: return PI
//fail: return 0
GATEPTR CIRCUIT::FindPIAssignment(GATEPTR gptr, VALUE value, const bool& trace) {
    if (trace) {
        cout << "\tfind PI decision to set " << gptr->GetName() << " = " << VALUE_NAME[value] << endl;
    }
    //search PI desicion
    if (gptr->GetFunction() == G_PI) {
        gptr->SetValue(value);
        return gptr;
    }
    GATEPTR j_gptr(0); //J-frontier
    VALUE j_value(X), cv_out;
    switch (gptr->GetFunction()) {
        case G_AND:
        case G_NAND:
        case G_OR:
        case G_NOR:
            cv_out = CV[gptr->GetFunction()];
            cv_out = gptr->Is_Inversion() ? NotTable[cv_out] : cv_out;
            //select one fanin as cv
            if (value == cv_out) {
                j_gptr = FindEasiestControl(gptr);
                j_value = CV[gptr->GetFunction()];
            }
            //select one fanin as ncv 
            else {
                j_gptr = FindHardestControl(gptr);
                j_value = NCV[gptr->GetFunction()];
            }
            break;
        case G_BUF:
        case G_NOT:
            j_value = gptr->Is_Inversion() ? NotTable[value] : value;
            j_gptr = gptr->Fanin(0);
            break;
        default:
            break;
    }
    if (trace) {
        cout << "\tPI decision returns " << j_gptr->GetName() << " = " << VALUE_NAME[j_value] << endl;
    }
    if (j_gptr) {
        return FindPIAssignment(j_gptr, j_value);
    }
    return 0;
}

//check if the fault has propagated to PO
bool CIRCUIT::CheckTest() {
    VALUE value;
    for (unsigned int i = 0; i < POlist.size(); ++i) {
        value = POlist[i]->GetValue();
        if (value == B || value == D) {
            return true;
        }
    }
    return false;
}

//search gate from propagate tree to propagate the fault
GATEPTR CIRCUIT::FindPropagateGate() {
    register unsigned i;
    list<GATEPTR>::iterator gite;
    GATEPTR gptr, fanin;
    for (gite = PropagateTree.begin(); gite != PropagateTree.end(); ++gite) {
        gptr = *gite;
        if (gptr->GetValue() != X) {
            continue;
        }
        for (i = 0; i < gptr->No_Fanin(); ++i) {
            fanin = gptr->Fanin(i);
            if (fanin->GetValue() != D && fanin->GetValue() != B) {
                continue;
            }
            if (TraceUnknownPath(gptr)) {
                return gptr;
            }
            break;
        }
    }
    return 0;
}

//trace if any unknown path from gptr to PO
bool CIRCUIT::TraceUnknownPath(GATEPTR gptr) {
    if (gptr->GetFlag(OUTPUT)) {
        return true;
    }
    GATEPTR fanout;
    for (unsigned int i = 0; i < gptr->No_Fanout(); ++i) {
        fanout = gptr->Fanout(i);
        if (fanout->GetValue()!=X) {
            continue;
        }
        if (TraceUnknownPath(fanout)) {
            return true;
        }
    }
    return false;
}

//serach lowest level unknown fanin
GATEPTR CIRCUIT::FindEasiestControl(GATEPTR gptr) {
    GATEPTR fanin;
    for (unsigned int i = 0; i < gptr->No_Fanin(); ++i) {
        fanin = gptr->Fanin(i);
        if (fanin->GetValue() == X) {
            return fanin;
        }
    }
    return 0;
}

//serach highest level unknown fanin
GATEPTR CIRCUIT::FindHardestControl(GATEPTR gptr) {
    GATEPTR fanin;
    for (unsigned int i = gptr->No_Fanin(); i > 0; --i) {
        fanin = gptr->Fanin(i-1);
        if (fanin->GetValue() == X) {
            return fanin;
        }
    }
    return 0;
}

//functor, used to compare the levels of two gates
struct sort_by_level {
    bool operator()(const GATEPTR gptr1, const GATEPTR gptr2) const {
        return (gptr1->GetLevel() < gptr2->GetLevel());
    }
};

//sort fanin by level (from low to high)
void CIRCUIT::SortFaninByLevel() {
    for (unsigned int i = 0; i < Netlist.size(); ++i) {
        vector<GATE*>& Input_list = Netlist[i]->GetInput_list();
        sort(Input_list.begin(), Input_list.end(), sort_by_level());
    }
    return;
}

//mark and trace all stem fault propagated by fault "val"
void CIRCUIT::TraceDetectedStemFault(GATEPTR gptr, VALUE val) {
    //no PO stem fault
    if (gptr->GetFunction() == G_PO) {
        return;
    }
    //get output fault type
    if (gptr->Is_Inversion()) {
        val = NotTable[val];
    }
    //translate value to flag: S0->ALL_ASSIGNED, S1->MARKED
    FLAGS flag = FLAGS(val);
    if (val != S1 && val != S0) {
        cerr << "error" << endl;
    }
    //stem fault has been detected
    if (gptr->GetFlag(flag)) {
        return;
    }
    gptr->SetFlag(flag);
    //stop when the gate meets branch
    if (gptr->No_Fanout() > 1) {
        return;
    }
    TraceDetectedStemFault(gptr->Fanout(0), val);
    return;
}

void CIRCUIT::CompareNo_Fault() {
    cout << "number of faults: " << this->Flist.size() << endl
         << "number of checkpoint faults: " << this->FlistCP.size() << endl
         << static_cast<double>(this->Flist.size() - this->FlistCP.size()) / this->Flist.size() * 100 << "% of faults have been collapsed\n";
    return;
}
