#ifndef BFAULT_H
#define BFAULT_H

#include "gate.h"

class BFAULT {
    private:
        VALUE Value;
        GATE* Input1;
        GATE* Input2;
        unsigned EqvFaultNum;
        FAULT_STATUS Status;
    public:
        BFAULT(GATE* gptr1, GATE* gptr2, VALUE value): Value(value), Input1(gptr1), Input2(gptr2), EqvFaultNum(1), Status(UNKNOWN) {}
        ~BFAULT() {}
        VALUE GetValue() const { return Value; }
        GATE* GetInputGate1() { return Input1; }
        GATE* GetInputGate2() { return Input2; }
        void SetEqvFaultNum(unsigned n) { EqvFaultNum = n; }
        void IncEqvFaultNum() { ++EqvFaultNum; }
        unsigned GetEqvFaultNum() const { return EqvFaultNum; }
        void SetStatus(FAULT_STATUS status) { Status = status; }
        FAULT_STATUS GetStatus() const { return Status; }
};

#endif  // BFAULT_H
