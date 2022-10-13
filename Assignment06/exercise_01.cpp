#include <iostream>
#include <vector>
int main(){
    std::vector<int> numDistinict;
    int *subInput = new int;
    bool isNotDistinict;
    if(subInput == NULL){
        std::cout << "Error : Can not allocate memory" << std::endl;
        exit(1);
    }
    std::cout << "[Vector Distinict Number] : ENTER 0 TO STOP" <<std::endl;
    do{
        isNotDistinict = true;
        std::cout << "ENTER Integer : ";
        std::cin >> (*subInput);
        if((*subInput) == 0) break;
        //numDistinict isEmpty add the first elements
        if(numDistinict.empty()){
            numDistinict.push_back((*subInput));
        }
        //numDistinict isNotEmpty check isNotDistinict add this input to numDistinict 
        if(!numDistinict.empty()){
            for(int i : numDistinict){
                if(i == (*subInput)){
                    isNotDistinict = false;
                    break;
                }
            }
            if(isNotDistinict == true) numDistinict.push_back((*subInput));
        }
    }while((*subInput) != 0);
    /*
        isNotEmpty : Print all elements.
        isEmpty : Print these are not elements in vector
    */
    if(!numDistinict.empty()){
        std::cout << "Distinict Integer : ";
        std::sort(numDistinict.begin(),numDistinict.end());
        for(int i : numDistinict){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }else std::cout << "\n[In vector does't have any elements.]" << std::endl;
    delete subInput;
    return 0;
}