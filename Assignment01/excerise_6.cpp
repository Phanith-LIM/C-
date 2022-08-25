#include <iostream>
using namespace std;
int main(){
    int pearls[2][10] = {{1,2,3,4,5,6,7,8,9,10},{0,0,0,0,0,0,0,0,0,0}};
    int swap = 0;
    int round = 1;
    int numPicking = 0;
    int randIndex = 0;
    int randDelete = 0;
    srand(time(0));
    for (int i = 0; i < round ;i++){
        numPicking = 3;
        cout <<"numPicking : "<<numPicking <<endl;
        for(int j = 0; j < numPicking; j++){
            randIndex = (rand() % 8);
            if(j == 0){
                randDelete = randIndex;
            }else if(j >= 1){
                do{
                    randIndex = (rand() % 8);
                }while(randDelete == randIndex);
                cout <<"randIndex : "<< j << ":"<<randIndex<<endl;
            }
            else cout <<"randIndex : "<< j << ":"<<randIndex<<endl;
            // pearls[1][j] = pearls[0][randIndex];
            // pearls[0][randIndex] = 0;
        }
    }
    // Display all pearls in each blow
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 10 ; j++){
            if(j == 5 ){
                cout <<"\n";
            }
            if(pearls[i][j] <= 5 && pearls[i][j] > 0){
                cout <<"\x1b[32m"<<pearls[i][j]<<"\t";
            }else if(pearls[i][j] == 0){
                cout <<"\x1b[37m"<<pearls[i][j]<<"\t";
            } else cout <<"\x1b[31m"<<pearls[i][j]<<"\t";
        }
        cout <<"\n\n";
    }

    
    return 0;
}