#include "QuickSort.h"
#include "Dentist.h"
#include "Patient.h"
#include "CSVSearcher.h"
#include "Appointment.h"
#include <vector>
#include <chrono>
#include <iostream>
#include "AppointmentDisplay.h"

int main()
{
    QuickSort sorter;
    // Create instances of Dentist and Patient
    Dentist drSmith("Dr", "Smith", "Smith", "add", "emai", 101, 50000);
    Patient johnDoe("Mr", "John", "Doe", "add", "emai", 202);

    // Display initial details
    std::cout << "Dentist: " << drSmith.getFirstName() << ", ID: " << drSmith.getDentistID() << ", Salary: $" << drSmith.getSalary() << std::endl;
    std::cout << "Patient: " << johnDoe.getFirstName() << ", ID: " << johnDoe.getPatientID() << std::endl;

    // Create appointments
    std::vector<Appointment> appointments;
    appointments.push_back(Appointment(1, std::chrono::system_clock::now() - std::chrono::hours(24), &drSmith));
    appointments.push_back(Appointment(2, std::chrono::system_clock::now() + std::chrono::hours(14), &drSmith));
    appointments.push_back(Appointment(3, std::chrono::system_clock::now() + std::chrono::hours(24), &drSmith));

    // Sort and print appointments
    sorter.sortAppointments(appointments);

    // Example set patient to room 2 appointment.
    for (Appointment &appt : appointments)
    {
        if (appt.getRoom() == 2)
        {
            appt.setPatient(&johnDoe);
            break;
        }
    }

    // Sort and print appointments after setting appointment
    // Output now shows room 2 is booked, so booking system working and sorting system working.
    sorter.sortAppointments(appointments);
    
    std::cout << "" << std::endl;
    
    CSVSearcher searcher;
    std::string filename = "dentist_office.csv";
    // Example searching for a room
    searcher.searchInCSV(filename, "101", "Room");
    // Example searching for a dentist by name
    searcher.searchInCSV(filename, "Dr. Smith", "Dentist");
    
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    
    AppointmentDisplay::displayAvailableAppointments(appointments);


    return 0;
}
