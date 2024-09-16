#include <iostream> 
#include <stack>
//#include <alg.h>
#include "circuit.h"
#include "GetLongOpt.h"
using namespace std;

extern GetLongOpt option;

double CIRCUIT::AverageNo_Fanout() {
    unsigned int fanout_num = 0;
    for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
        fanout_num += (*it)->No_Fanout();
    }
    return static_cast<double>(fanout_num) / this->Netlist.size();
}

void CIRCUIT::PrintEachGate() {
    cout << "all gates:" << endl;
    for (vector<GATE*>::iterator it = this->Netlist.begin(); it != this->Netlist.end(); it++) {
        cout << "\tname: " << (*it)->GetName()
             << ", level: " << (*it)->GetLevel()
             << ", function: " << (*it)->GetFunction()
             << ", fanin: " << (*it)->No_Fanin()
             << ", fanout: " << (*it)->No_Fanout()
             << ", to primary output: " << (((*it)->GetFlag(TO_PRIMARY_OUTPUT)) ? "Y" : "N")
             << endl;
    }
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

void CIRCUIT::PrintAllPath(const char* const start, const char* const end) {
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
    if (start_gate != nullptr && end_gate != nullptr) {
        end_gate->SetFlag(TO_PRIMARY_OUTPUT);
        for (unsigned int i = 0; i < end_gate->GetLevel(); i++) {
            for (unsigned int j = 0; j < this->No_Gate(); j++) {
                if (!this->Gate(j)->GetFlag(TO_PRIMARY_OUTPUT)) {
                    for (unsigned int k = 0; k < this->Gate(j)->No_Fanout(); k++) {
                        if (this->Gate(j)->Fanout(k)->GetFlag(TO_PRIMARY_OUTPUT)) {
                            this->Gate(j)->SetFlag(TO_PRIMARY_OUTPUT);
                            break;
                        }
                    }
                }
            }
        }
        std::stack<GATE*> process_stack;
        std::stack<std::string> path_stack;
        process_stack.push(start_gate);
        path_stack.push("");
        int path_num = 0;
        GATE* now_gate;
        string now_path, gate_name;
        while (!process_stack.empty()) {
            now_gate = process_stack.top();
            process_stack.pop();
            now_path = path_stack.top();
            path_stack.pop();
            gate_name = now_gate->GetName();
            int fanout = now_gate->No_Fanout();
            if (fanout > 0) {
                for (int i = 0; i < fanout; i++) {
                    if (now_gate->Fanout(i)->GetFlag(TO_PRIMARY_OUTPUT)) {
                        process_stack.push(now_gate->Fanout(i));
                        path_stack.push(now_path + " " + gate_name);
                    }
                }
            }
            else {
                cout << now_path.substr(1, now_path.length() - 1) + " " + gate_name << "\n";
                path_num++;
            }
        }
        cout << "The paths from " << start << " to " << end << ": " << path_num << endl;
        // PrintEachGate();
        for (unsigned int i = 0; i < this->No_Gate(); i++) {
            if (this->Gate(i)->GetFlag(TO_PRIMARY_OUTPUT)) {
                this->Gate(i)->ResetFlag(TO_PRIMARY_OUTPUT);
            }
        }
    }
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
