/* Logic Simulator
 * Last update: 2006/09/20 */
#include <iostream>
#include "gate.h"
#include "circuit.h"
#include "ReadPattern.h"
#include "GetLongOpt.h"
using namespace std;

extern GetLongOpt option;

//do logic simulation for test patterns
void CIRCUIT::LogicSimVectors()
{
    cout << "Run logic simulation" << endl;
    //read test patterns
    while (!Pattern.eof()) {
        Pattern.ReadNextPattern();
        SchedulePI();
        LogicSim();
        PrintIO();
    }
    return;
}

void CIRCUIT::ModifiedLogicSimVectors() {
    cout << "Run modified logic simulation" << endl;
    while (!Pattern.eof()) {
        Pattern.ModifiedReadNextPattern();
        SchedulePI();
        ModifiedLogicSim();
        ModifiedPrintIO();
    }
}

//do event-driven logic simulation
void CIRCUIT::LogicSim()
{
    GATE* gptr;
    VALUE new_value;
    for (unsigned i = 0;i <= MaxLevel;i++) {
        while (!Queue[i].empty()) {
            gptr = Queue[i].front();
            Queue[i].pop_front();
            gptr->ResetFlag(SCHEDULED);
            new_value = Evaluate(gptr);
            if (new_value != gptr->GetValue()) {
                gptr->SetValue(new_value);
                ScheduleFanout(gptr);
            }
        }
    }
    return;
}

void CIRCUIT::ModifiedLogicSim() {
    GATE* gptr;
    bitset<2> new_value_3;
    for (unsigned int i = 0; i <= this->MaxLevel; i++) {
        while (!Queue[i].empty()) {
            gptr = Queue[i].front();
            Queue[i].pop_front();
            gptr->ResetFlag(SCHEDULED);
            new_value_3 = ModifiedEvaluate(gptr);
            if (new_value_3 != gptr->GetValue_3()) {
                gptr->SetValue_3(new_value_3);
                ScheduleFanout(gptr);
            }
        }
    }
}

//Used only in the first pattern
void CIRCUIT::SchedulePI()
{
    for (unsigned i = 0;i < No_PI();i++) {
        if (PIGate(i)->GetFlag(SCHEDULED)) {
            PIGate(i)->ResetFlag(SCHEDULED);
            ScheduleFanout(PIGate(i));
        }
    }
    return;
}

//schedule all fanouts of PPIs to Queue
void CIRCUIT::SchedulePPI()
{
    for (unsigned i = 0;i < No_PPI();i++) {
        if (PPIGate(i)->GetFlag(SCHEDULED)) {
            PPIGate(i)->ResetFlag(SCHEDULED);
            ScheduleFanout(PPIGate(i));
        }
    }
    return;
}

//set all PPI as 0
void CIRCUIT::SetPPIZero() {
    for (unsigned int i = 0; i < No_PPI(); i++) {
        GATE* gptr = PPIGate(i);
        if (gptr->GetValue() != S0) {
            gptr->SetFlag(SCHEDULED);
            gptr->SetValue(S0);
        }
    }
    return;
}

//schedule all fanouts of gate to Queue
void CIRCUIT::ScheduleFanout(GATE* gptr)
{
    for (unsigned j = 0;j < gptr->No_Fanout();j++) {
        Schedule(gptr->Fanout(j));
    }
    return;
}

//initial Queue for logic simulation
void CIRCUIT::InitializeQueue()
{
    SetMaxLevel();
    Queue = new ListofGate[MaxLevel + 1];
    return;
}

//evaluate the output value of gate
VALUE CIRCUIT::Evaluate(GATEPTR gptr)
{
    GATEFUNC fun(gptr->GetFunction());
    VALUE cv(CV[fun]); //controling value
    VALUE value(gptr->Fanin(0)->GetValue());
    switch (fun) {
        case G_AND:
        case G_NAND:
            for (unsigned i = 1;i<gptr->No_Fanin() && value != cv;++i) {
                value = AndTable[value][gptr->Fanin(i)->GetValue()];
            }
            break;
        case G_OR:
        case G_NOR:
            for (unsigned i = 1;i<gptr->No_Fanin() && value != cv;++i) {
                value = OrTable[value][gptr->Fanin(i)->GetValue()];
            }
            break;
        default: break;
    }
    //NAND, NOR and NOT
    if (gptr->Is_Inversion()) { value = NotTable[value]; }
    return value;
}

bitset<2> CIRCUIT::ModifiedEvaluate(GATEPTR gptr) {
    GATEFUNC fun(gptr->GetFunction());
    bitset<2> cv_3(CV_3[fun]); //controling value
    bitset<2> value_3(gptr->Fanin(0)->GetValue_3());
    switch (fun) {
        case G_AND:
        case G_NAND:
            for (unsigned int i = 1; i < gptr->No_Fanin() && value_3 != cv_3; i++) {
                value_3 = value_3 & gptr->Fanin(i)->GetValue_3();
            }
            break;
        case G_OR:
        case G_NOR:
            for (unsigned int i = 1; i < gptr->No_Fanin() && value_3 != cv_3; i++) {
                value_3 = value_3 | gptr->Fanin(i)->GetValue_3();
            }
            break;
        default: break;
    }
    //NAND, NOR and NOT
    if (gptr->Is_Inversion()) {
        value_3 = ~value_3;
        bool temp = value_3[0];
        value_3[0] = value_3[1];
        value_3[1] = temp;
    }
    return value_3;
}

extern GATE* NameToGate(string);

void PATTERN::Initialize(char* InFileName, int no_pi, const string& TAG) {
    patterninput.open(InFileName, ios::in);
    if (!patterninput) {
        cout << "Unable to open input pattern file: " << InFileName << endl;
        exit( -1);
    }
    string piname;
    while (no_pi_infile < no_pi) {
        patterninput >> piname;
        if (piname == TAG) {
            patterninput >> piname;
            inlist.push_back(NameToGate(piname));
            no_pi_infile++;
        }
        else {
            cout << "Error in input pattern file at line "
                << no_pi_infile << endl;
            cout << "Maybe insufficient number of input\n";
            exit( -1);
        }
    }
    return;
}

//Assign next input pattern to PI
void PATTERN::ReadNextPattern()
{
    char V;
    for (int i = 0;i < no_pi_infile;i++) {
        patterninput >> V;
        if (V == '0') {
            if (inlist[i]->GetValue() != S0) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue(S0);
            }
        }
        else if (V == '1') {
            if (inlist[i]->GetValue() != S1) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue(S1);
            }
        }
        else if (V == 'X') {
            if (inlist[i]->GetValue() != X) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue(X);
            }
        }
    }
    //Take care of newline to force eof() function correctly
    patterninput >> V;
    if (!patterninput.eof()) patterninput.unget();
    return;
}

void PATTERN::FeedNextPattern() {
    for (int i = 0; i < no_pi_infile; i++) {
        int V = 2.0 * rand() / (RAND_MAX + 1.0);
        if (V == 0) {
            if (inlist[i]->GetValue() != S0) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue(S0);
            }
        }
        else {
            if (inlist[i]->GetValue() != S1) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue(S1);
            }
        }
    }
}

void PATTERN::ModifiedReadNextPattern()
{
    char V;
    for (int i = 0;i < no_pi_infile;i++) {
        patterninput >> V;
        if (V == '0') {
            if (inlist[i]->GetValue_3() != S0_3) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue_3(S0_3);
            }
        }
        else if (V == '1') {
            if (inlist[i]->GetValue_3() != S1_3) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue_3(S1_3);
            }
        }
        else if (V == 'X') {
            if (inlist[i]->GetValue_3() != X_3) {
                inlist[i]->SetFlag(SCHEDULED);
                inlist[i]->SetValue_3(X_3);
            }
        }
    }
    //Take care of newline to force eof() function correctly
    patterninput >> V;
    if (!patterninput.eof()) patterninput.unget();
    return;
}

void CIRCUIT::PrintIO()
{
    register unsigned i;
    for (i = 0;i<No_PI();++i) { cout << PIGate(i)->GetValue(); }
    cout << " ";
    for (i = 0;i<No_PO();++i) { cout << POGate(i)->GetValue(); }
    cout << endl;
    return;
}

void CIRCUIT::ModifiedPrintIO()
{
    register unsigned i;
    bitset<2> b;
    for (i = 0; i < No_PI(); i++) {
        b = PIGate(i)->GetValue_3();
        if (b == S0_3) {
            cout << S0;
        }
        else if (b == S1_3) {
            cout << S1;
        }
        else {
            cout << X;
        }
    }
    cout << " ";
    for (i = 0; i < No_PO(); i++) {
        b = POGate(i)->GetValue_3();
        if (b == S0_3) {
            cout << S0;
        }
        else if (b == S1_3) {
            cout << S1;
        }
        else {
            cout << X;
        }
    }
    cout << endl;
    return;
}

