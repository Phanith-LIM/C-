#include <iostream>
int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int sizeArray = sizeof(array)/sizeof(array[0]);
    //point to basic address
    int *ptr = &array[0]; 

    //print reverse order
    for (int i = sizeArray - 1 ; i >= 0; i--){
        std::cout << *(ptr + i) << " ";
    }
    return 0;
}