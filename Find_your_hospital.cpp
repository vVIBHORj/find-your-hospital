#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Hospital {
    std::string name;
    std::string state;
    std::string city;
    std::string localAddress;
    std::string pincode;
};



std::vector<Hospital> readHospitalData(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Hospital> hospitals;
    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        Hospital hospital;

        std::getline(ss, field, ',');

        std::getline(ss, hospital.name, ',');
        std::getline(ss, hospital.state, ',');
        std::getline(ss, hospital.city, ',');
        std::getline(ss, hospital.localAddress, ',');
        std::getline(ss, hospital.pincode, ',');

        hospitals.push_back(hospital);
    }

    return hospitals;
}

std::string findHospital(const std::vector<Hospital>& hospitals, const std::string& city, const std::string& localAddress) {
    for (const auto& hospital : hospitals) {
        if (hospital.city == city && hospital.localAddress == localAddress) {
            return hospital.name;
        }
    }

    return "Hospital not found.";
}

int main() {
    const std::string filename = "HospitalsInIndia.csv";
    std::vector<Hospital> hospitals = readHospitalData(filename);

    std::string city, localAddress;
    std::cout << "Enter the city: ";
    std::getline(std::cin, city);
    std::cout << "Enter the local address: ";
    std::getline(std::cin, localAddress);

    std::string hospitalName = findHospital(hospitals, city, localAddress);
    std::cout << "Hospital Name: " << hospitalName << std::endl;

    string name;
    string date;
    string time;

    cout << "Enter the date of appointment: ";
    cin >> date;

    cout << "Enter the time of appointment: ";
    cin >> time;

    cout << "Enter the preferred doctor name: ";
    cin >> name;


    std::ofstream appointmentFile("appointment.txt", std::ios::app); // Open the file in append mode
    if (appointmentFile.is_open()) {
        appointmentFile << "Date: " << date << ", Time: " << time << ", Name: " << name << "\n";
        appointmentFile.close();
        cout << "Appointment information saved to 'appointment.txt'." << endl;
    } else {
        cout << "Failed to open the file for saving appointment information." << endl;
    }

    return 0;
}
