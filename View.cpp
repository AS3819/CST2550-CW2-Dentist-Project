#include <iostream>
#include "View.h"
#include "Print_Functions.h"

void View::printDentists() {
  for (unsigned short int i = 0; i < data->getDentists().size(); i++) {
    Dentist* dentist = data->getDentist(i); 
    if (dentist != nullptr) {  
      std::cout << dentist->getDentistID() << ") " << dentist->getTitle() << " "
                << dentist->getFirstName() << " " << dentist->getSurname() << std::endl;
    }
  }
}


void View::printPatients() {
  for (unsigned short int i = 0; i < data->getPatients().size(); i++) {
    Patient* patient = data->getPatient(i);
    if (patient != nullptr) {
      std::cout << patient->getPatientID() << ") " << patient->getTitle() << " "
                << patient->getFirstName() << " " << patient->getSurname() << std::endl;
    }
  }
}


void View::printRooms() {
  for (unsigned short int i = 0; i < data->getRooms().size(); i++) {
    Room* room = data->getRoom(i);  
    if (room != nullptr) {  
      std::cout << "Room No." << room->getID() << std::endl;
    }
  }
}

void View::printAppointments() {
    auto appointments = data->getAppointments();
    for (unsigned short int i = 0; i < appointments.size(); i++) {
        const Appointment& app = appointments[i];

        std::cout << "ID: " << app.getID() << std::endl;

        if (app.getRoom()) {
            std::cout << "Room: " << app.getRoom()->getID() << std::endl;
        } else {
            std::cout << "Room: None" << std::endl;
        }

        if (app.getDentist()) {
            std::cout << "Dentist: " << app.getDentist()->getTitle() << " " 
                      << app.getDentist()->getFirstName() << " " 
                      << app.getDentist()->getSurname() << std::endl;
        } else {
            std::cout << "Dentist: None" << std::endl;
        }
        
        if (app.getPatient()) {
            std::cout << "Patient: " << app.getPatient()->getTitle() << " " 
                      << app.getPatient()->getFirstName() << " " 
                      << app.getPatient()->getSurname() << std::endl;
        } else {
            std::cout << "Patient: None" << std::endl;
        }
    }
}

