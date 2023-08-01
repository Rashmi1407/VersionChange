#include <iostream>
#include <fstream>
#include <string>

std::string incrementVersion(const std::string& version) {
    int major, minor, patch;
    sscanf(version.c_str(), "%d.%d.%d", &major, &minor, &patch);
    patch++;
    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

int main() {
    std::ifstream file("file2.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file2.txt" << std::endl;
        return 1;
    }

    std::string version;
    std::getline(file, version);
    file.close();

    std::string newVersion = incrementVersion(version);

    std::ofstream outFile("file2.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening file2.txt for writing" << std::endl;
        return 1;
    }

    outFile << newVersion;
    outFile.close();

    std::cout << "Updated version: " << newVersion << std::endl;

    return 0;
}
