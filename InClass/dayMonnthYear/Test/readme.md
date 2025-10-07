```Bash
$ g++ -std=c++23 -Wall -g -pthread  ./Test/main.cpp ./lib/*.cpp ./main/usecase.cpp -lgtest_main -lgtest -lpthread -o ./outTest/tests
```