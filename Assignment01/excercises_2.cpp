#include <iostream>
using namespace std;

int main()
{
    int num, digit, rev, newline = 0;
    //find and check isPalindromeNumber
    for(int i = 0; i < 10000; i++){
        num = i;
        rev = 0;
        do{
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);
        //condition printOut
        if ((i == rev) && (rev % 2 == 0)){
            cout << rev << "\t";
            newline++;
            if (newline % 10 == 0){
                cout << "\n";
                if (newline % 50 == 0)
                    break;
            }
        } 
     }
    return 0;
}