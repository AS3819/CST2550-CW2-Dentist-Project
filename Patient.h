#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
private:
    int patientID;

public:
    Patient(const std::string& t, const std::string& fn, const std::string& sn, const std::string& a, const std::string& e, int ID)
    : Person(t, fn, sn, a, e), patientID(ID) {}

    void setPatientID(int ID);
    int getPatientID() const;
};

#endif // PATIENT_H
