#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include "Appointment.h"
#include "Print_Functions.h"
#include <chrono>
#include "AppointmentDisplay.h"
#include "DentistManager.h"
#include "AppointmentManager.h"
#include <fstream>
#include "DateTimeUtils.h"
#include "CSVSearcher.h"



//Declarations.

const auto now = std::chrono::system_clock::now();

Dentist dentist1("Dr.", "Andrew", "Brown", "address1", "email1", 1, 50000);
Dentist dentist2("Dr.", "Thomas", "Green", "address2", "email2", 2, 30000);
Dentist dentist3("Dr.", "Peter", "Yeoman", "address3", "email3", 3, 40000);

Patient patient1("Mr.", "John", "Smith", "address1", "email1", 1);
Patient patient2("Mr.", "Aaron", "Carter", "address2", "email2", 2);
Patient patient3("Mr.", "Brian", "Turner", "address3", "email3", 3);
Patient patient4("Mr.", "David", "Grey", "address4", "email4", 4);
Patient patient5("Mr.", "Gordon", "Pike", "address5", "email5", 5);

Room room1(1);
Room room2(2);
Room room3(3);

Appointment appointment1(1, &room1, now, &dentist1, &patient1);
Appointment appointment2(2, &room2, now, &dentist2, &patient2);
Appointment appointment3(3, &room3, now, &dentist3, &patient3);
Appointment appointment4(4, &room1, now, &dentist1, &patient4);
Appointment appointment5(5, &room2, now, &dentist2, &patient5);

//Test Cases.

TEST_CASE("dentist1", "[dentist1]")
{
  REQUIRE(dentist1.getDentistID() == 1);
  REQUIRE(dentist1.getTitle() == "Dr.");
  REQUIRE(dentist1.getFirstName() == "Andrew");
  REQUIRE(dentist1.getSurname() == "Brown");
  REQUIRE(dentist1.getAddress() == "address1");
  REQUIRE(dentist1.getEmail() == "email1");
  REQUIRE(dentist1.getSalary() == 50000);
}

TEST_CASE("dentist2", "[dentist2]")
{
  REQUIRE(dentist2.getDentistID() == 2);
  REQUIRE(dentist2.getTitle() == "Dr.");
  REQUIRE(dentist2.getFirstName() == "Thomas");
  REQUIRE(dentist2.getSurname() == "Green");
  REQUIRE(dentist2.getAddress() == "address2");
  REQUIRE(dentist2.getEmail() == "email2");
  REQUIRE(dentist2.getSalary() == 30000);
}

TEST_CASE("dentist3", "[dentist3]")
{
  REQUIRE(dentist3.getDentistID() == 3);
  REQUIRE(dentist3.getTitle() == "Dr.");
  REQUIRE(dentist3.getFirstName() == "Peter");
  REQUIRE(dentist3.getSurname() == "Yeoman");
  REQUIRE(dentist3.getAddress() == "address3");
  REQUIRE(dentist3.getEmail() == "email3");
  REQUIRE(dentist3.getSalary() == 40000);
}


TEST_CASE("Patient Initialization") {
    SECTION("Patient1 Initialization") {
        REQUIRE(patient1.getPatientID() == 1);
        REQUIRE(patient1.getTitle() == "Mr.");
        REQUIRE(patient1.getFirstName() == "John");
        REQUIRE(patient1.getSurname() == "Smith");
        REQUIRE(patient1.getAddress() == "address1");
        REQUIRE(patient1.getEmail() == "email1");
    }

    SECTION("Patient2 Initialization") {
        REQUIRE(patient2.getPatientID() == 2);
        REQUIRE(patient2.getTitle() == "Mr.");
        REQUIRE(patient2.getFirstName() == "Aaron");
        REQUIRE(patient2.getSurname() == "Carter");
        REQUIRE(patient2.getAddress() == "address2");
        REQUIRE(patient2.getEmail() == "email2");
    }
}

TEST_CASE("Appointment Initialization") {
    SECTION("Appointment1 Initialization") {
        REQUIRE(appointment1.getID() == 1);
        REQUIRE(appointment1.getRoom() == &room1);
        REQUIRE(appointment1.getDate() == now);
        REQUIRE(appointment1.getDentist() == &dentist1);
        REQUIRE(appointment1.getPatient() == &patient1);
    }

    SECTION("Appointment2 Initialization") {
        REQUIRE(appointment2.getID() == 2);
        REQUIRE(appointment2.getRoom() == &room2);
        REQUIRE(appointment2.getDate() == now);
        REQUIRE(appointment2.getDentist() == &dentist2);
        REQUIRE(appointment2.getPatient() == &patient2);
    }


}

TEST_CASE("Appointment Creation with Invalid Parameters") {
    SECTION("Appointment Creation with nullptr Dentist") {
        Dentist* dentist = nullptr;
        REQUIRE_THROWS_WITH(Appointment(6, &room1, now, dentist),
                            Catch::Contains("Invalid dentist"));
    }

    SECTION("Appointment Creation with nullptr Patient") {
        Patient* patient = nullptr;
        REQUIRE_THROWS_WITH(Appointment(7, &room1, now, &dentist1, patient),
                            Catch::Contains("Invalid patient"));
    }
}

TEST_CASE("Appointment Display Formatting") {
    std::ostringstream output;
    std::vector<Appointment> appointments = {appointment1, appointment2, appointment3};

    SECTION("Display with Non-Empty Appointment List") {
        AppointmentDisplay::displayAppointments(appointments);
        // Verify the output format
        std::string expectedOutput = "Appointments:\n";
        expectedOutput += "Date           Time      Dentist           Room   Availability\n";
        expectedOutput += "----------------------------------------------------------\n";
        // Add expected formatted appointment data
        // You need to format the expected output based on the appointments vector
        // Example: expectedOutput += "2024-04-25     10:00     Dr. Andrew Brown     1     Booked\n";
        // Add more lines for each appointment in the vector
        REQUIRE(output.str() == expectedOutput);
    }

    SECTION("Display with Empty Appointment List") {
        std::vector<Appointment> emptyAppointments;
        AppointmentDisplay::displayAppointments(emptyAppointments);
        std::string expectedOutput = "Appointments:\n";
        expectedOutput += "Date           Time      Dentist           Room   Availability\n";
        expectedOutput += "----------------------------------------------------------\n";
        expectedOutput += "No appointments\n";
        REQUIRE(output.str() == expectedOutput);
    }
}

TEST_CASE("populateAppointmentsFromCSV Function") {
    DentistManager dentistManager;
    dentistManager.populateDentistsFromCSV("dentists.csv"); // Populate dentist data from CSV

    SECTION("Test with Empty CSV File") {
        std::vector<Appointment> appointments;
        AppointmentManager appointmentManager(dentistManager);
        appointmentManager.populateAppointmentsFromCSV("empty.csv", appointments);
        REQUIRE(appointments.empty());
    }

    SECTION("Test with CSV File with Valid Data") {
        std::vector<Appointment> appointments;
        AppointmentManager appointmentManager(dentistManager);
        appointmentManager.populateAppointmentsFromCSV("appointments.csv", appointments);
        // Add assertions based on the appointments vector content
        // Example: REQUIRE(appointments.size() == expectedSize);
    }

    SECTION("Test with CSV File with Invalid Data") {
        std::vector<Appointment> appointments;
        AppointmentManager appointmentManager(dentistManager);
        appointmentManager.populateAppointmentsFromCSV("invalid_appointments.csv", appointments);
        // Add assertions based on the appointments vector content
        // Example: REQUIRE(appointments.empty());
    }

    SECTION("Test with Empty Appointments Vector") {
        std::vector<Appointment> appointments;
        AppointmentManager appointmentManager(dentistManager);
        appointmentManager.populateAppointmentsFromCSV("appointments.csv", appointments);
        // Add assertions based on the appointments vector content
        // Example: REQUIRE(appointments.size() == expectedSize);
    }

    SECTION("Test with Non-Empty Appointments Vector") {
        std::vector<Appointment> appointments = {appointment1, appointment2};
        AppointmentManager appointmentManager(dentistManager);
        appointmentManager.populateAppointmentsFromCSV("appointments.csv", appointments);
        // Add assertions based on the appointments vector content
        // Example: REQUIRE(appointments.size() == expectedSize);
    }
}

TEST_CASE("Dentist Manager Initialization") {
    DentistManager dentistManager;

    SECTION("Test Empty Initialization") {
        REQUIRE(dentistManager.getDentists().empty());
    }
}

TEST_CASE("Adding Dentists to Dentist Manager") {
    DentistManager dentistManager;
    Dentist dentist1("Dr.", "John", "Smith", "address1", "email1", 1, 50000);

    SECTION("Test Adding Single Dentist") {
        dentistManager.addDentist(dentist1);
        REQUIRE(dentistManager.getDentists().size() == 1);
        REQUIRE(dentistManager.getDentists()[0] == dentist1);
    }

    // Add more test cases for adding multiple dentists, etc.
}

TEST_CASE("Retrieving Dentists from Dentist Manager") {
    DentistManager dentistManager;
    Dentist dentist1("Dr.", "John", "Smith", "address1", "email1", 1, 50000);
    Dentist dentist2("Dr.", "Jane", "Doe", "address2", "email2", 2, 60000);

    dentistManager.addDentist(dentist1);
    dentistManager.addDentist(dentist2);

    SECTION("Test Retrieving Dentist by ID") {
        REQUIRE(dentistManager.getDentistByID(1) == dentist1);
        REQUIRE(dentistManager.getDentistByID(2) == dentist2);
        REQUIRE(dentistManager.getDentistByID(3).getFirstName() == ""); // Non-existent ID
    }

    SECTION("Test Retrieving Dentist by Name") {
        REQUIRE(dentistManager.getDentistsByName("John").size() == 1);
        REQUIRE(dentistManager.getDentistsByName("Jane").size() == 1);
        REQUIRE(dentistManager.getDentistsByName("John")[0] == dentist1);
        REQUIRE(dentistManager.getDentistsByName("Jane")[0] == dentist2);
        REQUIRE(dentistManager.getDentistsByName("Jack").empty()); // Non-existent name
    }
}


TEST_CASE("Reading CSV Files") {
    CSVSearcher searcher;

    SECTION("Test Reading Valid CSV File") {
        std::string filename = "valid.csv";
        auto data = searcher.readCSV(filename);

        // Add assertions to check the correctness of data from a valid CSV file
    }

    SECTION("Test Reading Empty CSV File") {
        std::string filename = "empty.csv";
        auto data = searcher.readCSV(filename);

        REQUIRE(data.empty());
    }

    SECTION("Test Reading Non-existent CSV File") {
        std::string filename = "nonexistent.csv";
        auto data = searcher.readCSV(filename);

        REQUIRE(data.empty());
    }

}

TEST_CASE("DateTimeUtils Test Cases") {
    SECTION("Test Parsing Date/Time Strings") {
        std::string dateStr = "2022-04-30";
        std::string timeStr = "13:45";
        std::string dateTimeStr = dateStr + " " + timeStr;

        auto dateTime = parseDateTime(dateTimeStr);

        // Add assertions to check if dateTime is correctly parsed
        // For example:
        REQUIRE(dateTime.time_since_epoch().count() != 0); // Check if dateTime is valid
    }

}


TEST_CASE("Input Validation Test Cases") {
    SECTION("Test Integer Validation") {
        // Valid integer input
        REQUIRE(validateIntegerInput("123") == true);
        // Invalid integer input (non-numeric characters)
        REQUIRE(validateIntegerInput("abc") == false);
        // Invalid integer input (empty string)
        REQUIRE(validateIntegerInput("") == false);
        // Boundary case: maximum integer value
        REQUIRE(validateIntegerInput(std::to_string(std::numeric_limits<int>::max())) == true);
        // Boundary case: minimum integer value
        REQUIRE(validateIntegerInput(std::to_string(std::numeric_limits<int>::min())) == true);
    }

    SECTION("Test Double Validation") {
        // Valid double input
        REQUIRE(validateDoubleInput("123.45") == true);
        // Invalid double input (non-numeric characters)
        REQUIRE(validateDoubleInput("abc") == false);
        // Invalid double input (empty string)
        REQUIRE(validateDoubleInput("") == false);
        // Boundary case: maximum double value
        REQUIRE(validateDoubleInput(std::to_string(std::numeric_limits<double>::max())) == true);
        // Boundary case: minimum double value
        REQUIRE(validateDoubleInput(std::to_string(std::numeric_limits<double>::min())) == true);
    }

    // Add more test cases to cover other input validation functions and scenarios
}


TEST_CASE("Integration Test Cases") {
SECTION("Test Appointment Creation, Display, and Management") {
// Initialize Dentist Manager
DentistManager dentistManager;
// Initialize Appointment Manager with Dentist Manager reference
AppointmentManager appointmentManager(dentistManager);

// Populate Dentist Manager from dentists.csv
dentistManager.populateDentistsFromCSV("dentists.csv");

// Create Appointments from appointments.csv
std::vector<Appointment> appointments;
appointmentManager.populateAppointmentsFromCSV("appointments.csv", appointments);

// Test Displaying Appointments
AppointmentDisplay::displayAppointments(appointments);

// Verify Appointments were created and displayed correctly
REQUIRE(appointments.size() > 0);
}

SECTION("Test CSV File Reading and Parsing") {
CSVSearcher searcher;
// Test reading appointments.csv
auto appointmentsData = searcher.readCSV("appointments.csv");
// Verify appointments.csv was read correctly
REQUIRE(appointmentsData.size() > 0);

// Test reading dentists.csv
auto dentistsData = searcher.readCSV("dentists.csv");
// Verify dentists.csv was read correctly
REQUIRE(dentistsData.size() > 0);

// Test reading patients.csv
auto patientsData = searcher.readCSV("patients.csv");
// Verify patients.csv was read correctly
REQUIRE(patientsData.size() > 0);

// Test reading rooms.csv
auto roomsData = searcher.readCSV("rooms.csv");
// Verify rooms.csv was read correctly
REQUIRE(roomsData.size() > 0);
}

SECTION("Test DateTime Parsing") {
// Test parsing date/time strings
auto dateTime = parseDateTime("2024-04-28", "10:30");
// Verify date/time string was parsed correctly
REQUIRE(dateTime.time_since_epoch().count() > 0);
}

SECTION("Test Input Validation") {
// Test valid integer input
REQUIRE(validateIntegerInput("123") == true);
// Test invalid integer input
REQUIRE(validateIntegerInput("abc") == false);

// Test valid double input
REQUIRE(validateDoubleInput("123.45") == true);
// Test invalid double input
REQUIRE(validateDoubleInput("abc") == false);
}

}
