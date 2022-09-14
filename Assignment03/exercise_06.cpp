#include <iostream>
int main(){
    int array[][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    //size
    int row = 5;
    int column = 4;
 
    //pointer to array
    int *arr_ptr = &array[0][0];

    for(int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            std::cout << *(arr_ptr + i*row + j) <<"\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
