#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Point{
    double x,y;
};

struct Triangle{
    int type=0;
    Point A, B, C;
};

struct Circle{
    int type=1;
    Point I;
    double radius;
};

void read(struct Triangle Tri[], int& n1, struct Circle Cir[], int& n2){
    ifstream in("SHAPES.TXT");
    if (!in.is_open()) {
        cout << "FAILED" << endl;
        return;
    }

    n1=0;
    n2=0;
    
    char line[100];
        while (in.peek()!=EOF) {
        in.getline(line, 100);
        char* token = strtok(line, "[(,)] ");
        if (atof(token) == 0) { 
            Tri[n1].A.x = atof(strtok(NULL, "(,)] "));
            Tri[n1].A.y = atof(strtok(NULL, "(,)] "));
            Tri[n1].B.x = atof(strtok(NULL, "(,)] "));
            Tri[n1].B.y = atof(strtok(NULL, "(,)] "));
            Tri[n1].C.x = atof(strtok(NULL, "(,)] "));
            Tri[n1].C.y = atof(strtok(NULL, "(,)] "));  
            n1++;       
        } 
        else if (atof(token) == 1) {          
            Cir[n2].I.x = atof(strtok(NULL, "(,)] "));
            Cir[n2].I.y = atof(strtok(NULL, "(,)] "));
            Cir[n2].radius = atof(strtok(NULL, "(,)] ")); 
            n2++;          
        }
    }

    in.close();
}

int main(){

    int n1,n2;
    Triangle *Tri= new Triangle[100];
    Circle *Cir= new Circle[100];

    read(Tri, n1, Cir, n2);

    for (int i=0; i < n1; i++){
        cout << "[" << Tri[i].type;
        cout << ", (" << Tri[i].A.x << ", " << Tri[i].A.y << "),";
        cout << " (" << Tri[i].B.x << ", " << Tri[i].B.y << "),";
        cout << " (" << Tri[i].C.x << ", " << Tri[i].C.y << ")]" << endl;
    }
    for (int i=0; i < n2; i++){
        cout << "[" << Cir[i].type;
        cout << ", (" << Cir[i].I.x << ", " << Cir[i].I.y << "),";
        cout << " " << Cir[i].radius << "]" << endl;

    }

    delete[] Tri;
    delete[] Cir;

    return 0;
}