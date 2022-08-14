#include <iostream>
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
        }else if (i >= 1 ){
            /*
                if i = 1 => j = 1
                after first loop j = 1 + 2 = 3;
            */
            for(int j = i; j < numLocker; j = j + i + 1 ){
                if(locker[j]) {
                    locker[j] = false;
                }
                else {
                    locker[j] = true;
                }
            }
        }
    }
        
    //Display All
    for (int i = 0; i < numLocker ; i++){
        if(i % 10 == 0) cout << "\n";
        if (locker[i]) {
            cout <<"\x1b[32m"<<i+1<<"\t";
            numOpened++;
        }
        
        else {
            cout << "\x1b[31m"<<i+1 <<"\t";
            numClosed++;
        }
    }
    
    // Display result
    // for (int i = 0; i < numLocker ; i++){
    //     if (locker[i]) {
    //         if(numOpened % 10 == 0) cout << "\n";
    //         cout <<"\x1b[32m"<<i+1 <<"\t";
    //         numOpened++;
    //     }
    //     else {
    //         numClosed++;
    //     }
    // }
    cout <<"\x1b[32m\n\nOpened : "<<numOpened<<endl;
    cout <<"\x1b[31mClosed : "<<numClosed<<endl;
}