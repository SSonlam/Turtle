/**
 * .h file for TurtleProgram
 *
 * @author Sonlam Nguyen
 * @date 01/17/2020
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TurtleProgram {
    friend ostream &operator<<(ostream &Out, const TurtleProgram &Tp);

public:
    TurtleProgram();
    explicit TurtleProgram(const string &Command);
    TurtleProgram(const string &Command, const string &Times);
    TurtleProgram(const TurtleProgram &Tp);
    virtual ~TurtleProgram();

    int getLength() const;
    string getIndex(const int &I) const;
    void setIndex(const int &I, const string &Str);

    bool operator==(const TurtleProgram &Rhs) const;
    bool operator!=(const TurtleProgram &Rhs) const;

    TurtleProgram &operator=(const TurtleProgram &Rhs);
    TurtleProgram operator+(const TurtleProgram &Tp) const;
    TurtleProgram &operator+=(const TurtleProgram &Tp);
    TurtleProgram operator*(const int &Times) const;
    TurtleProgram &operator*=(const int &Times);
protected:
private:
    int length; // how many strings in the array
    string *turtleArray = nullptr; // Memory location for arrays

};

#endif // TURTLEPROGRAM_H