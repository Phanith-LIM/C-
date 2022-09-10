#include <iostream>
#include <cctype>
std::string swap_case (std::string str);
int main(){    
    std::cout <<"Swap Case Function: "<< swap_case("HeLLo") <<std::endl;
    return 0;
}
std::string swap_case (std::string str){
    for (int i = 0; str[i] != '\0';i++){
        if (isupper(str[i])){
            str[i] = tolower(str[i]);
        }else
            str[i] = toupper(str[i]);
    }
    return str;
}