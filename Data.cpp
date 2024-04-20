#include <iostream>
#include "Data.h"

//Setter methods.

void Data::setDentists(std::vector<Dentist> d) {
  dentists = d;
}
  
void Data::setPatients(std::vector<Patient> p) {
  patients = p;
}
  
void Data::setAppointments(std::vector<Appointment> a) {
  appointments = a;
}
  
void Data::setRooms(std::vector<Room> r) {
  rooms = r;
}

//Adder methods.

void Data::addDentist(Dentist d) {
  //std::cout << "Adding dentist: " << d.getDentistID() << std::endl;
  dentists.push_back(d);
}

void Data::addPatient(Patient p) {
  //std::cout << "Adding patient: " << p.getPatientID() << std::endl;
  patients.push_back(p);
}

void Data::addAppointment(Appointment a) {
  //std::cout << "Adding appointment: " << a.getID() << std::endl;
  appointments.push_back(a);
}
 
void Data::addRoom(Room r) {
  //std::cout << "Adding room: " << r.getID() << std::endl;
  rooms.push_back(r);
}

//Remover methods.

void Data::removeDentist(Dentist d) {
  for (unsigned short int i; i < dentists.size(); i++) {
     if (dentists[i].getDentistID() == d.getDentistID()) {
       dentists.erase(dentists.begin() + i);
       std::cout << i << " " << dentists[i].getFirstName() << " " << dentists[i].getSurname() << std::endl;
     }
   }
}

void Data::removePatient(Patient p) {
  for (unsigned short int i; i < patients.size(); i++) {
     if (patients[i].getPatientID() == p.getPatientID()) {
       patients.erase(patients.begin() + i);
       std::cout << i << " " << patients[i].getFirstName() << " " << patients[i].getSurname() << std::endl;
     }
   }
}

void Data::removeAppointment(Appointment a) {
  for (unsigned short int i; i < appointments.size(); i++) {
     if (appointments[i].getID() == a.getID()) {
       appointments.erase(appointments.begin() + i);
       std::cout << i << " " << appointments[i].getID() << std::endl;
     }
   }
}

void Data::removeRoom(Room r) {
  for (unsigned short int i; i < rooms.size(); i++) {
     if (rooms[i].getID() == r.getID()) {
       rooms.erase(rooms.begin() + i);
       std::cout << i << " " << rooms[i].getID() << std::endl;
     }
   }
}

//Getter methods.

std::vector<Dentist> Data::getDentists() const {
  return dentists;
}

std::vector<Patient> Data::getPatients() const {
  return patients;
}

std::vector<Appointment>& Data::getAppointments() {
    return appointments;
}

std::vector<Room> Data::getRooms() const {
  return rooms;
}

Dentist* Data::getDentist(int index) {
  return &dentists[index];
}

Patient* Data::getPatient(int index) {
  return &patients[index];
}

Appointment Data::getAppointment(int index) const {
  return appointments[index];
}

Room* Data::getRoom(int index) {
  return &rooms[index];
}
