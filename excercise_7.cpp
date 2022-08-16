#include <iostream>
int main(){
    int numPlayer = 6;
    int rounds = 1000;
    int numRandom;
    bool swap = 0;
    int numShot[6] = {0,0,0,0,0,0};
    srand(time(0));
    //Bullets in Gun start firing from Bullets[0]
    for (int p = 0; p < rounds ; p++){
        //Gun's round barrel
        //New round it's mean roll the barrel
        bool Bullets[6] = {1,1,1,1,1,0};
        for (int i = 0; i < numPlayer; i++)
        {
            //If next Player the barrel will roll
            //Swap index to make Random Boolean is mean Bullets is Random
            for (int j = 0; j < numPlayer; j++)
            {
                numRandom = rand() % numPlayer;
                swap = Bullets[0];
                Bullets[0] = Bullets[numRandom];
                Bullets[numRandom] = swap;
            }
            //Check isBullets[0] is 1( have a bullets) so iBullets[0] will change to 1
            for (int k = 0; k < numPlayer; k++)
            {
                if(Bullets[0] == 1) {
                    Bullets[0] = 0;
                    numShot[i]++;
                }
            }
        }
    }
    for (int i = 0; i < numPlayer ;i++){
            std::cout << "\x1b[37mPlayer " <<i+1<<" : Shot " << numShot[i] << " Times"<<std::endl;
     }
    return 0;
}
