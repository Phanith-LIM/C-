#include <iostream>
int main(){
    int *ptr_int = (int *)malloc(1);
    if (ptr_int == NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }
    int sumInt = 0;
    int increment = 1;
    for (int i = 0; sumInt < 100; i++){
        std::cout << "Enter integer : ";
        std::cin >> ptr_int[i];
        increment++;
        ptr_int = (int*)realloc(ptr_int, increment * sizeof(int));
        if (ptr_int == NULL) {
            std::cout << "Error: out of memory."; 
            exit(1);
        }
        sumInt = sumInt + (*(ptr_int + i));
    }
    std::cout << "SUM : " << sumInt << std::endl;
    std::cout << "Integer : ";
    for(int i = 0; i < increment; i++){
        std::cout << *(ptr_int + i) << " ";
    }
    std::cout << std::endl;
    free(ptr_int);
    return 0;
}