#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <sstream>
#include "Data.h"
#include "Dentist.h"
#include "Patient.h"
#include "Appointment.h"

class CSV_Reader {
 private:
  Data data;
  std::string dentistsFile;
  std::string patientsFile;
  std::string roomsFile;
  std::string appointmentsFile;
  void  getLineIgnoringQuotes(std::istream& input, std::string& result, char delimiter = ',');
 public:
  CSV_Reader(Data d) {
    data = d;
  }
  void readDentistsFile();
  void readPatientsFile();
  void readRoomsFile();
  void readAppointmentsFile();
  void fileSelection();
};

#endif
