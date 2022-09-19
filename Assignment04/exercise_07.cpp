#include <iostream>
#include <cstdlib>
#include <cstring>
int main(){
    char *numHex;
    int sizeStr = 1;
    int sizeHex = 1;
    int increment = 0;
    char **listHex = (char**)calloc(1, sizeof(char *));
    bool isDone = false;
    bool isHex;
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
       }
    }
    std::cout << "Hexadecimal values: ";
    for(int i = 0; i < increment; i++){
        std::cout << listHex[i] << " ";
    }
    std::cout << std::endl;
    free(listHex);
    free(numHex);
    return 0;
}