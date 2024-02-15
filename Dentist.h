#ifndef DENTIST_H
#define DENTIST_H

#include "Person.h"

class Dentist : public Person {
 private:
  int dentistID;
  int salary;
 Public:
  Dentist(std::string t, std::string fn, std::string sn, std::string a, std::string e, int ID, int s) {
    setTitle(t);
    setFirstName(fn);
    setSurname(sn);
    setAddress(a);
    setEmail(e);
    setDentistID(ID);
    setSalary(s);
  }
  void setDentistID(int ID);
  void setSalary(int s);
  int getDentistID();
  int getSalary();
};

#endif
