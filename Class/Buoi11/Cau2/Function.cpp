#include "Header.h"

int checkCircle(Circle C1, Circle C2){
    if (C1.I.x==C2.I.x && C1.I.y==C2.I.y){
        if (C1.radian==C2.radian){
            return 3;
        }
        else{
            return 1;
        }
    }
    double checkLong2Aim= sqrt(pow(C1.I.x-C2.I.x,2) +pow(C1.I.y-C2.I.y,2));
    if (checkLong2Aim == C1.radian+C2.radian) return 1;
    if (checkLong2Aim < C1.radian+C2.radian) return 2;
    if (checkLong2Aim > C1.radian+C2.radian) return 0;
}