#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Dentist.h"
#include "Patient.h"
#include "Room.h"
#include "Appointment.h"
#include "Print_Functions.h"
#include <chrono>

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

TEST_CASE("patient1", "[patient1]")
{
  REQUIRE(patient1.getPatientID() == 1);
  REQUIRE(patient1.getTitle() == "Mr.");
  REQUIRE(patient1.getFirstName() == "John");
  REQUIRE(patient1.getSurname() == "Smith");
  REQUIRE(patient1.getAddress() == "address1");
  REQUIRE(patient1.getEmail() == "email1");
}

TEST_CASE("patient2", "[patient2]")
{
  REQUIRE(patient2.getPatientID() == 2);
  REQUIRE(patient2.getTitle() == "Mr.");
  REQUIRE(patient2.getFirstName() == "Aaron");
  REQUIRE(patient2.getSurname() == "Carter");
  REQUIRE(patient2.getAddress() == "address2");
  REQUIRE(patient2.getEmail() == "email2");
}

TEST_CASE("patient3", "[patient3]")
{
  REQUIRE(patient3.getPatientID() == 3);
  REQUIRE(patient3.getTitle() == "Mr.");
  REQUIRE(patient3.getFirstName() == "Brian");
  REQUIRE(patient3.getSurname() == "Turner");
  REQUIRE(patient3.getAddress() == "address3");
  REQUIRE(patient3.getEmail() == "email3");
}

TEST_CASE("patient4", "[patient4]")
{
  REQUIRE(patient4.getPatientID() == 4);
  REQUIRE(patient4.getTitle() == "Mr.");
  REQUIRE(patient4.getFirstName() == "David");
  REQUIRE(patient4.getSurname() == "Grey");
  REQUIRE(patient4.getAddress() == "address4");
  REQUIRE(patient4.getEmail() == "email4");
}

TEST_CASE("patient5", "[patient5]")
{
  REQUIRE(patient5.getPatientID() == 5);
  REQUIRE(patient5.getTitle() == "Mr.");
  REQUIRE(patient5.getFirstName() == "Gordon");
  REQUIRE(patient5.getSurname() == "Pike");
  REQUIRE(patient5.getAddress() == "address5");
  REQUIRE(patient5.getEmail() == "email5");
}

TEST_CASE("room1", "[room1]")
{
  REQUIRE(room1.getID() == 1);
}

TEST_CASE("room2", "[room2]")
{
  REQUIRE(room1.getID() == 2);
}

TEST_CASE("room3", "[room3]")
{
  REQUIRE(room1.getID() == 3);
}
