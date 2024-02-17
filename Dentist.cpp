#include "Dentist.h"

void Dentist::setDentistID(int ID) {
  dentistID = ID;
}

void Dentist::setSalary(int s) {
  salary = s;
}

int Dentist::getDentistID() const {
  return dentistID;
}

int Dentist::getSalary() const {
  return salary;
}
