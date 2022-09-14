#include <iostream>
int main(){
     int array[][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    //size
    int row, column;
    column = row = 4;
    int time = 0;
    //pointer to array
    int *arr_ptr = &array[0][0];
    /*
        1
        5       2
        9       6       3
        13      10      7       4
    */
    for(int i = 0; i < row; i++){
        for (int j = 0; j < time + 1; j++){
            std::cout << *(arr_ptr + i*row - j*(column - 1)) <<"\t";
        }
        time++;
        std::cout <<std::endl;
    }
    /*
        14      11      8
        15      12
        16
    */ 
    for(int k = 0; k < row - 1; k++){
        for(int i = row + k; i < row + (k + 1); i++)
        {
            for (int j = k + 1  ; j < time + k; j++){
                std::cout << *(arr_ptr + i*row - j*(column - 1)) <<"\t";
            }
            time--;
            std::cout <<std::endl;
        }
    }
    return 0;
}