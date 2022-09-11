#include <iostream>
void reverse_str(std::string *str_ptr);
int main(){
    std::string str = "Hello";
    reverse_str(&str);
    std::cout << str <<std::endl;
    return 0;
}
void reverse_str(std::string *str_ptr){
    int str_length = (*str_ptr).length() - 1 ;
    for(int i = 0; i < str_length / 2; i++){
        std::swap((*str_ptr)[i], (*str_ptr)[str_length - i]);
    }
}