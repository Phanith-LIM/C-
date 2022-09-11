#include <iostream>

int main(){
    int array[] = {99,2,3,4,5,306,7,8,9,10};
    int sizeArray = sizeof(array) / sizeof(array[0]);
    int *ptr = &array[0];
    int largest;
    int smallest = largest = array[0];
    for(int i = 0; i < sizeArray; i++){
        //ptr > largest -> ptr is the largest
        if(*(ptr + i) > largest){
            largest = *(ptr + i);
        }else if (*(ptr + i) < smallest){ //ptr < largest -> ptr is the smallest
            smallest = *(ptr + i);
        }
    }
    std::cout <<"The largest : "<<largest<<std::endl;
    std::cout <<"The smallest : "<<smallest<<std::endl;
    return 0;
}