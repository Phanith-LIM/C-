#include <iostream>
#include <cstdlib>
#include <cstring>
int main(){
    char *numHex;
    int sizeStr = 1;
    int sizeHex = 1;
    int sizeNotHex = 1;
    int increment = 0;
    int increment2 = 0;
    char **listHex = (char**)calloc(1, sizeof(char *));
    if (listHex == NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }   
    char **listNotHex = (char**)calloc(1, sizeof(char *));
    if (listNotHex == NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }   
    bool isDone = false;
    bool isHex;
    std::cout << "DISPLAY HEXADECIMAL (Enter Done to stop)"<< std::endl;
    for (int i = 0; !isDone ; i++) { 
        numHex = (char *)malloc(1);
        isHex = true;
        std::cout << "Enter value : ";
        char numInput = getchar();
        for (int j = 0; numInput != '\n'; j++){
            numHex[j] = numInput;
            sizeStr++;
            numHex = (char *)realloc(numHex, sizeStr);
            if (numHex== NULL) {
                std::cout << "Error: out of memory."; 
                exit(1);
            }
            numInput = getchar();
        }
        numHex[sizeStr - 1] = '\0';
        std::string subNum = numHex;
        if(subNum == "Done"){
            isDone = true;
            break;
        }
        if(!isDone){
            for (int k = 0; k < strlen(numHex); k++){
                if (!isxdigit(numHex[k])){
                    isHex = false;
                    break;
                }
            }
            if(isHex == true){
                listHex[increment] = numHex;
                sizeHex++;
                listHex = (char **)realloc(listHex, sizeHex * sizeof(*listHex));
                if (numHex== NULL) {
                    std::cout << "Error: out of memory."; 
                    exit(1);
                }   
                increment++;
            }
            if(isHex != true){
                listNotHex[increment2] = numHex;
                sizeNotHex++;
                listNotHex = (char **)realloc(listNotHex, sizeNotHex * sizeof(*listNotHex));
                if (listNotHex == NULL) {
                    std::cout << "Error: out of memory."; 
                    exit(1);
                }   
                increment2++;
            }
       }
    }
    std::cout << "Hexadecimal values: ";
    for(int i = 0; i < increment; i++){
        std::cout << listHex[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Not Hexadecimal values: ";
    for(int i = 0; i < increment2; i++){
        std::cout << listNotHex[i] << " ";
    }
    std::cout << std::endl;
    free(listHex);
    free(numHex);
    free(listNotHex);
    return 0;
}