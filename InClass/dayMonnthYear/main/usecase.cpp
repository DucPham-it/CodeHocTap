#include "usecase.h"
#include "../lib/utils.h"



void checkValidDateUseCase() {
    int day, month, year;

    std::cout << "Nhập ngày : ";
    std::cin >> day;
    std::cout << "Nhập tháng : ";
    std::cin >> month;
    std::cout << "Nhập năm : ";
    std::cin >> year;

    if (isValidDate(day, month, year)){

        int daysInMonth = getDaysInMonth(month, year);
        int nextDay = day;
        int monthOfNextDay = month;
        int yearOfNextDay = year;

        // Nếu chưa phải ngày cuối tháng
        if (nextDay < daysInMonth) {
            nextDay++;
        } 
        else {
            nextDay = 1;
            if (monthOfNextDay < 12)
                monthOfNextDay++;
            else {
                monthOfNextDay = 1;
                yearOfNextDay++;
            }
        }

        std::cout<< std::format("Ngày tiếp theo là: {0}/{1}/{2}\n",nextDay, monthOfNextDay, yearOfNextDay);
        }
    else{
        std::cout<< std::format("Ngày tháng năm không hợp lệ\n");
    }
}

void salute(std::string message) {
    // TODO: Nếu chuỗi rỗng thì in ra thông báo mặc định
    std::cout << message;
}

void bye() {
    std::cout << "\nChương trình đang thoát. Bấm enter để kết thúc..."; // 1 điểm
    std::cin.get();
}