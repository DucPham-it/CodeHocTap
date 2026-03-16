#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Line {
    int nwords = 0;
    string line;
    Line* nLines = nullptr;
};
struct TFile {
    int nlines = 0;
    Line* lines = nullptr;
};

void readTFile(string nameFile, TFile& output);
void deleteTFile(TFile nameFile);
int numInLine(Line line);
void writeInBynary(string nameFile, TFile input);

int main(int argc, char *argv[]) { 
    string nameFile = argv[1];
    TFile text;

    readTFile(nameFile, text);
    Line* head = text.lines;

    cout << "N lines in fiel: " << text.nlines << "\n";

    while (head != nullptr) {
        cout << head->line << " n wolds in line: "<< head->nwords <<"\n";
        head = head->nLines;
    }

    deleteTFile(text);
    
    return 0; }

int numInLine(Line* line){
    string token;
    int count = 0;
    
    stringstream ss(line->line);

    while (ss >> token){
        count++;
    }
    return count;
}

void readTFile(string nameFile, TFile& output) {
    ifstream input;
    input.open(nameFile);

    if (!input.is_open()) {
        cout << "Can't open file \n";
    }

    string line;
    Line* hold;

    while (getline(input, line)) {
        Line* temp = new Line;
        temp->line = line;
        temp->nwords = numInLine(temp);
        if (output.lines == nullptr) {
            output.lines = temp;
        }
        else {
            hold->nLines = temp;
        }
        output.nlines++;
        hold = temp;
    }
    input.close();
}

void deleteTFile(TFile nameFile){
    Line* head = nameFile.lines;

    while (head->nLines != nullptr) {
        Line* temp = head;
        head = head->nLines;
        delete temp;
    }
}

void writeInBynary(string nameFile, TFile input){
    ofstream output(nameFile, ios::binary);


    if (!output.is_open()) {
        cout << "Can't open file \n";
    }
    Line* head = input->lines;
    
    while (head != nullptr) {
        
        head = head->nLines;
    }
}
