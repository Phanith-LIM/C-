#include <iostream>
void reverse_str(std::string *str_ptr);
int main(){
    std::string str = "Good morning, How are you today ?";
    reverse_str(&str);
    std::cout << str <<std::endl;
    return 0;
}
void reverse_str(std::string *str_ptr){
    int str_length = (*str_ptr).length();
    for(int i = 0; i < str_length; i++){
        std::swap((*str_ptr)[i], (*str_ptr)[str_length--]);
    }
}
