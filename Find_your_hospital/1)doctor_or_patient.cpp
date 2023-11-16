#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Patient {
    string name;
    string address;
    string age;
    string gender;
};

void savePatientDetails(const Patient& patient) {
    ofstream file("patient_details.txt", ios::app);
    if (file.is_open()) {
        file << "Name: " << patient.name << endl;
        file << "Address: " << patient.address << endl;
        file << "age: " << patient.age << endl;
        file << "Gender: " << patient.gender << endl;
        file << endl;
        file.close();
        cout << "Patient details saved successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    string userType;
    cout << "Are you a doctor or a patient? ";
    cin >> userType;

    if (userType == "patient") {
    
            Patient patient;
            cout << "Name: ";
            cin >> patient.name;
            cout << "Address: ";
            cin >> patient.address;
            cout << "age: ";
            cin >> patient.age;
            cout << "Gender: ";
            cin >> patient.gender;

            savePatientDetails(patient);
        }
     else if (userType == "doctor") {
        string age;
        string locality;

        cout << "Enter the type of diseass: ";
        cin >> age;
        cout << "Medicine prescribied ";
        cin >> locality;

        Patient patient;
        patient.age = age;
        patient.address = locality;

        savePatientDetails(patient);
    } else {
        cout << "Invalid user type. Please enter either 'doctor' or 'patient'." << endl;
    }

    return 0;
}