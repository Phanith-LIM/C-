#include <iostream>
void remove_int_from_array(int array[9],int *sizeArray, int deleteNumber);
int main(){
    int array[] = {1,9,3,4,5,6,4,8,9,4,9,10};
    int size = sizeof(array)/sizeof(array[0]);

    remove_int_from_array(array, &size ,9);
    for(int i = 0; i < size; i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
void remove_int_from_array(int array[],int *sizeArray, int deleteNumber){
    int size = *sizeArray;
    for(int k = 0; k < size; k++){
        for(int i = 0; i < size; i++){
            if(array[i] == deleteNumber){ 
                for (int j = i; j < size;  j++){
                    array[j] = array[j+1];
                }
                size--;
            }
        }
    }
    *sizeArray = size;
}