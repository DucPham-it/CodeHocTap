#include <iostream>
#include <string>
#include <map>
#include <vector>

void printUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -i <file>      Input file name" << std::endl;
    std::cout << "  -o <file>      Output file name" << std::endl;
    std::cout << "  -v             Enable verbose mode" << std::endl;
    std::cout << "  -h, --help     Display this help message" << std::endl;
}

int main(int argc, char const *argv[]) {
    std::string programName = argv[0];
    std::string inputFileName;
    std::string outputFileName;
    bool verbose = false;
    
    int i = 1;
    while (i < argc) {
        std::string arg = argv[i++];
        
        if (arg == "-i") {
            if (i < argc) {
                inputFileName = argv[i++];
            } else {
                std::cerr << "Error: -i requires a file name" << std::endl;
                printUsage(programName);
                return 1;
            }
        }
        else if (arg == "-o") {
            if (i < argc) {
                outputFileName = argv[i++];
            } else {
                std::cerr << "Error: -o requires a file name" << std::endl;
                printUsage(programName);
                return 1;
            }
        }
        else if (arg == "-v") {
            verbose = true;
        }
        else if (arg == "-h" || arg == "--help") {
            printUsage(programName);
            return 0;
        }
        else {
            std::cerr << "Unknown option: " << arg << std::endl;
            printUsage(programName);
            return 1;
        }
    }
    
    // Check if required arguments are provided
    if (inputFileName.empty()) {
        std::cerr << "Error: Input file name is required" << std::endl;
        printUsage(programName);
        return 1;
    }
    
    // Display parsed options if verbose
    if (verbose) {
        std::cout << "Input file: " << inputFileName << std::endl;
        if (!outputFileName.empty()) {
            std::cout << "Output file: " << outputFileName << std::endl;
        }
    }
    
    // Your program logic goes here
    std::cout << "Processing file: " << inputFileName << std::endl;
    
    return 0;
}

