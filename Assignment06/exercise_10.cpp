#include <iostream>
#include <vector>
int main(){
    std::vector<std::vector<std::string>> listCountry = {
        {"Cambodia", "Phnom Penh","phnom penh"},
        {"Thailand", "Bangkok","bangkok"},
        {"China", "Beijing", "beijing"},
        {"Japan", "Tokyo","tokyo"},
        {"India", "Delhi","delhi"},
        {"Malaysia", "Kuala Lumpur", "kuala lumpur"},
        {"Turkey","Ankara","ankara"},
        {"Laos", "Vientiane", "vientiane"},
        {"Vietnam","Hanoi", "hanoi"},
        {"Ukraine","Kiev", "kiev"},
    };
    std::string strAnswer;
    int correct = 0;
    std::cout << "[HOW MUCH YOU KNOW]" << std::endl;
    for(int i = 0; i < listCountry.size(); i++){
        std::cout << "What is the capital of " << listCountry.at(i).at(0) << " ? ";
        getline(std::cin, strAnswer);
        if((strAnswer == listCountry.at(i).at(1)) or (strAnswer == listCountry.at(i).at(2))){
            std::cout << "Your answer is correct." << std::endl;
            correct++;
        }else {
            std::cout << "The correct answer should be " << listCountry.at(i).at(1) <<'.'<< std::endl;
        }
    }
    std::cout << "The correct count " << correct << std::endl;
    return 0;
}