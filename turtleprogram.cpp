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
    const int oneParam = 1;
    length = oneParam;
    turtleArray = new string[oneParam];
    turtleArray[0] = Command;
}

TurtleProgram::TurtleProgram(const string &Command, const string &Times) {
    const int twoParam = 2;
    length = twoParam;
    turtleArray = new string[twoParam];
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
    for (int i = 0; i < length; i++) {
        if (turtleArray[i].compare(Rhs.turtleArray[i]) != 0) {
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
    int i = 0;
    if (length > 0) {
        for (i; i < length; i++) {
            Bigger.turtleArray[i] = turtleArray[i];
        }
    }
    if(Tp.length > 0){
        for (int j = 0; j < Tp.length; j++) {
            Bigger.turtleArray[i] = Tp.turtleArray[j];
            i++;
        }
    }
    return Bigger;
}

TurtleProgram &TurtleProgram::operator+=(const TurtleProgram &Tp) {
    string* tempPtr;
    tempPtr = new string[length];
    for (int i = 0; i < length; i++) {
        tempPtr[i] = turtleArray[i];
    }
    delete []turtleArray;
    turtleArray = new string[length + Tp.length];
    int i = 0;
    for (i; i < length; i++) {
        turtleArray[i] = tempPtr[i];
    }
    for (int j = 0; j < Tp.length; j++) {
        turtleArray[i] = Tp.turtleArray[j];
        i++;
    }
    length += Tp.length;
    delete []tempPtr;
    return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int &Times) const {
    assert(Times > 0);
    TurtleProgram Bigger;
    Bigger.length = length * Times;
    delete[]Bigger.turtleArray;
    Bigger.turtleArray = new string[Bigger.length];
    int i = 0;
    while (i < Bigger.length) {
        for (int j = 0; j < length; j++) {
            Bigger.turtleArray[i] = turtleArray[j];
            i++;
        }
    }
    //delete[]turtleArray;
    return Bigger;
}

TurtleProgram &TurtleProgram::operator*=(const int &Times) {
    assert(Times > 0);
    string *tempPtr;
    tempPtr = new string[length];
    for (int i = 0; i < length; i++) {
        tempPtr[i] = turtleArray[i];
    }
    delete []turtleArray;
    turtleArray = new string[length * Times];
    int i = 0;
    while (i < (length * Times)) {
        for (int j = 0; j < length; j++) {
            turtleArray[i] = tempPtr[j];
            i++;
        }
    }
    delete []tempPtr;
    length *= Times;
    return *this;
}

TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) { // copy assignment
    if (this != &Rhs) {
        delete []turtleArray;
        length = Rhs.length;
        turtleArray = new string[Rhs.length];
        for (int i = 0; i < Rhs.length; i++) {
            turtleArray[i] = Rhs.turtleArray[i];
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
    for (int i = 0; i < Tp.length; i++) {
        Out << Tp.turtleArray[i];
        if (i != (Tp.length - 1)) {
            Out << " ";
        }
    }
    Out << "]";
    return Out;                      // e.g., enables cout << x << y;
}