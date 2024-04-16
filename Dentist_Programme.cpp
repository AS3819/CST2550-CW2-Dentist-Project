#include <iostream>
#include "Data.h"
#include "CSV_Reader.h"
#include "Interface.h"
#include "View.h"
#include "Print_Functions.h"

int main() {

  Data data;
  CSV_Reader reader(&data);
  Interface interface(&data);
  View view(&data);

  println("Would you like to use the default .csv files?");
  reader.fileSelection();
  view.printDentists();
  view.printPatients();
  view.printRooms();
  view.printAppointments();
  interface.printMenu(0);
  interface.mainMenu();
  
}
