#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <chrono>
#include "Dentist.h"
#include "Patient.h"

class Appointment {
private:
    int room;
    std::chrono::system_clock::time_point date;
    Dentist* dentist;
    Patient* patient;
    bool isFree;

public:
    Appointment(int room, std::chrono::system_clock::time_point date, Dentist* dentist, bool isFree, Patient* patient = nullptr)
        : room(room), date(date), dentist(dentist), isFree(isFree), patient(patient) {}

    void setPatient(Patient* newPatient);

    // Public getter methods
    int getRoom() const { return room; }
    std::chrono::system_clock::time_point getDate() const { return date; }
    Dentist* getDentist() const { return dentist; }
    Patient* getPatient() const { return patient; }
    bool getIsFree() const { return isFree; }
};

#endif // APPOINTMENT_H
