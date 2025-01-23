#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    double a,min,max;
    char line[100];
    int i=1;

    do {
        cout<<"Number "<<i<<" = ";
        cin.getline(line,100);
        if (!(stringstream(line)>>a)){
            cout<<"Wrong! Enter Again ";
        }
        else{
            if (i==1){
                min=a;
                max=a;
            }
            if ((min>a) && (a!=0)) min=a;
            if ((max<a) && (a!=0)) max=a;
            i++;
        }
    } while ((!(stringstream(line)>>a)) || (a!=0));
    
    if ((min==0) && (max==0)){
      cout<<"NO VALID OF MAX AND MIN WAS FOUND";
    }
    else{
    cout<<"Max = "<<max<<endl;
    cout<<"Min = "<<min<<endl;
    }

    return 0;
}