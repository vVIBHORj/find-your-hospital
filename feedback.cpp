#include <iostream>
#include <fstream>
#include <string>

struct Feedback {
    std::string patientName;
    std::string hospitalName;
    std::string doctorName;
    std::string feedbackText;
};

void leaveFeedback() {
    Feedback feedback;
    std::cout << "Patient Name: ";
    std::cin.ignore();
    std::getline(std::cin, feedback.patientName);
    std::cout << "Hospital Name: ";
    std::getline(std::cin, feedback.hospitalName);
    std::cout << "Doctor Name: ";
    std::getline(std::cin, feedback.doctorName);
    std::cout << "Feedback: ";
    std::getline(std::cin, feedback.feedbackText);

    std::ofstream outFile("feedback.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Patient: " << feedback.patientName << std::endl;
        outFile << "Hospital: " << feedback.hospitalName << std::endl;
        outFile << "Doctor: " << feedback.doctorName << std::endl;
        outFile << "Feedback: " << feedback.feedbackText << std::endl;
        outFile << "----------------------------------" << std::endl;
        outFile.close();
        std::cout << "Thank you for your feedback!" << std::endl;
    } else {
        std::cerr << "Error: Unable to save feedback." << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "Patient Review and Feedback System" << std::endl;
        std::cout << "1. Leave Feedback" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                leaveFeedback();
                break;
            case 2:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 2);

    return 0;
}