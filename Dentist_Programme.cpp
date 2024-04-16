#include <iostream>
#include "Data.h"
#include "CSV_Reader.h"
#include "Interface.h"

int main() {

  Data data;
  CSV_Reader reader(&data);
  Interface interface(&data);

  interface.printMenu(0);
  interface.mainMenu();
  
}
