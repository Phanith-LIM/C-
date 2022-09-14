#include <iostream>
int main(){
    int array[][5] = 
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25},
    };
    int row, column; 
    column = row = 5;
    int time = 0;
    //pointer to array
    int *arr_ptr = &array[0][0];
    
    for(int i = 0; i < row; i++){
        for (int j = 0; j < time + 1; j++){
            std::cout << *(arr_ptr + (i + 1)*row*(row - 1) - (row*column*i - j*(row + 1))) <<"\t";
        }
        time++;
        std::cout <<std::endl;
    }
    
    for(int k = 0; k < row - 1; k++){
        for(int i = row + k; i < row + (k + 1); i++)
        {
            for (int j = k + 1  ; j < time + k; j++){
                std::cout << *(arr_ptr + (i + 1)*row*(row - 1) - (row*column*i - j*(row + 1))) <<"\t";
            }
            time--;
            std::cout <<std::endl;
        }
    }
    return 0;
}