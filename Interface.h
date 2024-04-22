#ifndef INTERFACE_H
#define INTERFACE_H

#include "Data.h"
#include "Calendar.h"
#include "View.h"
#include "Book.h"
#include "PatientManager.h"
#include "DentistManager.h"

class Interface {
 private:
  Data* data;
  PatientManager* patientManager;
  DentistManager* dentistManager;
  Calendar calendar;
  View view;
  Book book;
  std::string userInput = "";
  std::string menuOptions[2][7] = {
    {"1) Display", "2) Book", "3) Date", "4) Add Patient", "5) Add Dentist", "6) Exit"},
    {"1) Dentist", "2) Patient", "3) Appointment", "4) Room", "5) Return"}
  };
 public:
  Interface(Data* d, View& v, Book& b) : data(d), view(v), book(b) {
    patientManager = new PatientManager(d);
    dentistManager = new DentistManager(d);
  }
  ~Interface() {
      delete patientManager;
      delete dentistManager;
  }
  void printMenu(short int menu);
  void mainMenu();
  void displayMenu();
  void bookMenu();
};

#endif
