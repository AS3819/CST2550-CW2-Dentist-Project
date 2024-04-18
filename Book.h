#ifndef BOOK_H
#define BOOK_H

#include "Data.h"
#include "View.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Patient.h"
#include <vector>
#include <iostream>

class Book {
private:
    Data* data;
    View* view;

public:
    Book(Data* data, View* view);
    void startBookingProcess();
    void selectPatient();
    void selectDentist(Patient* patient);
    void selectAppointmentById(Patient* patient, Dentist* dentist);
    void confirmBooking(Appointment* appointment);
};

#endif
