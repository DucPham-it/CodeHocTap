#include  <iostream>
#include <vector>
using namespace std;

#include <vector>
using namespace std;

void longestAscending(vector<double> *a, int &start, int &end) {
    int n = a->size();
    if (n < 2) {
        start = 0;
        end = 0;
        return;
    }

    int currentStart = 0; 
    int maxLength = 1;    
    start = 0;
    end = 0;

    for (int i = 2; i < n; ++i) {
        if ((*a)[i] - (*a)[i-1] == (*a)[i-1] - (*a)[i-2]) {
            if (i - currentStart + 1 >= maxLength) {
                maxLength = i - currentStart + 1;
                start = currentStart;
                end = i;
            }
        } else {
            currentStart = i - 1; 
        }
    }
}

void inputMark(vector<double> *&a){
    int size;
    cout  << "Number Semester: ";
    cin >> size;
    a= new vector <double>(size);

    for (int i=0; i<a->size(); i++){
        cout << "Semester " <<  i << " : ";
        cin >> (*a)[i];
    }
}

int main(){
    vector <double> *markSemester = nullptr;
    inputMark(markSemester);

    int start = -1;
    int end = -1;
    longestAscending(markSemester,start, end);
    cout << "Start = "  << start << endl;
    cout << "End = "  << end << endl;

    delete markSemester;
    return 0;
}