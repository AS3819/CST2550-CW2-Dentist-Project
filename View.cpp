#include <iostream>
#include "View.h"
#include "Print_Functions.h"

void View::printDentists() {
  for (unsigned short int i = 0; i < data->getDentists().size(); i++) {
    std::cout << data->getDentist(i).getDentistID() << ") " << data->getDentist(i).getTitle() << " " << data->getDentist(i).getFirstName() << " " << data->getDentist(i).getSurname() << std::endl;
  }
}

void View::printPatients() {
  for (unsigned short int i = 0; i < data->getPatients().size(); i++) {
    std::cout << data->getPatient(i).getPatientID() << ") " << data->getPatient(i).getTitle() << " " << data->getPatient(i).getFirstName() << " " << data->getPatient(i).getSurname() << std::endl;
  }
}

void View::printRooms() {
  for (unsigned short int i = 0; i < data->getRooms().size(); i++) {
    std::cout << "Room No." << data->getRoom(i).getID() << std::endl;
  }
}

void View::printAppointments() {
  for (unsigned short int i = 0; i < data->getAppointments().size(); i++) {
    std::cout << "ID: " << data->getAppointment(i).getID() << std::endl;
    std::cout << "Room: " << data->getAppointment(i).getRoom()->getID() << std::endl;
    std::cout << "Dentist: " << data->getAppointment(i).getDentist()->getTitle() << " " << data->getAppointment(i).getDentist()->getFirstName() << " " << data->getAppointment(i).getDentist()->getSurname() << std::endl;
    std::cout << "Patient: " << data->getAppointment(i).getPatient()->getTitle() << " " << data->getAppointment(i).getPatient()->getFirstName() << " " << data->getAppointment(i).getPatient()->getSurname() << std::endl;
    std::cout << "Date: " << data->getAppointment(i).getDate() << std::endl;
  }
}
