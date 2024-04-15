#include "Data.h"

//Setter methods.

void Data::setDentists(std::vector<Dentist> d) {
  dentists = d;
}
  
void Data::setPatients(std::vector<Patients> p) {
  patients = p;
}
  
void Data::setAppointments(std::vector<Appointment> a) {
  appointments = a;
}
  
void Data::setRooms(std::vector<Room> r) {
  rooms = r;
}

//Adder methods.

void addDentist(Dentist d) {
  dentists.push_back(d);
}

void addPatient(Patient p) {
  patients.push_back(p);
}

void addAppointment(Appointment a) {
  appointments.push_back(a);
}

void addRoom(Room r) {
  rooms.push_back(r);
}

//Remover methods.

void removeDentist(Dentist d) {
  for (unsigned short int i; i < dentists.size(); i++) {
     if (dentists[i].getDentistID() == d.getDentistID()) {
       dentists.erase(dentists.begin() + i);
       std::cout << i << " " << dentists[i].getFirstName() << " " << dentists[i].getSurname() << std::endl;
     }
   }
}

void removePatient(Patient p) {
  for (unsigned short int i; i < patients.size(); i++) {
     if (patients[i].getPatientID() == p.getPatientID()) {
       patients.erase(patients.begin() + i);
       std::cout << i << " " << patients[i].getFirstName() << " " << patients[i].getSurname() << std::endl;
     }
   }
}

void removeAppointment(Appointment a) {
  for (unsigned short int i; i < appointments.size(); i++) {
     if (appointments[i].getID() == a.getID()) {
       appointments.erase(appointments.begin() + i);
       std::cout << i << " " << appointments[i].getID() << std::endl;
     }
   }
}

void removeRoom(Room r) {
  for (unsigned short int i; i < rooms.size(); i++) {
     if (rooms[i].getID() == r.getID()) {
       rooms.erase(rooms.begin() + i);
       std::cout << i << " " << rooms[i].getID() << std::endl;
     }
   }
}

//Getter methods.

std::vector<Dentist> getDentists() const {
  return dentists;
}

std::vector<Patient> getPatients() const {
  return patients;
}

std::vector<Appointment> getAppointments() const {
  return appointments;
}

std::vector<Room> getRooms() const {
  return rooms;
}
