#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    //open(true) or close(false)
    bool locker[456];
    int numLocker = 456;
    int numOpened = 0;
    int numClosed = 0;

    cout << "\nLocker Puzzle : Squid Game"<<endl;
    for (int i = 0 ; i < numLocker ; i++){
        if (i == 0 ){
            for(int j = 0; j < numLocker; j++){
                locker[j] = true;
            }
        }else if (i == 1 ){
            for(int j = i; j < numLocker; j++ ){
                locker[j] = !locker[j];
            }
        }else if (i >= 2 ){
            for(int j = i; j < numLocker; j = j + i + 1 ){
                locker[j] = !locker[j];
            }
        }
    }
    // Display result
    for (int i = 0; i < numLocker ; i++){
        if (locker[i]) {
            if(numOpened % 10 == 0) cout << "\n";
            printf("\x1b[32m%5d",(i+1));
            numOpened++;
        }
        else {
            numClosed++;
        }
    }
    cout <<"\x1b[37m\n\nLOCKER" <<"\n";
    cout <<"\x1b[32m    Opened : "<<numOpened<<endl;
    cout <<"\x1b[31m    Closed : "<<numClosed<<endl;
}