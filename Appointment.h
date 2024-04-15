#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <chrono>
#include "Dentist.h"
#include "Patient.h"
#inclide "Room.h"

//Prototype class for 'Room', to prevent recursive inclusion.

class Room;

class Appointment {
 private:
  Room* room;
  std::chrono::system_clock::time_point date;
  Dentist* dentist;
  Patient* patient;
  bool isFree;
  
 public:
  Appointment(Room* r, std::chrono::system_clock::time_point dt, Dentist* d) {
    setRoom(r);
    setDate(dt);
    setDentist(d);
    setPatient(nullptr);
    isFree = true;
  }

  //Public setter methods.
  void setRoom(Room* newRoom);
  void setDate(std::chrono::system_clock::time_point newDate);
  void setDentist(Dentist* newDentist);
  void setPatient(Patient* newPatient);

  //Public getter methods.
  Room* getRoom() const;
  std::chrono::system_clock::time_point getDate() const;
  Dentist* getDentist() const;
  Patient* getPatient() const;
  bool getIsFree() const;
};

#endif // APPOINTMENT_H
