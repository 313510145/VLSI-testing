#include <iostream> 
#include <stack>
//#include <alg.h>
#include "circuit.h"
#include "GetLongOpt.h"
using namespace std;

extern GetLongOpt option;

bool CIRCUIT::FindPath(vector<GATE*>& ps, unsigned int& pn, const GATE* const eg) {
    GATE* current_gate = ps.back();
    if (current_gate == eg) {
        for (vector<GATE*>::iterator it = ps.begin(); it != ps.end(); it++) {
            if (it != ps.begin()) {
                cout << " ";
            }
            cout << (*it)->GetName();
        }
        cout << endl;
        ps.pop_back();
        pn++;
        return true;
    }
    bool path_found = false;
    GATE* next_gate;
    for (unsigned int i = 0; i < current_gate->No_Fanout(); i++) {
        next_gate = current_gate->Fanout(i);
        if (!next_gate->GetFlag(NOT_IN_PATH)) {
            ps.push_back(next_gate);
            bool temp = FindPath(ps, pn, eg);
            if (!path_found) {
                path_found = temp;
            }
        }
    }
    if (!path_found) {
        current_gate->SetFlag(NOT_IN_PATH);
    }
    ps.pop_back();
    return path_found;
}

double CIRCUIT::AverageNo_Fanout() {
    unsigned int fanout_num = 0;
    for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
        fanout_num += (*it)->No_Fanout();
    }
    return static_cast<double>(fanout_num) / this->Netlist.size();
}

void CIRCUIT::PrintNo_GateEachType() {
    unsigned int gate_num[G_BAD] = {0};
    for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
        gate_num[(*it)->GetFunction()]++;
    }
    cout << "total number of gates including inverter, or, nor, and, nand: " << gate_num[G_NOT] + gate_num[G_OR] + gate_num[G_NOR] + gate_num[G_AND] + gate_num[G_NAND] << endl
         << "number of gates for each type:" << endl;
    for (unsigned int i = 0; i < G_BAD; i++) {
        cout << "\t" << GATENAME[i] << ": " << gate_num[i] << endl;
    }
}

void CIRCUIT::PrintNo_Net() {
    unsigned int signal_net_num = 0, branch_net_num = 0, stem_net_num = 0;
    for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
        unsigned int temp = (*it)->No_Fanout();
        if (temp > 1) {
            signal_net_num += temp + 1;
            branch_net_num += temp;
            stem_net_num++;
        }
        else {
            signal_net_num += temp;
        }
    }
    cout << "total number of signal nets: " << signal_net_num << endl
         << "\tnumber of branch nets: " << branch_net_num << endl
         << "\tnumber of stem nets: " << stem_net_num << endl;
}

void CIRCUIT::PrintAllPath(const string& start, const string& end) {
    GATE *start_gate = nullptr, *end_gate = nullptr;
    for (unsigned int i = 0; i < this->PIlist.size(); i++) {
        if (this->PIGate(i)->GetName() == start) {
            start_gate = this->PIGate(i);
            break;
        }
    }
    for (unsigned int i = 0; i < this->POlist.size(); i++) {
        if (this->POGate(i)->GetName() == end) {
            end_gate = this->POGate(i);
            break;
        }
    }
    if (start_gate != nullptr) {
        vector<GATE*> path_stack;
        path_stack.push_back(start_gate);
        unsigned int path_num = 0;
        FindPath(path_stack, path_num, end_gate);
        cout << "The paths from " << start << " to " << end << ": " << path_num << endl;
        for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
            if ((*it)->GetFlag(NOT_IN_PATH)) {
                (*it)->ResetFlag(NOT_IN_PATH);
            }
        }
    }
}

void CIRCUIT::GenerateRandomPattern(const string& num, const string& output, const bool& unknown) {
    if (unknown) {
        cout << "Generate random patterns with unknown values\n";
    }
    else {
        cout << "Generate random patterns without unknown values\n";
    }
    ofstream output_file(output);
    if (!output_file) {
        cout << "Can't open pattern file: " << output << endl;
        exit(-1);
    }
    srand(time(NULL));
    for (vector<GATE*>::iterator it = this->PIlist.begin(); it != this->PIlist.end(); it++) {
        if (it != this->PIlist.begin()) {
            output_file << " ";
        }
        output_file << "PI " << (*it)->GetName();
    }
    output_file << endl;
    int n = stoi(num);
    if (unknown) {
        for (int i = 0; i < n; i++) {
            for (unsigned int j = 0; j < this->PIlist.size(); j++) {
                int r = 3.0 * rand() / (RAND_MAX + 1.0);
                if (r > 1) {
                    output_file << "X";
                }
                else {
                    output_file << r;
                }
            }
            output_file << endl;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (unsigned int j = 0; j < this->PIlist.size(); j++) {
                int r = 2.0 * rand() / (RAND_MAX + 1.0);
                output_file << r;
            }
            output_file << endl;
        }
    }
    output_file.close();
}

void CIRCUIT::FanoutList()
{
    unsigned i = 0, j;
    GATE* gptr;
    for (;i < No_Gate();i++) {
        gptr = Gate(i);
        for (j = 0;j < gptr->No_Fanin();j++) {
            gptr->Fanin(j)->AddOutput_list(gptr);
        }
    }
}

void CIRCUIT::Levelize()
{
    list<GATE*> Queue;
    GATE* gptr;
    GATE* out;
    unsigned j = 0;
    for (unsigned i = 0;i < No_PI();i++) {
        gptr = PIGate(i);
        gptr->SetLevel(0);
        for (j = 0;j < gptr->No_Fanout();j++) {
            out = gptr->Fanout(j);
            if (out->GetFunction() != G_PPI) {
                out->IncCount();
                if (out->GetCount() == out->No_Fanin()) {
                    out->SetLevel(1);
                    Queue.push_back(out);
                }
            }
        }
    }
    for (unsigned i = 0;i < No_PPI();i++) {
        gptr = PPIGate(i);
        gptr->SetLevel(0);
        for (j = 0;j < gptr->No_Fanout();j++) {
            out = gptr->Fanout(j);
            if (out->GetFunction() != G_PPI) {
                out->IncCount();
                if (out->GetCount() ==
                        out->No_Fanin()) {
                    out->SetLevel(1);
                    Queue.push_back(out);
                }
            }
        }
    }
    int l1, l2;
    while (!Queue.empty()) {
        gptr = Queue.front();
        Queue.pop_front();
        l2 = gptr->GetLevel();
        for (j = 0;j < gptr->No_Fanout();j++) {
            out = gptr->Fanout(j);
            if (out->GetFunction() != G_PPI) {
                l1 = out->GetLevel();
                if (l1 <= l2)
                    out->SetLevel(l2 + 1);
                out->IncCount();
                if (out->GetCount() ==
                        out->No_Fanin()) {
                    Queue.push_back(out);
                }
            }
        }
    }
    for (unsigned i = 0;i < No_Gate();i++) {
        Gate(i)->ResetCount();
    }
}

void CIRCUIT::Check_Levelization()
{

    GATE* gptr;
    GATE* in;
    unsigned i, j;
    for (i = 0;i < No_Gate();i++) {
        gptr = Gate(i);
        if (gptr->GetFunction() == G_PI) {
            if (gptr->GetLevel() != 0) {
                cout << "Wrong Level for PI : " <<
                gptr->GetName() << endl;
                exit( -1);
            }
        }
        else if (gptr->GetFunction() == G_PPI) {
            if (gptr->GetLevel() != 0) {
                cout << "Wrong Level for PPI : " <<
                gptr->GetName() << endl;
                exit( -1);
            }
        }
        else {
            for (j = 0;j < gptr->No_Fanin();j++) {
                in = gptr->Fanin(j);
                if (in->GetLevel() >= gptr->GetLevel()) {
                    cout << "Wrong Level for: " <<
                    gptr->GetName() << '\t' <<
                    gptr->GetID() << '\t' <<
                    gptr->GetLevel() <<
                    " with fanin " <<
                    in->GetName() << '\t' <<
                    in->GetID() << '\t' <<
                    in->GetLevel() <<
                    endl;
                }
            }
        }
    }
}

void CIRCUIT::SetMaxLevel()
{
    for (unsigned i = 0;i < No_Gate();i++) {
        if (Gate(i)->GetLevel() > MaxLevel) {
            MaxLevel = Gate(i)->GetLevel();
        }
    }
}

//Setup the Gate ID and Inversion
//Setup the list of PI PPI PO PPO
void CIRCUIT::SetupIO_ID()
{
    unsigned i = 0;
    GATE* gptr;
    vector<GATE*>::iterator Circuit_ite = Netlist.begin();
    for (; Circuit_ite != Netlist.end();Circuit_ite++, i++) {
        gptr = (*Circuit_ite);
        gptr->SetID(i);
        switch (gptr->GetFunction()) {
            case G_PI: PIlist.push_back(gptr);
                break;
            case G_PO: POlist.push_back(gptr);
                break;
            case G_PPI: PPIlist.push_back(gptr);
                break;
            case G_PPO: PPOlist.push_back(gptr);
                break;
            case G_NOT: gptr->SetInversion();
                break;
            case G_NAND: gptr->SetInversion();
                break;
            case G_NOR: gptr->SetInversion();
                break;
            default:
                break;
        }
    }
}
