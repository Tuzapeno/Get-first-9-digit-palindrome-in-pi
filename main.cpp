#include <iostream>
#include <fstream>
#include <vector>

using std::cout;   using std::endl; 
using std::string; using std::ifstream; 
using std::vector;


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
    cout << "\nPalindrome found!\n";
    return 1;
}

void printVector(vector<int>& vec)
{
    for(int i : vec)
        cout << i;
}


int main () 
{
  char character;
  vector<int> digits;

  ifstream myFile ("text.txt");

  //Checks if file is open
  if (myFile.is_open())
  {
    //Gets the first 9 values.
    for(int i = 0; i < 9; ++i)
    {
        if(myFile.get(character))
        {
            int digit = character - '0';
            digits.push_back(digit);
        }  
    }

    //Checks for palindrome.
    if(isPalindrome(digits))
    {
        printVector(digits);
        return 0;
    }

    while(!myFile.eof())
    {
        myFile.get(character);

        digits.erase(digits.begin());

        int digit = character - '0';
        digits.push_back(digit);
        
        if(isPalindrome(digits))
        {
            printVector(digits);
            break;
        }
    }
    myFile.close();
  }
  else cout << "Unable to open file"; 

  return 0;
}
