#include <iostream>
#include <algorithm>
bool is_substring(std::string str1, std::string str2);
int main(){
    std::string str1 = "Love";
    std::string str2 = "I Love You";
      
    std::cout <<"\033[31m"<<str1 <<""<<"\033[37m is substring of " <<"\033[31m"<<str2 <<"\033[37m : "<<"\033[31m"<<std::boolalpha << is_substring(str1, str2) <<std::endl;
    return 0;
}
bool is_substring(std::string str2, std::string str1){
    for (int i = 0; str2[i] != '\0';i++){
        bool foundNoMatch = false;
        //find isNot substring
        for(int j = 0; str1[j] != '\0' ; j++){
            if(str1[i + j] != str1[j]){
                foundNoMatch = true;
                break;
            }
        }
        if(!foundNoMatch){
            return true;
        }
    }
    return false;
}
//Reference : http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf