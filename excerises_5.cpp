#include <iostream>
using namespace std;
int main(){
    float Bank[5];
    Bank[0] = 446;
    Bank[1] = 250;
    Bank[2] = 375;
    Bank[3] = 200;
    Bank[4] = 306;

    float limitAsset;
    cout << "Enter Limit TotalAsset :  ";
    cin >> limitAsset;

    if (Bank[0] < limitAsset){
        Bank[2] = Bank[2] - 125;
        Bank[3] = Bank[3] - 125;
    }else if(Bank[1] < limitAsset){
        Bank[0] = Bank[0] - 100.5;
    }else if(Bank[2] < limitAsset){
        Bank[1] = Bank[1] - 40;
        Bank[0] = Bank[0] - 125;
    }else if(Bank[3] < limitAsset){
        Bank[1] = Bank[1] - 85;
        Bank[2] = Bank[2] - 75;
    }else if(Bank[4] < limitAsset){
        Bank[0] = Bank[0] - 320.5;
    }

    // for(int i = 0; i < 5 ; i++ ){
    //     cout << " Total Asset Bank "<<i<<" : "<<Bank[i]<<endl;
    // }
    for(int i = 0; i < 5; i++ ){
        if (Bank[i] < limitAsset) cout << "\x1b[31m BANK "<<i<<" : "<<"Unsafe"<<endl;
    }
    return 0;
}