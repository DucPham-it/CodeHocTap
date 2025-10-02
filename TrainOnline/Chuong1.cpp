#include <iostream>

class LopHoc
{
private:
int student;

public:
LopHoc(/* args */);
void testCall();
~LopHoc();
};

LopHoc::LopHoc(/* args */)
{
std::cout << "Class call out \n";
}
void LopHoc::testCall()
{
student = 5;
std::cout << "student : " << student;
}
LopHoc::~LopHoc()
{
}

int main()
{

return 0;
}