#include <iostream>
int main(){
    int *ptr_int = (int *)malloc(1);
    int i = 0;
    bool isZero = false;
    int increment = 1;
    std::cout << "ASCENDING ORDER OF INTEGER (Enter 0 to stop)" << std::endl;
    for(int i = 0; !isZero ; i++ ){
        std::cout << "Enter integer : ";
        std::cin >> ptr_int[i];
        if (ptr_int[i] == 0) isZero = true;
        increment++;
        ptr_int = (int*)realloc(ptr_int, increment * sizeof(int));
        if (ptr_int == NULL) {
            std::cout << "Error: out of memory."; 
            exit(1);
        }
    }
    if(isZero){
        for (int i = 0; i < increment - 1; i++){
            for (int j = i + 1; j < increment - 1; j++){
                if (ptr_int[i] >= ptr_int[j]){
                    std::swap(ptr_int[i],ptr_int[j]);
                }
            }
        }
    }
    std::cout << "ASCENDING ORDER OF INTEGER : ";
    for (int i = 0 ; i < increment - 1; i++){
        std::cout << ptr_int[i] << " ";
    }
    std::cout << std::endl;
    free(ptr_int);
    return 0;
}