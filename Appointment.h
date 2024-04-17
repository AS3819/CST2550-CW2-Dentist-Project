#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include <chrono>

//Prototype class for 'Room', to prevent recursive inclusion.

class Room;

class Appointment {
 private:
  int appointmentID;
  Room* room;
  std::chrono::system_clock::time_point date;
  Dentist* dentist;
  Patient* patient;
  bool isFree;
  
 public:
  Appointment(int ID, Room* r, std::chrono::system_clock::time_point dt, Dentist* d) {
    setID(ID);
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(nullptr);
    isFree = false;
  }
  
  Appointment(int ID, Room* r, std::chrono::system_clock::time_point dt, Dentist* d, Patient* p) {
    setID(ID);
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(p);
    isFree = false;
  }

  //Public setter methods.
  void setID(int ID);
  void setRoom(Room* newRoom);
  void setDate(std::chrono::system_clock::time_point newDate);
  void setDentist(Dentist* newDentist);
  void setPatient(Patient* newPatient);

  //Public getter methods.
  int getID() const;
  Room* getRoom() const;
  std::chrono::system_clock::time_point getDate() const;
  Dentist* getDentist() const;
  Patient* getPatient() const;
  bool getIsFree() const;
};

#endif // APPOINTMENT_H
