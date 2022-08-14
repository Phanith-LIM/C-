#include <iostream>
int main(){
    int numPlayer = 6;
    int rounds = 10;
    int numRandom;
    bool swap = 0;
    int numDead[6] = {0,0,0,0,0,0};
    int numaLive[6] = {0,0,0,0,0,0};
    //Bullets in Gun start firing from Bullets[0]
    for (int p = 0; p < rounds ; p++){
        //Gun's round barrel
        bool Bullets[6] = {1,1,1,1,1,0};
        std::cout <<"\x1b[37mRound "<< p + 1<< std::endl;
        for (int i = 0; i < numPlayer; i++)
        {
            std::cout << "\x1b[37mP"<<i+1<<":\t";
            //Swap index to make Random Boolean is mean Bullets is Random
            for (int j = 0; j < numPlayer; j++)
            {
                numRandom = rand() % numPlayer;
                swap = Bullets[0];
                Bullets[0] = Bullets[numRandom];
                Bullets[numRandom] = swap;
            }
            //Check isBullets[0] is 1( have a bullets)
            for (int k = 0; k < numPlayer; k++)
            {
                if(Bullets[0] == 1) {
                    Bullets[0] = 0;
                    numDead[i]++;
                    if(Bullets[0] == 0) std::cout <<"\x1b[31m"<<Bullets[k] + 1 <<"\t";
                }else if (i == 0) { 
                    std::cout <<"\x1b[32m"<<Bullets[k]<<"\t";
                }else std::cout <<"\x1b[32m"<<Bullets[k]<<"\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < numPlayer ;i++){
            numaLive[i] = rounds - numDead[i];
            std::cout << "\x1b[37mP" <<i+1<<" : Dead " << numDead[i] << " Times"<<std::endl;

     }
     std::cout << std::endl;
     for (int i = 0; i < numPlayer ;i++){
            std::cout << "\x1b[37mP" <<i+1<<" : a Live " << numaLive[i] << " Times"<<std::endl;
     }
    return 0;
}