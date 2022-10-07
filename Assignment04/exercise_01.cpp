#include <iostream>
#include <cstdlib>
int main(){
    int i = 0;
    int size = 1;
    int *ptr_int;
    ptr_int = (int*)malloc(1);
    if(ptr_int == NULL){
        std::cout << "Sorry! unable to allocate memory"; 
        exit(1);
    } 
    do{
        std::cout << " Enter Integer : ";
        std::cin >> *(ptr_int + i); 
        if(*(ptr_int + i) <= 5){
            size++;
            i++;
            ptr_int = (int *)realloc(ptr_int, size * sizeof(int));
            if(ptr_int == NULL){
                std::cout << "Sorry! unable to allocate memory"; 
                exit(1);
            }
        }
    }while (*(ptr_int + i) <= 5);
    for(int j = 0; j < size; j++){
        std::cout << *(ptr_int + j) << " ";
    }
    free(ptr_int);
    return 0;
}