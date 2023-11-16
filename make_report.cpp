#include <iostream>
#include <vector>
#include <string>

struct Patient {
    std::string name;
    int age;
    std::string gender;
    std::string address;
    std::string diagnosis;
    std::string treatment;
    double height;
    double weight;
    std::string bloodType;
    std::string allergies;
};

void savePatientReport(std::vector<Patient>& patientDatabase) {
    Patient patient;

    std::cout << "Enter patient's name: ";
    std::cin.ignore();
    std::getline(std::cin, patient.name);

    std::cout << "Enter patient's age: ";
    std::cin >> patient.age;

    std::cout << "Enter patient's gender: ";
    std::cin.ignore();
    std::getline(std::cin, patient.gender);

    std::cout << "Enter patient's address: ";
    std::cin.ignore();
    std::getline(std::cin, patient.address);

    std::cout << "Enter diagnosis: ";
    std::cin.ignore();
    std::getline(std::cin, patient.diagnosis);

    std::cout << "Enter treatment: ";
    std::cin.ignore();
    std::getline(std::cin, patient.treatment);

    std::cout << "Enter patient's height (in cm): ";
    std::cin >> patient.height;

    std::cout << "Enter patient's weight (in kg): ";
    std::cin >> patient.weight;

    std::cout << "Enter patient's blood type: ";
    std::cin.ignore();
    std::getline(std::cin, patient.bloodType);

    std::cout << "Enter patient's allergies: ";
    std::cin.ignore();
    std::getline(std::cin, patient.allergies);

    patientDatabase.push_back(patient);
    std::cout << "Patient report saved successfully." << std::endl;
}

void displayPatientReports(const std::vector<Patient>& patientDatabase) {
    if (patientDatabase.empty()) {
        std::cout << "No patient reports to display." << std::endl;
    } else {
        std::cout << "Patient Reports:" << std::endl;
        for (const Patient& patient : patientDatabase) {
            std::cout << "Name: " << patient.name << std::endl;
            std::cout << "Age: " << patient.age << std::endl;
            std::cout << "Gender: " << patient.gender << std::endl;
            std::cout << "Address: " << patient.address << std::endl;
            std::cout << "Diagnosis: " << patient.diagnosis << std::endl;
            std::cout << "Treatment: " << patient.treatment << std::endl;
            std::cout << "Height (cm): " << patient.height << std::endl;
            std::cout << "Weight (kg): " << patient.weight << std::endl;
            std::cout << "Blood Type: " << patient.bloodType << std::endl;
            std::cout << "Allergies: " << patient.allergies << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

int main() {
    std::vector<Patient> patientDatabase;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Save Patient Report" << std::endl;
        std::cout << "2. Display Patient Reports" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                savePatientReport(patientDatabase);
                break;
            case 2:
                displayPatientReports(patientDatabase);
                break;
            case 3:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
