#include <iostream>
class Decimal {
private:
    int value;
public:
    Decimal(int value){
        if(value > 1000){
            std::cout << "Value must be less than 1000." << std::endl;
            return;
        }
        this->value = value;
    }
    int reverse(){
        int rev = 0;
        int num = value;
        while(num != 0){
            int remainder = num % 10;
            rev = (rev * 10) + remainder;
            num = num / 10;
        }
        return rev;
    }
    bool is_palindrome(){
        std::string num_str = std::to_string(value);
        std::string rev_str = num_str;
        std::reverse(rev_str.begin(), rev_str.end());
        if(num_str == rev_str) return true;
        return false;
    }
    bool is_prime(){
        if(value == 0 or value == 1){
            return false;
        }
        for(int i = 2; i <= value / 2; i++){
            if(value % i == 0) return false;   
        }
        return true;
    }
    int to_binary(){
        int dec = value;
        std::string binary;
        while(true){
            int rem = dec % 2;
            if(dec < 2) {
                binary += std::to_string(dec);
                break;
            };
            binary += std::to_string(rem);
            dec = dec / 2;
        }
        std::reverse(binary.begin(), binary.end());
        return stoi(binary);
    }
    std::string convertToWord(int value, std::string suffix){
        std::string nameInteger;
        std::string X[] = { "", "one ", "two ", "three ", "four ","five ", "six ", "seven ", "eight ","nine ", "ten ", "eleven ", "twelve ","thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen ","nineteen " };
        std::string Y[] = { "", "", "twenty ", "thirty ", "forty ","fifty ", "sixty ", "seventy ", "eighty ","ninety " };
        if (value == 0) {
            return nameInteger;
        }
        if (value > 19) {
            return Y[value / 10] + X[value % 10] + suffix;
        }
        else {
            return X[value] + suffix;
        }
    }
    std::string to_words(){
        std::string result = "";
        // this handles digits at ones and tens place 1 -> 99
        result = convertToWord((value % 100), "");

        // this handles digit at hundred place 100 -> 999
        result = convertToWord(((value / 100) % 10), "hundred ") + result;
            
        if (value > 1000 && value % 1000) {
            result = "," + result;
        }
        result = convertToWord(((value / 1000) % 100), "thousand ") + result;
        if (value == 0) result = result + "zero";
        return result;
    }
};
int main(){
    int subNumber;
    do{
        std::cout << "NUMBER: ";
        std::cin >> subNumber;
        if(subNumber >= 1000) std::cout << "ENTER NUMBER BETWEEN 0 - 999." << std::endl;
    }while(subNumber >= 1000);
    Decimal value = Decimal(subNumber);
    std::cout << "is_palindrome: " << value.is_palindrome() << std::endl;
    std::cout << "is_prime: " << value.is_prime() << std::endl;
    std::cout << "to_binary: " << value.to_binary() << std::endl;
    std::cout << "to_word: " << value.to_words() << std::endl;
    return 0;
}