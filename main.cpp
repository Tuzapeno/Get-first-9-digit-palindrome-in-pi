#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;   using std::endl; 
using std::string; using std::ifstream; 
using std::vector;


int isPrime(vector<int>& vec)
{
    int num = 0;

    for (auto i : vec)
        num = num * 10 + i;

    for(int i = 2; i < num; ++i)
        if(num % i == 0)
            return 0;

    return 1;
}

int isPalindrome(vector<int>& vec)
{
    vector<int>::iterator it = vec.begin();
    vector<int>::reverse_iterator rit = vec.rbegin();

    for(int i = 0; i < 4; ++i)
    {
        if(*it == *rit)
        {
            std::advance(it, 1);
            std::advance(rit, 1);
        }
        else return 0;
    }
    return 1;
}

void printVector(vector<int>& vec)
{
    for(int i : vec)
        cout << i;
    cout << endl;
}

int main () 
{
    char character;
    vector<int> digits;

    ifstream myFile ("pi.txt");

    if (!myFile.is_open())
    {
        cout << "Unable to open file\n";
        exit(1);
    }

    //Gets the first 9 values.
    for(int i = 0; i < 9; ++i)
    {
        if(myFile.get(character))
        {
            int digit = character - '0';
            digits.push_back(digit);
        }  
    }

    while(!myFile.eof())
    {
        if(isPalindrome(digits))
        {
            if(isPrime(digits))
            {
                cout << "\nPrime Palindrome found!\n";
                printVector(digits);
                break;
            }
        }

        myFile.get(character);

        digits.erase(digits.begin());

        int digit = character - '0';
        digits.push_back(digit);
    }

    myFile.close();
    return 0;
}