#include <iostream>
int count_word_in_str (std::string *str_ptr, std::string *word_ptr);
int main(){
    std::string str;
    std::string word;
    std::cout << "Enter the sentence : ";
    getline(std::cin, str);
    std::cout << "Enter the the : ";
    getline(std::cin, word);

    std::cout << " Time: "<< count_word_in_str(&str, &word) <<std::endl;
    return 0;
}
int count_word_in_str(std::string *str_ptr, std::string *word_ptr){
    int count = 0;
    for(int i = 0; (*str_ptr)[i] != '\0'; i++){
        bool found = true;
        //if found word_ptr[i] does not match the str_ptr[i]
        for(int j = 0; (*word_ptr)[j] != '\0'; j++){
            if((*word_ptr)[j] != (*str_ptr)[i + j]){
                found = false;
                break;
            }
        }
        //if passed the condition or found the word is the same in string,count will be increase.
        if(found) count++;
    }
    return count;
}