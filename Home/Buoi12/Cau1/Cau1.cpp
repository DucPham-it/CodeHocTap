#include <iostream>
#include <stdio.h>
using namespace std;

struct Time{
    int hour, minute;
};

struct ticketFilm{
    char name[256];
    Time timeBegin;
    char theaterName[256];
    double costOfFood;
    double coef;
    double costOfTicket(){
        if (coef == 1.0)
            return coef * 80000 + costOfFood;
        else if (coef == 1.5)
            return (coef * 80000 + costOfFood) * 0.9;
        else
            return 0.0; 
    }
};

void inputTicket(ticketFilm* &a, int &n);
double totalRevenue(Time timeInput, ticketFilm* a, int n);

int main() {
    int n;
    ticketFilm* tickets = nullptr; 

    inputTicket(tickets, n);

    // Nhập thời gian cần tính doanh thu
    Time timeInput;
    cout << "Enter time to calculate revenue (hour minute): ";
    cin >> timeInput.hour >> timeInput.minute;

    // Tính doanh thu
    double revenue = totalRevenue(timeInput, tickets, n);
    cout << "Total revenue for the given time: " << revenue     << endl;

    delete[] tickets;
    return 0;
}

void inputTicket(ticketFilm* &a, int &n){
    cout << "Number of ticket :";
    cin >> n;
    a = new ticketFilm[n];
    

    for (int i=0; i<n; i++){
        cout << "Input ticket ["<<i<<"] :" << endl;

        cout << "Film Name: ";
        cin.ignore(); 
        cin.getline(a[i].name, 256);

        cout << "Time: ";
        // cin >> a[i].timeBegin.hour >> a[i].timeBegin.minute;
        scanf("%dh%dm",&a[i].timeBegin.hour,&a[i].timeBegin.minute);
        cout << "Theater Name: ";
        cin.ignore(); 
        cin.getline(a[i].theaterName, 256);

        cout << "Cost Of Food: ";
        cin >> a[i].costOfFood;

        cout << "Coefficient: ";
        cin >> a[i].coef;

        cout << endl;
    }
}

double totalRevenue(Time timeInput, ticketFilm* a, int n){
    double sum = 0;
    for (int  i=0; i<n; i++){
        if (timeInput.hour== a[i].timeBegin.hour && timeInput.minute == a[i].timeBegin.minute){
            sum+=a[i].costOfTicket();
        }
    }
    return sum;
}