﻿#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(std::string city, std::string street, int houseNumber, int apartmentNumber)
       : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}
    
    Address() {}

    std::string getOutputAddress() {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    int n;
    inputFile >> n;

    Address* addresses = new Address[n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int houseNumber, apartmentNumber;
        inputFile >> city >> street >> houseNumber >> apartmentNumber;
        addresses[i] = Address(city, street, houseNumber, apartmentNumber);
    }

    outputFile << n << "\n";
    for (int i = n - 1; i >= 0; i--) {
        outputFile << addresses[i].getOutputAddress() << "\n";
    }

    delete[] addresses;

    return 0;
}
