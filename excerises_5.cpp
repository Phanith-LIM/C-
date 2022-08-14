#include <iostream>
using namespace std;
int main(){
    float Bank[5];
    Bank[0] = 446;
    Bank[1] = 250;
    Bank[2] = 375;
    Bank[3] = 200;
    Bank[4] = 306;

    int numBanks = 5;
    float loanMoney = 0;
    float loanMoney2 = 0;

    float limitAsset;
    cout << "Enter Limit TotalAsset :  ";
    cin >> limitAsset;
    for(int i = 0; i < numBanks; i++ ){
        loanMoney = 0;
        if(i == 0) {
            for(int j = 1; j < 5 ; j = j + 3)
            {
                if(j == 1){
                    loanMoney = 100.5;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }else if(j == 4){
                    loanMoney = 320.5;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }
            } 
        }else if (i == 1){
             for(int j = 2; j < 4 ; j++)
            {
                loanMoney = 0;
                if(j == 2){
                    loanMoney = 40;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }else if(j == 3){
                    loanMoney = 85;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }
            } 
        }else if (i == 2){
            for(int j = 0; j < 4 ; j = j + 3)
            {
                loanMoney = 0;
                if(j == 0){
                    loanMoney = 125;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }else if(j == 3){
                    loanMoney = 75;
                    Bank[j] = Bank[j] + loanMoney;
                    Bank[i] = Bank[i] - loanMoney;
                }
            } 
        }else if(i == 3){
            loanMoney = 125;
            Bank[i-i] = Bank[i-i] + loanMoney;
            Bank[i] = Bank[i] - loanMoney;
        }else if(i == 4){
            loanMoney = 125;
            Bank[i-2] = Bank[i-2] + loanMoney;
            Bank[i] = Bank[i] - loanMoney;
        }
    }

    for(int i = 0; i < numBanks; i++ ){
        cout << " Total Asset Bank "<<i<<" : "<<Bank[i]<<endl;
    }
    for(int i = 0; i < numBanks; i++ ){
        if (Bank[i] >= limitAsset) cout << "\x1b[32m BANK "<<i<<" : "<<"Safe"<<endl;
        else cout << "\x1b[31m BANK "<<i<<" : "<<"Unsafe"<<endl;
    }
    return 0;
}