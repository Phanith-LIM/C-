#include <iostream>
void shuffle_array(int array[],int sizeArray);
int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int sizeArray = sizeof(array)/sizeof(array[0]);
    srand(time(0));

    //Before shuffle
    std::cout <<"Before shuffle : ";
    for(int i = 0; i < sizeArray; i++){
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    //Use shuffle_array function
    shuffle_array(array,sizeArray);

    //After shuffle
    std::cout <<"After shuffle : ";
    for(int i = 0; i < sizeArray; i++){
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
void shuffle_array(int array[], int sizeArray){
    int *arr_ptr = &array[0];
    for(int i = 0; i < sizeArray; i++){
        int randomIndex = rand() % sizeArray;
        std::swap(*(arr_ptr),*(arr_ptr + randomIndex));
    }
}