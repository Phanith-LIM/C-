#include <iostream>
#include <sstream>
void display_longest_word(std::string );
int main()
{
    std::string str = "Hello how are you today ?";
    std::string st1;
    std::istringstream wordFromText(str);
    display_longest_word(str);
    return 0;
}
void display_longest_word(std::string text){
    std::string longWord;
    std::string eachWord;
    std::string finalEachWord;
    int longLength = 0;
    std::istringstream wordFromText(text);
    while(wordFromText >> eachWord){
        if (longLength < eachWord.size()){
            longLength = eachWord.size();
            longWord = eachWord;
        }else if(longLength == eachWord.size()){
            longWord += "; ";
            longWord += eachWord;
        }
    }
    std::cout << "Longest Word : "<<longWord <<std::endl;
}