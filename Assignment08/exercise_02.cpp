#include <iostream>
#include <map>
#include <string>
void printInformation(std::map<int , std::map<std::string , std::string>> accounts, int account_no);
void balanceMethod(std::map<int , std::map<std::string , std::string>> *accounts, int account_no, std::string methods);
int checkUser(std::map<int , std::map<std::string , std::string>> accounts);
int main() {
    std::map<int , std::map<std::string , std::string>> accounts = {
        {001,{{"password","12345"},{"name","Lim Phanith"},{"balance","1231.23"}}},
        {002,{{"password","12345"},{"name","Lim Heng"},{"balance","2312.23"}}},
        {003,{{"password","12345"},{"name","Lim Chila"},{"balance","7411.12"}}},
        {004,{{"password","12345"},{"name","Vourt Sokchea"},{"balance","7411.12"}}},
        {005,{{"password","12345"},{"name","Seang Rotha"},{"balance","7411.12"}}},
    };
    char my_char;
    int account_no = checkUser(accounts);
    std::cout << "a. Balance" << std::endl;
    std::cout << "b. Withdraw" << std::endl;
    std::cout << "c. Deposit" << std::endl;
    std::cout << "d. Exit the program." << std::endl;
    std::cout << "Enter Option : ";
    std::cin >> my_char;
    fflush(stdin);
    if(my_char == 'a') balanceMethod(&accounts, account_no, "balance");
    if(my_char == 'b') balanceMethod(&accounts, account_no, "withDraw");
    if(my_char == 'c') balanceMethod(&accounts, account_no, "deposit");
    if(my_char == 'd') exit(1);
    else exit(0);
    return 0;
}
void printInformation(std::map<int , std::map<std::string , std::string>> accounts, int account_no){
    std::cout << "[Your Information]" << std::endl;
    std::cout << "Name : " << accounts[account_no]["name"] <<std::endl;
    std::cout << "Balance : " << stof(accounts[account_no]["balance"]) <<std::endl;
}
int checkUser(std::map<int , std::map<std::string , std::string>> accounts){
    int account_no;
    std::string password;
    bool incorrect_no = 1;
    bool incorrect_pw = 1;
    do{
        std::cout << "[Enter Your Information]" << std::endl;
        std::cout << "Account  : ";
        std::cin >> account_no;
        fflush(stdin);
        std::cout << "Password : ";
        getline(std::cin, password);
        fflush(stdin);
        for(auto e : accounts){
            if(e.first == account_no){
                incorrect_no = 0;
                if(e.second["password"] == password){
                    incorrect_pw = 0;
                    break;
                }
            }
        }
        if(incorrect_no) std::cout << "-Invalid Account ID!" << std::endl;
        if(incorrect_pw) std::cout << "-Invalid Password!" << std::endl;
    }while(incorrect_no || incorrect_pw);
    return account_no;
}
void balanceMethod(std::map<int , std::map<std::string , std::string>> *accounts, int account_no, std::string methods){
    double amount;
    bool isOverage = 0;
    double balance = stof((*accounts)[account_no]["balance"]);
    if(methods == "balance") printInformation(*accounts, account_no);
    if(methods == "withDraw" || methods == "deposit") {
        methods == "withDraw" ? std::cout << "[WithDraw Money]" << std::endl : std::cout << "[Deposit Money]" << std::endl;
        do{
            isOverage = 0;
            std::cout << "amount : ";
            std::cin >> amount;
            fflush(stdin);
            if(amount < 0) {
                std::cout << "Amount must be in positive." << std::endl;
                isOverage = 1;
            }else if(methods == "withDraw"){
                if(amount > balance){
                    std::cout << "Amount is overage balance." << std::endl;
                    isOverage = 1;
                }
            };  
        }while(isOverage);
        if(methods == "withDraw") (*accounts)[account_no]["balance"] = std::to_string((balance - amount));
        if(methods == "deposit") (*accounts)[account_no]["balance"] = std::to_string((balance + amount));
        printInformation(*accounts, account_no);
    }
}