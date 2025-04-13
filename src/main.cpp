#include <iostream>
#include <string>
#include <cstdlib>   // For rand()
#include <ctime>     // For seeding random generator

struct Plant {
    std::string name;
    float idealPHMin;
    float idealPHMax;
    float idealWaterLevel;
};

// Simulate pH reading (range: 4.5 to 8.0)
float simulatePH() {
    return 4.5f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (8.0f - 4.5f)));
}

// Simulate water level reading (range: 50% to 100%)
float simulateWaterLevel() {
    return 50.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 50.0f));
}

void checkPlantStatus(const Plant& plant, float currentPH, float currentWater) {
    std::cout << "\nChecking plant: " << plant.name << std::endl;
    std::cout << "Current pH: " << currentPH << ", Ideal pH: " 
              << plant.idealPHMin << "-" << plant.idealPHMax << std::endl;

    if (currentPH < plant.idealPHMin || currentPH > plant.idealPHMax) {
        std::cout << "⚠️  ALERT: pH out of range!" << std::endl;
    } else {
        std::cout << "✅ pH is within range." << std::endl;
    }

    std::cout << "Current Water Level: " << currentWater << "%, Ideal: " 
              << plant.idealWaterLevel << "%" << std::endl;

    if (currentWater < plant.idealWaterLevel) {
        std::cout << "⚠️  ALERT: Water level too low!" << std::endl;
    } else {
        std::cout << "✅ Water level is OK." << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random generator

    Plant plants[5] = {
        {"Lettuce", 5.5, 6.5, 70.0},
        {"Tomato", 5.8, 6.8, 80.0},
        {"Basil", 6.0, 7.0, 60.0},
        {"Spinach", 6.0, 7.5, 75.0},
        {"Cucumber", 5.5, 6.0, 85.0}
    };

    for (const auto& plant : plants) {
        float currentPH = simulatePH();
        float currentWater = simulateWaterLevel();
        checkPlantStatus(plant, currentPH, currentWater);
    }

    return 0;
}
