#include "Book.h"
#include <iostream>
#include <limits>
#include <string>
#include <regex>
#include <chrono>
#include <iomanip>
#include <sstream>

Book::Book(Data* data, View* view) : data(data), view(view) {}

void Book::startBookingProcess() {
    view->printPatients();
    selectPatient();
}

void Book::selectPatient() {
    int patientID;
    std::cout << "Enter patient ID: ";
    std::cin >> patientID;
    Patient* patient = data->getPatient(patientID - 1); 

    if (patient != nullptr) {
        view->printDentists();
        selectDentist(patient);
    } else {
        std::cout << "Invalid patient ID, try again.\n";
        startBookingProcess();
    }
}

void Book::selectDentist(Patient* patient) {
    int dentistID;
    std::cout << "Enter dentist ID: ";
    std::cin >> dentistID;
    Dentist* dentist = data->getDentist(dentistID - 1);  

    if (dentist != nullptr) {
        view->printDoctorsAvailableAppointments(dentistID);
        selectAppointmentById(patient, dentist);
    } else {
        std::cout << "Invalid dentist ID, try again.\n";
        selectDentist(patient);
    }
}

void Book::selectAppointmentById(Patient* patient, Dentist* dentist) {
    std::cout << "Enter appointment ID: ";
    int appointmentId;
    std::cin >> appointmentId;

    auto appointments = data->getAppointments();
    bool found = false;

    for (auto& appointment : appointments) {
        if (appointment.getDentist() == dentist &&
            appointment.getID() == appointmentId &&
            !appointment.getPatient()) {
            appointment.setPatient(patient);
            std::cout << "Appointment booked successfully.\n";
            confirmBooking(&appointment);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid appointment ID or appointment is not available, try again.\n";
        selectAppointmentById(patient, dentist);
    }
}

void Book::confirmBooking(Appointment* appointment) {
    
    std::time_t appointmentTime = std::chrono::system_clock::to_time_t(appointment->getDate());
    std::cout << "Booking confirmed for " << appointment->getPatient()->getFirstName()
              << " with Dr. " << appointment->getDentist()->getFirstName()
              << " on " <<  std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d at %H:%M") << "\n";
    data->addAppointment(*appointment);
}
