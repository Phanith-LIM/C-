#include <iostream>
void sort_string(std::string str[6], int size);
int main(){
    std::string str[] = {"Apples", "Mango", "Oranges", "Boysenberries", "Bananas", "Yunnan Hackberry"};
    int size = sizeof(str)/sizeof(str[0]);
    std::cout <<"Before sorted : "<<" : ";
    for(int i = 0; i < size; i++){
        std::cout << str[i] <<" ";
    }
    std::cout << std::endl;
    sort_string(str,size);
    std::cout <<"After sorted : "<<" : ";
    for(int i = 0; i < size; i++){
        std::cout << str[i] <<" ";
    }
    std::cout << std::endl;
    return 0;
}
void sort_string(std::string str[6], int size){
    int res;
    for(int round = 1; round < size; round++){
        for(int i = 0; i < size - round; i++){
            //similar static_cast<int> 
            res = str[i].compare(str[i+1]);
            if(res > 0){ 
                std::swap(str[i], str[i+1]);
            }
        }
    }
}