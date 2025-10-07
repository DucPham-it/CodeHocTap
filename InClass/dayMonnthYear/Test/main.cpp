#include <gtest/gtest.h>
#include "../main/usecase.h"

#include <sstream>
#include <format>

using std::istringstream, std::ostringstream;
using std::cout, std::cin;
using std::format;
using std::string;

bool executedCheckDate(int day, int month, int year) {
    istringstream input(format("{}\n{}\n{}\n",
        day,month,year
    ));
    ostringstream output;

    auto* cinBuf = cin.rdbuf();
    auto* coutBuf = cout.rdbuf();
    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());

    checkValidDateUseCase();

    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    
    string info;
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

        info = format("Ngày tiếp theo là: {0}/{1}/{2}\n",nextDay, monthOfNextDay, yearOfNextDay);
        }
    else{
        info = format("Ngày tháng năm không hợp lệ\n");
    }    

    bool result = output.str().find(info) != string::npos;
    return result;
}

TEST(checkVaidDateUseCase, ValidDate_ReturnsCorrect1) {
    int day = 1;
    int month = 1;
    int year = 2000;

    bool found = executedCheckDate(day, month, year);
    EXPECT_EQ(found, true);
}

TEST(checkVaidDateUseCase, ValidDate_ReturnsCorrect2) {
    int day = 31;
    int month = 12;
    int year = 2000;

    bool found = executedCheckDate(day, month, year);
    EXPECT_EQ(found, true);
}

TEST(checkVaidDateUseCase, ValidDate_ReturnsInCorrect1) {
    int day = 1;
    int month = 0;
    int year = 2000;

    bool found = executedCheckDate(day, month, year);
    EXPECT_EQ(found, true);
}

TEST(checkVaidDateUseCase, ValidDate_ReturnsInCorrect2) {
    int day = 1;
    int month = 10;
    int year = 1800;

    bool found = executedCheckDate(day, month, year);
    EXPECT_EQ(found, true);
}


// Nếu bạn không viết hàm main, thì nó sẽ được tự động sinh ra
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}