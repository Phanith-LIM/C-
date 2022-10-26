#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::vector <std::string> listCountry;
    std::string *subInput = new std::string;
    if(subInput == NULL){
        std::cout << "Error : Can not allocate memory" << std::endl;
        exit(1);
    }
    std::cout << "[Vector Country] : ENTER (Done) TO STOP" <<std::endl;
    do{
        std::cout << "ENTER Country : ";
        std::cin >> (*subInput);
        fflush(stdin);
        if((*subInput) == "Done" or (*subInput) == "done") break;
        listCountry.push_back((*subInput));

    }while((*subInput) != "Done" or (*subInput) == "done");

    std::sort(listCountry.begin(),listCountry.end());
    
    if(!listCountry.empty()){
        std::cout << "COUNTRY : ";
        for(std::string i : listCountry){
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }else std::cout << "\n[In vector does't have any elements.]" << std::endl;
    delete subInput;
    return 0;
}