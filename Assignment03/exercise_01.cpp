#include <iostream>
int main(){
    int array[] = {1,2,3,4,5,6,7,9,5,10,12};
    int sizeArray = sizeof(array)/sizeof(array[0]);
    //point to basic address
    int *ptr = &array[sizeArray - 1]; 
    
    // print reverse order
    for (int i = 0 ; i < sizeArray; i++){
        std::cout << *(ptr)-- <<" ";
    }
    std::cout << std::endl;
    return 0;
}