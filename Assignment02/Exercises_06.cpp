#include <iostream>
#include <cmath>
std::string convertToWord(int numDigit, std::string number);
std::string verbose(int numDigit);
int main(){
    int numInteger;
    do{
        std::cout << "Integer Numbers :  ";
        std::cin >> numInteger;
        if(numInteger > pow(10,6)){
            std::cout << "The number has to less than 10⁶"<<std::endl;
        }else{
            std::cout << "Name integer in English : "<< verbose(numInteger) <<std::endl;
        }
    }while(numInteger > pow(10,6));
    
    return 0;
}
std::string convertToWord (int numDigit, std::string suffix){
    std::string nameInteger = "";
    std::string X[] = { "", "one ", "two ", "three ", "four ","five ", "six ", "seven ", "eight ","nine ", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen ","nineteen " };
    std::string Y[] = { "", "", "twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };
    
    if (numDigit == 0) {
        return nameInteger;
    }

    // split `n` if it is more than 19
    if (numDigit > 19) {
        return Y[numDigit / 10] + X[numDigit % 10] + suffix;
    }
    else {
        return X[numDigit] + suffix;
    }
}
std::string verbose(int number){
    std::string result = "";
    // this handles digits at ones and tens place 1 -> 99
    result = convertToWord((number % 100), "");

    // this handles digit at hundred place 100 -> 999
    result = convertToWord(((number / 100) % 10), "hundred ") + result;
        
    if (number > 1000 && number % 1000) {
        result = "," + result;
    }
    // this handles digits at thousand and tens thousand place 1000 -> 10,000
    result = convertToWord(((number / 1000) % 100), "thousand ") + result;

    // this handles digits at hundred thousand and one lakh place 100 000 -> 100,000
    if(number % 1000 == 0){
        // In case last 3digits is 0
        result = convertToWord(((number / 100000) % 100), "hundred thousand") + result;
    }else{
        result = convertToWord(((number / 100000) % 100), "hundred ") + result;
    }
    // In a single number is 0
    if (number == 0)
        result = result + "zero";
    return result;
}