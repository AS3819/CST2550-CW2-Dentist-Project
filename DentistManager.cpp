#include "DentistManager.h"
#include "Print_Functions.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "Input_Validation.h"

void DentistManager::addNewDentist() {
    std::string title, firstName, surname, email, address, salaryStr;
    int dentistId = data->getMaxDentistID() + 1;
    int salary;

    println("Adding new dentist with ID: " + std::to_string(dentistId));

    if (!getInput("Enter First Name: (Or 0 to cancel) ", firstName) ||
        !getInput("Enter Surname: (Or 0 to cancel) ", surname) ||
        !getInput("Enter Address: (Or 0 to cancel) ", address) ||
        !getInput("Enter Email: (Or 0 to cancel) ", email)) {
        return;
    }
    
    println("Enter Salary: (Or 0 to cancel) ");
    std::getline(std::cin, salaryStr);
    if (salaryStr == "0") {
        println("Operation cancelled by user.");
        return;
    }
    try {
        salary = std::stoi(salaryStr);
    } catch (const std::invalid_argument& ia) {
        println("Invalid input for salary. Please enter a numeric value.");
        return; 
    } catch (const std::out_of_range& oor) {
        println("The number you entered is too large.");
        return;
    }

    title = "Dr.";

    Dentist newDentist(title, firstName, surname, address, email, dentistId, salary);
    data->addDentist(newDentist);
    saveDentistsToCSV();
}

void DentistManager::saveDentistsToCSV() {
    std::ofstream outFile("dentists.csv");
    outFile << "Dentist ID,Title,First Name,Surname,Address,E-Mail Address,Salary\n";

    const auto& dentists = data->getDentists();
    for (const auto& dentist : dentists) {
        outFile << dentist.getDentistID() << ","
                << dentist.getTitle() << ","
                << dentist.getFirstName() << ","
                << dentist.getSurname() << ","
                << dentist.getAddress() << ","
                << dentist.getEmail() << ","
                << dentist.getSalary() << "\n";
    }

    outFile.close();
}

Dentist* DentistManager::findOrCreateDentist(const std::string& name) {
    for (auto* dentist : dentists) {
        if (dentist->getFirstName() + " " + dentist->getSurname() == name) {
            return dentist;
        }
    }
    auto* newDentist = new Dentist("Dr.", name, "", "", "", dentists.size() + 1, 0);
    dentists.push_back(newDentist);
    return newDentist;
}

DentistManager::~DentistManager() {
    for (auto* dentist : dentists) {
        delete dentist;
    }
}
