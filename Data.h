#ifndef DATA_H
#define DATA_H

#include <vector>
#include "Dentist.h"
#include "Patient.h"
#include "Appointment.h"
#inclide "Room.h"

//Prototype classes, to prevent recursive inclusion.

class Dentist;
class Patient;
class Appointment;
class Room;

class Data {
 private:
  std::vector<Dentist> dentists;
  std::vector<Patient> patients;
  std::vector<Appointment> appointments;
  std::vector<Room> rooms;
 public:
  //Public setter methods.
  void setDentists(std::vector<Dentist> d);
  void setPatients(std::vector<Patients> p);
  void setAppointments(std::vector<Appointment> a);
  void setRooms(std::vector<Room> r);

  //Public adder methods.
  void addDentist(Dentist d);
  void addPatient(Patient p);
  void addAppointment(Appointment a);
  void addRoom(Room r);

  //Public remover methods.
  void removeDentist(Dentist d);
  void removePatient(Patient p);
  void removeAppointment(Appointment a);
  void removeRoom(Room r);

  //Public getter methods.
  std::vector<Dentist> getDentists() const;
  std::vector<Patient> getPatients() const;
  std::vector<Appointment> getAppointments() const;
  std::vector<Room> getRooms() const;
};

#endif // DATA_H
