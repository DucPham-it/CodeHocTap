#include <iostream>
#include <string>
#include <print>

//Mail 
std::string mail = "d**p287*@gmail.com";

void printSent(std::string sent);
void askQuesUseCase();
void bye();

int main()
{
    printSent("Find the missing part of the Email : "+mail);
    askQuesUseCase();
    bye();

    return 0;
}

void printSent(std::string sent){
    std::println("{}", sent);
}
void askQuesUseCase(){
    //3 answers for questions
    char ans1;
    char ans2;
    char ans3;

    //Question 1
    // TODO :code function
    printSent("1. Which famous K-Pop girl group has a name that combines 2 English colors and has four members? (Take the 3rd character)");
    std::cout << "Your answer character: ";
    std::cin >> ans1;

    //Question 2
    printSent("2. What is \"Good morning\" in Japanese? (Take the first letter)");
    std::cout << "Your answer character: ";
    std::cin >> ans2;

    //Question 3
    printSent("3. Which number president of the United States was Washington?");
    std::cout << "Your answer character: ";
    std::cin >> ans3;

    //Final Mail
    std::string finalCode = { ans1, ans2, ans3 };
    for (int i = 0; i < 3; i++){
        size_t pos = mail.find('*');
        mail[pos] = finalCode[i];
    }
    printSent("\nYour final mail : "+mail);
}

void bye() {
    std::cout << "\nHope you can find out us!!! Press \"Enter\" to end...\n"; 
    std::cin.get();
}