#include <iostream>
int main(){
    // int array[6][7] = {
    //     {0,1,0,3,1,6,1},
    //     {0,1,6,8,6,0,1},  
    //     {5,6,2,1,8,2,9},
    //     {6,5,6,1,1,9,1},
    //     {1,3,6,1,4,0,7},
    //     {3,3,3,3,4,0,7}
    // };
    // int array[6][7] = {
    //     {0,1,0,3,1,6,1},
    //     {0,1,6,8,6,0,1},  
    //     {5,5,2,1,8,2,9},
    //     {6,5,6,1,1,9,1},
    //     {1,5,6,1,4,0,7},
    //     {3,5,3,3,4,0,7}
    // };
    // int array[6][7] = {
    //     {0,1,0,3,1,6,1},
    //     {0,1,6,8,6,0,1},  
    //     {5,6,2,1,6,2,3},
    //     {6,5,6,5,1,3,1},
    //     {1,3,2,1,3,0,7},
    //     {3,6,3,3,4,0,7}
    // };
    int array[6][7] = {
        {6,1,0,3,1,6,1},
        {6,9,6,4,3,0,1},  
        {6,6,9,3,7,2,9},
        {6,1,3,9,1,5,1},
        {1,3,3,1,9,0,7},
        {3,3,3,3,4,0,7}
    };
    int *arr_ptr = &array[0][0];
    int row = 6;
    int column = 7;
    int first_num, next_num;
    int time = 0;
    for(int i = 0; i < row; i++){
        for(int j  = 0; j < column; j++){
            std::cout << *(arr_ptr + i*(row + 1) + j) << " ";
        } 
        std::cout << std::endl;
    }
    for(int t = 1; t <= 4; t++){
        int count = 0;
        int isFound = false;
        switch(t){
            //Horizontally
            case 1:
                for(int i = 0; i < row; i++){
                    count = 1;
                    for(int j  = 0; j < column; j++){
                        first_num = *(arr_ptr + i*(row + 1) + j);
                        next_num = *(arr_ptr + i*(row + 1) + (j + 1));
                        if(first_num == next_num){
                            if(count >= 4) {
                                break;
                            }
                            count++;
                        }
                    } 
                    if(count == 4) {
                        std::cout <<"Horizontal "<<"R["<<i<<"] : "<< "True"<<std::endl;
                        break;
                    }
                }
                if(count < 4) std::cout << "Horizontal : False"<<std::endl;
            break;
            //Vertically
            case 2:
                for(int i = 0; i < column; i++){
                    count = 1;
                    for(int j  = 0; j < row; j++){   
                        first_num = *(arr_ptr + j*column + i);
                        next_num = *(arr_ptr + (j + 1)*column + i);
                        if(first_num == next_num){
                            if(count >= 4) {
                                break;
                            }
                            count++;
                        }
                    } 
                    if(count == 4) {
                        std::cout <<"Vertically "<<"C["<<i<<"] : "<< "True"<<std::endl;
                        break;
                    }
                }
                if(count < 4 ) std::cout << "Vertically : False "<<std::endl;
            break;
            case 3:
                // Diagonally right up
                for(int i = 0; i < row; i++){
                    count = 1;
                    for(int j  = 0; j < time + 1; j++){
                        first_num = *(arr_ptr + i*row*column - ((row*column - 1)*i - j*row));
                        next_num = *(arr_ptr + i*row*column - ((row*column - 1)*i - (j+1)*row));
                        if(first_num == next_num){
                            if(count >= 4) {
                                break;
                            }
                            count++;
                        }
                    } 
                    if(count >= 4) {
                        std::cout <<"Diagonally right up : "<< "True"<<std::endl;
                        isFound = true;
                        break;
                    }
                    time++;
                }
                if(!isFound){
                    for(int k = 0; k < row; k++){
                        count = 1;
                        for(int i = row + k; i < row + (k + 1); i++){
                            for (int j = k ; j < time + k; j++){
                                // std::cout << *(arr_ptr + i*row*column - ((row*column - 1)*i - j*row)) <<" ";
                                first_num = *(arr_ptr + i*row*column - ((row*column - 1)*i - j*row));
                                next_num = *(arr_ptr + i*row*column - ((row*column - 1)*i - (j+1)*row));
                                if(first_num == next_num){
                                    if(count == 4) break;
                                    count++;
                                }
                            }
                            if(count == 4) {
                                std::cout <<"Diagonally right up : True"<<std::endl;
                                isFound = true;
                                break;
                            }  
                            time--;
                        }
                    }
                   if(!isFound){
                     if(count < 4) {
                        std::cout << "Diagonally right up : False"<<std::endl;
                    }
                   }
                }
            break;
            case 4 :
                // Diagonally right down
                for(int i = 0; i < row; i++){
                    count = 1;
                    for (int j = 0; j < time + 1; j++){
                        // std::cout << *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - j*(column + 1))) <<" ";
                        first_num = *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - j*(column + 1)));
                        next_num = *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - (j+1)*(column + 1)));
                        if(first_num == next_num){
                            if(count >= 4) break;
                            count++;
                        }
                    }
                    if(count >= 4) {
                        std::cout <<"Diagonally right down : True"<<std::endl;
                        isFound = true;
                        break;
                    }
                    time++;
                }
                if(!isFound){
                    for(int k = 0; k < row; k++){
                        count = 1;
                        for(int i = row + k; i < row + (k + 1); i++)
                        {
                            for (int j = k + 1 ; j < time + k + 1; j++){
                                // std::cout <<  *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - j*(column + 1))) <<" ";
                                first_num = *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - j*(column + 1)));
                                next_num = *(arr_ptr + (i + 1)*(row - 1)*column - (row*column*i - (j+1)*(column + 1)));
                                if(first_num == next_num){
                                    if(count == 4) break;
                                    count++;
                                }    
                            }
                            if(count == 4) {
                                std::cout <<"Diagonally right down : True"<<std::endl;
                                isFound = true;
                                break;
                            }
                            time--;
                        }
                    }
                    if(!isFound){
                        if(count < 4) {
                            std::cout << "Diagonally right down : False"<<std::endl;
                            break;
                        }
                    }
                }      
            break;
        }
    }
    return 0;
}