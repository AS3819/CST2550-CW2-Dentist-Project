#ifndef INTERFACE_H
#define INTERFACE_H

#include "Calendar.h"

class Interface {
 private:
  Calendar calendar;
  std::string userInput = "";
  std::string menuOptions[2][5] = {
    {"1) Display", "2) Book", "3) Date", "4) Exit"},
    {"1) Dentist", "2) Patient", "3) Appointment", "4) Room", "5) Return"}
  };
 public:
  void printMenu(short int menu);
  void mainMenu();
  void displayMenu();
  void bookMenu();
};

#endif
