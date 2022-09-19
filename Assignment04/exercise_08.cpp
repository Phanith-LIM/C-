#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
int main(){
    char *namCountry;
    char **listCountry = (char**)calloc(1, sizeof(char *));
    if (listCountry== NULL) {
        std::cout << "Error: out of memory."; 
        exit(1);
    }
    int res;
    char *temp;
    int sizeStr = 1;
    int sizeCountry = 1;
    int increment = 0;
    bool isDone = false;
    for (int i = 0; !isDone ; i++) { 
        namCountry = (char *)malloc(1);
        std::cout << "Enter Country : ";
        char nameInput = getchar();
        for (int j = 0; nameInput != '\n'; j++){
            namCountry[j] = nameInput;
            sizeStr++;
            namCountry = (char *)realloc(namCountry, sizeStr);
            if (namCountry== NULL) {
                std::cout << "Error: out of memory."; 
                exit(1);
            }
            nameInput = getchar();
        }
        namCountry[sizeStr - 1] = '\0';
        std::string subNam = namCountry;
        if(subNam == "Done"){
            isDone = true;
            break;
        }
        if(!isDone){
            if(std::all_of(subNam.begin(), subNam.end(), isalpha)){
                listCountry[increment] = namCountry;
                sizeCountry++;
                listCountry = (char **)realloc(listCountry, sizeCountry * sizeof(*listCountry));
                increment++;
                if (listCountry== NULL) {
                    std::cout << "Error: out of memory."; 
                    exit(1);
                }
                
            }
        }
    }
    std::cout << increment << " ";
    for(int round = 1; round < increment; round++){
        for(int i = 0; i < increment - round; i++){
            //similar static_cast<int> 
            res = strcmp(listCountry[i], listCountry[i + 1]);
            if(res > 0){ 
                temp = (char *)malloc(strlen(listCountry[i] + 1) * sizeof(char));
                strcpy(temp, listCountry[i]);
                strcpy(listCountry[i], listCountry[i + 1]);
                strcpy(listCountry[i + 1], temp);        
            }
        }
    }
    std::cout << "List Country : ";
    for(int i = 0; i < increment; i++){
        std::cout << listCountry[i] << " ";
    }
    std::cout << std::endl;
    free(listCountry);
    free(namCountry);
    free(temp);
    return 0;
}