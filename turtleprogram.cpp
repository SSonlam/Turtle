/**
 *.cpp file for TurtleProgram
 *
 * @author Sonlam Nguyen
 * @date 01/17/2020
 */

#include "turtleprogram.h"
#include <cassert>

TurtleProgram::TurtleProgram() {
    length = 0;
    turtleArray = new string[0];
}

TurtleProgram::TurtleProgram(const string &Command) {
    const int OneParam = 1;
    length = OneParam;
    turtleArray = new string[OneParam];
    turtleArray[0] = Command;
}

TurtleProgram::TurtleProgram(const string &Command, const string &Times) {
    const int TwoParam = 2;
    length = TwoParam;
    turtleArray = new string[TwoParam];
    turtleArray[0] = Command;
    turtleArray[1] = Times;
}


TurtleProgram::TurtleProgram(const TurtleProgram &Tp) {
    *this = Tp;
}

// accessors
int TurtleProgram::getLength() const {
    return length;
}
string TurtleProgram::getIndex(const int &I) const {
    if (turtleArray == nullptr) { return "empty array"; }
    if (I < 0 || I > length) { return "out of scope"; }
    return turtleArray[I];
}

// mutators
void TurtleProgram::setIndex(const int &I, const string &Str) {
    if (turtleArray == nullptr || I < 0 || I > length) {
        cout << "Cannot perform setIndex" << endl;
    }
    else {
        turtleArray[I] = Str;
    }
}

// equality
bool TurtleProgram::operator!=(const TurtleProgram &Rhs) const {
    return !(*this == Rhs);
}

bool TurtleProgram::operator==(const TurtleProgram &Rhs) const {
    if (length != Rhs.length) { return false; }
    for (int I = 0; I < length; I++) {
        if (turtleArray[I].compare(Rhs.turtleArray[I]) != 0) {
            return false;
        }
    }
    return true;
}

// + and +=
TurtleProgram TurtleProgram::operator+(const TurtleProgram &Tp) const {
    TurtleProgram Bigger;
    Bigger.length = length + Tp.length;
    delete[]Bigger.turtleArray;
    Bigger.turtleArray = new string[Bigger.length];
    int I = 0;
    if (length > 0) {
        for (I = 0; I < length; I++) {
            Bigger.turtleArray[I] = turtleArray[I];
        }
    }
    if(Tp.length > 0){
        for (int J = 0; J < Tp.length; J++) {
            Bigger.turtleArray[I] = Tp.turtleArray[J];
            I++;
        }
    }
    return Bigger;
}

TurtleProgram &TurtleProgram::operator+=(const TurtleProgram &Tp) {
    string* TempPtr;
    TempPtr = new string[length];
    for (int I = 0; I < length; I++) {
        TempPtr[I] = turtleArray[I];
    }
    delete []turtleArray;
    turtleArray = new string[length + Tp.length];
    int I = 0;
    for (I = 0; I < length; I++) {
        turtleArray[I] = TempPtr[I];
    }
    for (int J = 0; J < Tp.length; J++) {
        turtleArray[I] = Tp.turtleArray[J];
        I++;
    }
    length += Tp.length;
    delete []TempPtr;
    return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int &Times) const {
    assert(Times > 0);
    TurtleProgram Bigger;
    Bigger.length = length * Times;
    delete[]Bigger.turtleArray;
    Bigger.turtleArray = new string[Bigger.length];
    int I = 0;
    while (I < Bigger.length) {
        for (int J = 0; J < length; J++) {
            Bigger.turtleArray[I] = turtleArray[J];
            I++;
        }
    }
    return Bigger;
}

TurtleProgram &TurtleProgram::operator*=(const int &Times) {
    assert(Times > 0);
    string *TempPtr;
    TempPtr = new string[length];
    for (int I = 0; I < length; I++) {
        TempPtr[I] = turtleArray[I];
    }
    delete []turtleArray;
    turtleArray = new string[length * Times];
    int I = 0;
    while (I < (length * Times)) {
        for (int J = 0; J < length; J++) {
            turtleArray[I] = TempPtr[J];
            I++;
        }
    }
    delete []TempPtr;
    length *= Times;
    return *this;
}

TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) { // copy assignment
    if (this != &Rhs) {
        delete []turtleArray;
        length = Rhs.length;
        turtleArray = new string[Rhs.length];
        for (int I = 0; I < Rhs.length; I++) {
            turtleArray[I] = Rhs.turtleArray[I];
        }
    }
    return *this;
}

TurtleProgram::~TurtleProgram() {
    delete []turtleArray;
}

// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
ostream &operator<<(ostream &Out, const TurtleProgram &Tp) {
    Out << "[";
    for (int I = 0; I < Tp.length; I++) {
        Out << Tp.turtleArray[I];
        if (I != (Tp.length - 1)) {
            Out << " ";
        }
    }
    Out << "]";
    return Out;                      // e.g., enables cout << x << y;
}