#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
int main(){
    int sizeArr;
    char *charArr = (char *)malloc(sizeArr * sizeof(char));
    if (charArr == NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }
    int increment = 0;
    char subChar;
    std::cout << "Enter size : ";
    std::cin >> sizeArr;

    for (int i = 0; i < sizeArr; i++){
        std::cout << "Enter Alphabet " ​<< i + 1 <<" : ";
        std::cin >> subChar;
        if(isalpha(subChar) == true){
            if((subChar == 'a' || subChar == 'e' || subChar == 'i' || subChar == 'o' || subChar == 'u') || (subChar == 'A' || subChar == 'E' || subChar == 'I' || subChar == 'O' || subChar == 'U')){
            }else{
                charArr[increment] = subChar;
                increment++;
            }
        }
    }
    std::cout << "Consonants : ";
    for (int i = 0; i < increment; i++) std::cout << charArr[i] <<" ";
    std::cout << std::endl;
    free(charArr);
    return 0;
}