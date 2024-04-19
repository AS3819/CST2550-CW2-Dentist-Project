#include "Book.h"
#include "Print_Functions.h"
#include "Input_Validation.h"
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
  std::string patientInput;
  int patientID;
  bool valid = false;
  std::cout << "Enter patient ID (press 0 to cancel): ";
  std::cin >> patientInput;
  
  if (isIntegerString(patientInput)) {
    patientID = stoi(patientInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectPatient();
  }

  if (valid) {
    Patient* patient = data->getPatient(patientID - 1); 
    if (patientID != 0) {
      if (patient != nullptr) {
	view->printDentists();
	selectDentist(patient);
      } else {
	println("Invalid patient ID, try again.");
	startBookingProcess();
      }
    } else {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::selectDentist(Patient* patient) {
  std::string dentistInput;
  int dentistID;
  bool valid = false;
  std::cout << "Enter dentist ID (press 0 to cancel): ";
  std::cin >> dentistInput;
  
  if (isIntegerString(dentistInput)) {
    dentistID = stoi(dentistInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectDentist(patient);
  }

  if (valid) {
    Dentist* dentist = data->getDentist(dentistID - 1);  
    if (dentistID != 0) {
      if (dentist != nullptr) {
        view->printDoctorsAvailableAppointments(dentistID);
        selectAppointmentById(patient, dentist);
      } else {
	println("Invalid patient ID, try again.");
        selectDentist(patient);
      }
    } else {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::selectAppointmentById(Patient* patient, Dentist* dentist) {
  std::cout << "Enter appointment ID (press 0 to cancel): ";
  std::string appointmentInput;
  int appointmentId;
  bool valid = false;
  std::cin >> appointmentInput;

  if (isIntegerString(appointmentInput)) {
    appointmentId = stoi(appointmentInput);
    valid = true;
  } else {
    println("Invalid input, try again.");
    selectAppointmentById(patient, dentist);
  }

  if (valid) {
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

    if (!found && appointmentId != 0) {
      println("Invalid appointment ID or appointment is not available, try again.");
      selectAppointmentById(patient, dentist);
    } else {
      println("Booking process cancelled. Returning to the main menu.");
    }
  }
}

void Book::confirmBooking(Appointment* appointment) {
    
    std::time_t appointmentTime = std::chrono::system_clock::to_time_t(appointment->getDate());
    std::cout << "Booking confirmed for " << appointment->getPatient()->getFirstName()
              << " with Dr. " << appointment->getDentist()->getFirstName()
              << " on " <<  std::put_time(std::localtime(&appointmentTime), "%Y-%m-%d at %H:%M") << "\n";
    data->addAppointment(*appointment);
}
