#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
 private:
  int patientID;
 Public:
  Patient(std::string t, std::string fn, std::string sn, std::string a, std::string e, int ID) {
    setTitle(t);
    setFirstName(fn);
    setSurname(sn);
    setAddress(a);
    setEmail(e);
    setPatientID(ID);
  }
  void setPatientID(int ID);
  int getPatientID();
};

#endif
