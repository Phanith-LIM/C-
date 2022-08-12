#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
int main(){
    std::string password;
    std::cout << "Enter your password : ";
    char rules[] = "0123456789";
    getline(std::cin, password);
    bool isPass1 = true;
    bool isPass2 = true;
    bool isPass3 = true;
    bool isPass4 = true;
    bool isPass5;
    //isTest1 : A password must have exactly 8 characters
    if(password.length() >= 8){
        std::cout << "\x1b[32m Passed Test 1 : ✅" << std::endl;
        //isTest2 : A password must consist of only digits and letters.
            if ((std::all_of(password.begin(), password.end(), isalpha) || (std::all_of(password.begin(), password.end(), isalnum)))){
                //isTest3 : A password must always start with a digit.
                if(strchr(rules,password[0])){
                    //isTest4 : A password must contain at least one uppercase letter.
                    for (int i = 0; i < password.length(); i++){
                        if (isupper(password[i])){
                            isPass4 = true;
                            break;
                        }else{
                            isPass4 = false;
                        }
                    }
                }
                else{
                    isPass3 = false;  
                }
            }
            else{
                isPass2 = false;
            }
        if (isPass2)
            std::cout << "\x1b[32m Passed Test 2 : ✅" << std::endl;
        else
             std::cout << "\x1b[31m Failed Test 2 : ❌" <<std::endl;

        if (isPass3)
            std::cout << "\x1b[32m Passed Test 3 : ✅" << std::endl;
        else
             std::cout << "\x1b[31m Failed Test 3 : ❌" <<std::endl;
        
         if (isPass4)
            std::cout << "\x1b[32m Passed Test 4 : ✅" << std::endl;
        else
             std::cout << "\x1b[31m Failed Test 4 : ❌" <<std::endl;
    }else{
        isPass1 = false;
        std::cout << "\x1b[31m Failed Test 1 : ❌" <<std::endl;
    }

    //Final evaluate
    isPass5 = isPass1 && isPass2 && isPass3 && isPass4;
    if(isPass5){
        std::cout << "\x1b[32m Passed Final Test : ✅" << std::endl;
    }else{
        std::cout << "\x1b[31m Failed Final Test : ❌" <<std::endl;
    }
    return 0;
}