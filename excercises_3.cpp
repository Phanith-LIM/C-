#include <iostream>
#include <string>
#include <algorithm>
int main(){
    std::string password;
    std::cout << "Enter your password : ";
    char rules[] = "0123456789";
    getline(std::cin, password);
    bool isPassed1 = password.length() >= 8;
    bool isPassed2;
    bool isPassed3;
    bool isPassed4;
    bool isPassed5;
    //isTest1 : A password must have exactly 8 characters
    if (isPassed1){
        std::cout << "\x1b[32m Passed Test 1 : ✅" << std::endl;
        for (int i = 0; i < password.length(); i++)
        {
            //isTest2 : A password must consist of only digits and letters.
            if ((std::all_of(password.begin(), password.end(), isalpha) || (std::all_of(password.begin(), password.end(), isalnum)))){
                isPassed2 = true;
            }
            else isPassed2 = false;

            //isTest3 : A password must always start with a digit.
            if(strchr(rules,password[0])) isPassed3 = true;
            else isPassed3 = false;
            
            //isTest4 : A password must contain at least one uppercase letter.
            if (isupper(password[i])){
                isPassed4 = true;
                break;
            }else isPassed4 = false;
    
        }
        //Display isPassed rules for passwords
        if (isPassed2) std::cout << "\x1b[32m Passed Test 2 : ✅" << std::endl;
        else std::cout << "\x1b[31m Failed Test 2 : ❌" <<std::endl;

        if (isPassed3) std::cout << "\x1b[32m Passed Test 3 : ✅" << std::endl;     
        else std::cout << "\x1b[31m Failed Test 3 : ❌" <<std::endl;
             
        if (isPassed4) std::cout << "\x1b[32m Passed Test 4 : ✅" << std::endl;   
        else std::cout << "\x1b[31m Failed Test 4 : ❌" <<std::endl;
    }else{
        isPassed1 = false;
        std::cout << "\x1b[31m Failed Test 1 : ❌" <<std::endl;
    }
    //Final evaluate
    isPassed5 = isPassed1 && isPassed2 && isPassed3 && isPassed4;
    if(isPassed5){
        std::cout << "------------------------------" << std::endl;
        std::cout << "\x1b[32m Passed Final Test : ✅" << std::endl;
        std::cout << "\x1b[32m Valid Password" << std::endl;
    }else{
        std::cout << "------------------------------" << std::endl;
        std::cout << "\x1b[31m Failed Final Test : ❌" <<std::endl;
        std::cout << "\x1b[31m Invalid Password" <<std::endl;
    }
    return 0;
}