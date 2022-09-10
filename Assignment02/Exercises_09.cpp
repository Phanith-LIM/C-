#include <iostream>
void capitalize(std::string *str1){
    std::string str = *str1;
    std::cout<<"Capitalize function : "<<str<<std::endl;
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
    *str1 = str;
}
int main(){
    std::string str = "hello";
    capitalize(&str);
    std::cout<<"Capitalize function : "<<str<<std::endl;
    return 0;
}
