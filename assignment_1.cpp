#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string number;
    float average;
    float sum = 0;
    char decimals_digit[] = "0123456789";
    bool isDecimal = true;
    short int sizeNumber = sizeof(number) / sizeof(number[0]);
    cout << "Enter numer : ";
    getline(cin, number);
    
    //check number isDecimal
    for(int i = 0; i < number.size(); i++){
        if(strchr(decimals_digit, number[i]) == NULL){
            isDecimal = false;
            cout << "This is not decimal number "<<endl;
                break;
        }
    }
    if (isDecimal){
        for(int i = 0; i < number.size(); i++){
            sum = sum  + (number[i] - 48);
        }
        average = sum / number.size();
        cout << "The average of the digits in "<< number << " is "<< average <<endl;
    }
    return 0;
}