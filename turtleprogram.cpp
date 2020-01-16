/**
 * TODO file documentation
 *
 * @author TODO
 * @date TODO
 */

#include "turtleprogram.h"
#include <cassert>

TurtleProgram::TurtleProgram() {

}

TurtleProgram::TurtleProgram(const string &Command) {
}

TurtleProgram::TurtleProgram(const string &Command, const string &Times) {
}

TurtleProgram::TurtleProgram(const TurtleProgram &Tp) {
}

// accessors
int TurtleProgram::getLength() const {
}
string TurtleProgram::getIndex(const int &I) const {
}

// mutators
void TurtleProgram::setIndex(const int &I, const string &Str) {
}

// equality
bool TurtleProgram::operator!=(const TurtleProgram &Rhs) const {
}

bool TurtleProgram::operator==(const TurtleProgram &Rhs) const {
}

// + and +=
TurtleProgram TurtleProgram::operator+(const TurtleProgram &Tp) const {
  TurtleProgram Bigger;
  return Bigger;
}

TurtleProgram &TurtleProgram::operator+=(const TurtleProgram &Tp) {
  return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int &Times) const {
  assert(Times > 0);
  TurtleProgram Bigger;
  return Bigger;
}

TurtleProgram &TurtleProgram::operator*=(const int &Times) {
  assert(Times > 0);
  return *this;
}

TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) { // copy assignment
  return *this;
}

TurtleProgram::~TurtleProgram() {
}

// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
ostream &operator<<(ostream &Out,
                    const TurtleProgram &Tp) {
  return Out;                      // e.g., enables cout << x << y;
}
