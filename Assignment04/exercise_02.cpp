#include <iostream>
#include <cstdlib>
int main(){
    int sizeArr;
    int *numArr = (int *)malloc(sizeArr * sizeof(int));
    if (numArr == NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }
    int numEven = 0;
    int numOdd = 0;

    std::cout << "Enter size : ";
    std::cin >> sizeArr;

    for (int i = 0; i < sizeArr; i++){
        std::cout << "Enter integer "<<i + 1<<" : ";
        std::cin >> numArr[i];
    }
    
    for(int i = 0; i < sizeArr; i++){
        int subNum = *(numArr + i);
        //is Even Number
        if(subNum % 2 == 0){
           numEven++;
        }
        //is Odd Number
        if(subNum % 2 != 0){
           numOdd++;
        }
    }
    std::cout<<"Element : ";
    for(int i = 0; i < sizeArr; i++){
        std::cout<<*(numArr + i)<<" ";
    }
    std::cout << std::endl;
    std::cout<< "Number of Even  : " << numEven <<std::endl;
    std::cout<< "Number of Odd : " << numOdd <<std::endl;
    free(numArr);
}