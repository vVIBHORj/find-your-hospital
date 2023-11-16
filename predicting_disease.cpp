#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Disease {
    std::string name;
    double temperature;
    int bloodPressure;
    int heartRate;
    int sugarLevel;
    std::vector<std::string> medicines;
    std::vector<std::string> precautions;
};
int t=98.6;
int bp=120;
int hr=70;
int sl=80;


std::vector<Disease> initializeDiseases() {
    std::vector<Disease> diseases;

    // Disease 1: Common Cold
    Disease cold;
    cold.name = "Common Cold";
    cold.temperature = 98.6; // Normal body temperature
    cold.bloodPressure = 120; // Normal blood pressure
    cold.heartRate = 70; // Normal heart rate
    cold.sugarLevel = 80; // Normal sugar level
    cold.medicines = { "Pain relievers", "Decongestants" };
    cold.precautions = { "Drink plenty of fluids", "Get plenty of rest" };
    diseases.push_back(cold);

    // Disease 2: Hypertension (High Blood Pressure)
    Disease hypertension;
    hypertension.name = "Hypertension";
    hypertension.temperature = 98.6; // Normal body temperature
    hypertension.bloodPressure = 140; // High blood pressure
    hypertension.heartRate = 70; // Normal heart rate
    hypertension.sugarLevel = 80; // Normal sugar level
    hypertension.medicines = { "Antihypertensive medications" };
    hypertension.precautions = { "Maintain a healthy diet", "Exercise regularly" };
    diseases.push_back(hypertension);

    Disease diabetes;
    diabetes.name = "Diabetes";
    diabetes.temperature = 98.6; // Normal body temperature
    diabetes.bloodPressure = 120; // Normal blood pressure
    diabetes.heartRate = 70; // Normal heart rate
    diabetes.sugarLevel = 200; // High sugar level
    diabetes.medicines = { "Insulin", "Oral medications" };
    diabetes.precautions = { "Monitor blood sugar levels regularly", "Follow a healthy diet" };
    diseases.push_back(diabetes);

    // Disease 4: Asthma
    Disease asthma;
    asthma.name = "Asthma";
    asthma.temperature = 98.6; // Normal body temperature
    asthma.bloodPressure = 120; // Normal blood pressure
    asthma.heartRate = 70; // Normal heart rate
    asthma.sugarLevel = 80; // Normal sugar level
    asthma.medicines = { "Bronchodilators", "Inhaled corticosteroids" };
    asthma.precautions = { "Avoid triggers like smoke and allergens", "Use inhalers as prescribed" };
    diseases.push_back(asthma);

    // Disease 5: Migraine
    Disease migraine;
    migraine.name = "Migraine";
    migraine.temperature = 98.6; // Normal body temperature
    migraine.bloodPressure = 120; // Normal blood pressure
    migraine.heartRate = 70; // Normal heart rate
    migraine.sugarLevel = 80; // Normal sugar level
    migraine.medicines = { "Pain relievers", "Triptans" };
    migraine.precautions = { "Identify triggers and avoid them", "Get enough sleep" };
    diseases.push_back(migraine);

    // Disease 6: Allergies
    Disease allergies;
    allergies.name = "Allergies";
    allergies.temperature = 98.6; // Normal body temperature
    allergies.bloodPressure = 120; // Normal blood pressure
    allergies.heartRate = 70; // Normal heart rate
    allergies.sugarLevel = 80; // Normal sugar level
    allergies.medicines = { "Antihistamines", "Nasal sprays" };
    allergies.precautions = { "Avoid allergens", "Keep the environment clean" };
    diseases.push_back(allergies);

    // Disease 7: Arthritis
    Disease arthritis;
    arthritis.name = "Arthritis";
    arthritis.temperature = 98.6; // Normal body temperature
    arthritis.bloodPressure = 120; // Normal blood pressure
    arthritis.heartRate = 70; // Normal heart rate
    arthritis.sugarLevel = 80; // Normal sugar level
    arthritis.medicines = { "Nonsteroidal anti-inflammatory drugs (NSAIDs)", "Corticosteroids" };
    arthritis.precautions = { "Exercise regularly", "Maintain a healthy weight" };
    diseases.push_back(arthritis);

    return diseases;
}

std::string predictDisease(const std::vector<Disease>& diseases, double temperature, int bloodPressure, int heartRate, int sugarLevel) {
    for (const auto& disease : diseases) {
        if (temperature != disease.temperature ||
            bloodPressure != disease.bloodPressure ||
            heartRate != disease.heartRate ||
            sugarLevel != disease.sugarLevel) {
            continue;
        }

        return disease.name;
    }

    return "Unknown";
}

void displayMedicines(const std::vector<std::string>& medicines) {
    std::cout << "Medicines: ";
    for (const auto& medicine : medicines) {
        std::cout << medicine << ", ";
    }
    std::cout << std::endl;
}

void displayPrecautions(const std::vector<std::string>& precautions) {
    std::cout << "Precautions: ";
    for (const auto& precaution : precautions) {
        std::cout << precaution << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Disease> diseases = initializeDiseases();

    double temperature;
    int bloodPressure;
    int heartRate;
    int sugarLevel;

    std::cout << "Enter your body temperature: ";
    std::cin >> temperature;

    std::cout << "Enter your blood pressure: ";
    std::cin >> bloodPressure;

    std::cout << "Enter your heart rate: ";
    std::cin >> heartRate;

    std::cout << "Enter your sugar level: ";
    std::cin >> sugarLevel;

    std::string predictedDisease = predictDisease(diseases, temperature, bloodPressure, heartRate, sugarLevel);

    if (predictedDisease != "Unknown") {
        std::cout << "Predicted Disease: " << predictedDisease << std::endl;

        // Find the disease in the diseases vector
        auto it = std::find_if(diseases.begin(), diseases.end(), [&](const Disease& disease) {
            return disease.name == predictedDisease;
        });

        if (it != diseases.end()) {
            displayMedicines(it->medicines);
            displayPrecautions(it->precautions);
        }
    } else {
        std::cout << "Unknown disease. Please consult a doctor." << std::endl;
    }

    return 0;
}