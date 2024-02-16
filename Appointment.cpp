#include "Appointment.h"

void Appointment::setPatient(Patient* newPatient) {
    if (isFree) {
        patient = newPatient;
        isFree = false;
    }
}