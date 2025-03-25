// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⠉⠉⠉⠒⠀⠀⠤⣀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠑⡄⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠰⠿⠿⠿⠿⠣⣶⣿⡏⣶⣿⣿⠷⠶⠆⠀⠀⠘⠀
// ⠀⠀⠀⠀⠀⠀⠠⠴⡅⠀⠀⠠⢶⣿⣿⣷⡄⣀⡀⡀⠀⠀⠀⠀⠀⡇⠀
// ⠀⣰⡶⣦⠀⠀⠀⡰⠀⠀⠸⠟⢸⣿⣿⣷⡆⠢⣉⢀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⢹⣧⣿⣇⠀⠀⡇⠀⢠⣷⣲⣺⣿⣿⣇⠤⣤⣿⣿⠀⢸⠀⣤⣶⠦⠀⠀
// ⠀⠀⠙⢿⣿⣦⡀⢇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⡜⣾⣿⡃⠇⢀⣤⡀⠀
// ⠀⠀⠀⠀⠙⢿⣿⣮⡆⠀⠙⠿⣿⣿⣾⣿⡿⡿⠋⢀⠞⢀⣿⣿⣿⣿⣿⡟⠁
// ⠀⠀⠀⠀⠀⠀⠛⢿⠇⣶⣤⣄⢀⣰⣷⣶⣿⠁⡰⢃⣴⣿⡿⢋⠏⠉⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠠⢾⣿⣿⣿⣞⠿⣿⣿⢿⢸⣷⣌⠛⠋⠀⠘⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⣿⣿⣿⣶⣶⣿⣯⣿⣿⣿⣆⠀⠇
// TRY TO FIX BUG TODAY, BECOME A NICE CODER TOMORROW !!!


//24120041 - Pham Vo Duc

#include <iostream>
#include <cstring>
using namespace std;


bool isPunctuation(char* c)
{
    const char Punctuation[] = "!@#$%^&*()_-,.?/\\{}[]:;";
    return strstr(Punctuation, c) != nullptr;
}

void normalizedParagraph(char* a)
{
    if (a == nullptr || strlen(a) == 0) return;

    const int n = strlen(a);
    char temp[n] = "";
    char b[n];
    strcpy(b, a);

    char* token = strtok(b, " \t\n");
    while (token)
    {
        if (isPunctuation(token) || strlen(temp) == 0)
        {
            strcat(temp, token);
        }
        else
        {   
            
            strcat(temp, " ");
            strcat(temp, token);
        }
        token = strtok(nullptr, " \t\n");
    }

    strcpy(a, temp);
}
 

int countWord(char* a)
{   
    const int n = strlen(a);
    char b[n+1];
    strcpy(b,a);
    char* token = strtok(b," \t\n");
    int count = 0;
    while (token)
    {
        count++;
        token = strtok(NULL," \t\n");
    }
    return count;
}

char* longestWord(char* a)
{
    const int n = strlen(a);
    char b[n+1];
    strcpy(b,a);

    char* token = strtok(b," \t\n!@#$%^&*()_-,.?/\\{}[]:;");
    int max = 0;
    char* word = new char[200];
    while (token)
    {
        if (strlen(token) > max){
            strcpy(word, token);
            max = strlen(token);
        }
        token = strtok(NULL," \t\n!@#$%^&*()_-,.?/\\{}[]:;");
    }
    return word;
}

int main()
{
    char a[1024] = "";
    cin.getline(a,1024);
    //Normalized paragraph:
    cout << "Normalized paragraph:" << endl;
    normalizedParagraph(a);
    cout << a << endl;
    //Count Word
    cout << "Word Count : " << countWord(a) << endl;
    //Find ligest word
    char* longest = longestWord(a);
    cout << "Longest Word : " << longest << endl;
    delete[] longest;

    return 0;
}