#include <iostream>
int main(){
    int numberInt;
    int increment = 1;
    int indexDistinct = 1;
    int *numDistinct = (int *)malloc(1);
    if (numDistinct== NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }
    bool isZero = false;
    std::cout << "DISTINCT INTEGER (Enter 0 to stop)" << std::endl;
    for(int i = 0; !isZero ; i++ ){
        bool isDistinct = true;
        std::cout << "Enter integer : ";
        std::cin >> numberInt;
        if (numberInt == 0) {
            isZero = true;
            break;
        };
        if(i == 0){
            numDistinct[i] = numberInt;
        }
        if(i > 0) {
            for(int j = 0; j < i ; j++){
                if(numberInt == numDistinct[j]){
                    isDistinct = false;
                    break;
                }
            }
            if (isDistinct == true){
                //extend size array
                increment++;
                numDistinct = (int*)realloc(numDistinct, increment * sizeof(int));
                if (numDistinct== NULL) {
                    std::cout << "Error: out of memory."; 
                    exit(1);
                }
                //add to the next index
                numDistinct[indexDistinct] = numberInt; 
                indexDistinct++;
            }
        }
    }
    std::cout << "Distinct Elements : ";
    for(int i = 0; i < increment; i++){
        std::cout << numDistinct[i] << " ";
    }
    std::cout << std::endl;
    free(numDistinct);
    return 0;
}