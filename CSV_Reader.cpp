#include "CSV_Reader.h"

//Function for getting lines as inputs while ignoring commas as delimiters if they are withing double quotation marks.

void CSV_Reader::getLineIgnoringQuotes(std::istream& input, std::string& result, char delimiter = ',') {
  
    char character = input.get();
    bool inQuotes = false;

    while (character != delimiter || inQuotes) {
        if (character == '"') {
            inQuotes = !inQuotes;
        } else if (character == delimiter && !inQuotes) {
            return;
        } else {
            result += character;
        }
        character = input.get();
    }
}

/*Functions for reading the data from the CSV files,
 based on the code from this video: https://www.youtube.com/watch?v=NFvxA-57LLA*/

void CSV_Reader::readDentistsFile() {

  std::string line = "";
  
  getline(dentistsFile, line);
  line = "";
  
  while (getline(dentistsFile, line)) {

    std::string dentistID;
    std::string name;
    std::string address;
    std::string email;
    std::string salary;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, dentistID, ',');
    getLineIgnoringQuotes(inputString, title, ',');
    getLineIgnoringQuotes(inputString, firstName, ',');
    getLineIgnoringQuotes(inputString, surname, ',');
    getLineIgnoringQuotes(inputString, address, ',');
    getLineIgnoringQuotes(inputString, email, ',');
    getline(inputString, salary, ' ');

    Dentist newDentist(title, firstName, surname, address, email, stoi(dentistID), stoi(salary));
    data.addDentist(newDentist);
    
    line = "";
  }
  
}

void CSV_Reader::readPatientsFile() {

  std::string line = "";
  
  getline(patientsFile, line);
  line = "";
  
  while (getline(patientsFile, line)) {

    std::string patientID;
    std::string name;
    std::string address;
    std::string email;
    std::string salary;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, patientID, ',');
    getLineIgnoringQuotes(inputString, title, ',');
    getLineIgnoringQuotes(inputString, firstName, ',');
    getLineIgnoringQuotes(inputString, surname, ',');
    getLineIgnoringQuotes(inputString, address, ',');
    getLineIgnoringQuotes(inputString, email, ',');

    Patient newPatient(title, firstName, surname, address, email, stoi(patientID));
    data.addPatient(newPatient);
    
    line = "";
  }
  
}


void CSV_Reader::readRoomsFile() {

  std::string line = "";
  
  getline(roomsFile, line);
  line = "";
  
  while (getline(roomsFile, line)) {

    std::string roomID;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, roomID, ',');

    Room newRoom(stoi(roomID));
    data.addRoom(newRoom);
    
    line = "";
  }
  
}

void CSV_Reader::readAppointmentsFile() {

  std::string line = "";
  
  getline(appointmentsFile, line);
  line = "";
  
  while (getline(appointmentsFile, line)) {

    std::string appointmentID;
    std::string roomID;
    std::string dentistID;
    std::string patientID;
    std::string time;

    std::stringstream inputString(line);

    getLineIgnoringQuotes(inputString, appointmentID, ',');
    getLineIgnoringQuotes(inputString, roomID, ',');
    getLineIgnoringQuotes(inputString, firstName, ',');
    getLineIgnoringQuotes(inputString, dentistID, ',');
    getLineIgnoringQuotes(inputString, time, ',');

    //Appointment newAppointment(appointmentID, firstName, surname, address, email, stoi(dentistID), stoi(salary));
    //data.addAppointment(appointmentID);
    
    line = "";
  }
  
}
