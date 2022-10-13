#include <iostream>
struct Customers {
    int accNumber;
    std::string name;
    double balance;
    void displayInfor(){
        std::cout <<"---------------------------------------------------------------"<< std::endl;
        std::cout <<"Id:\t\t" << accNumber << std::endl;
        std::cout <<"Name:\t\t" << name << std::endl;
        std::cout <<"Balance:\t" << balance << std::endl;
    }
};
void printAllUser(Customers customer[],int n);
void printHighThan600(Customers customer[],int n);
void add300(Customers customer[],int n);
void withdraw100(Customers customer[],int n);
int main(){
    Customers customer[5] = {
        {427058,"Max Planck",892.23},
        {468656,"Leonardo da Vinci",601},
        {474620,"Nicola Tesla",861},
        {427058,"Albert Einstein",476},
        {473263,"Michael Faraday",175},
    };
    // printAllUser(customer,5);
    printHighThan600(customer,5);
}
void printAllUser(Customers customer[],int n){
    for (int i = 0; i < n; i++){
        customer[i].displayInfor();
    }
}
void printHighThan600(Customers customer[],int n){
    for (int i = 0; i < n; i++){
      if(customer[i].balance > 600)  customer[i].displayInfor();
    }
}
void add300(Customers customer[],int n){
    Customers *customer_ptr = &customer[0];
    for (int i = 0; i < n; i++){
        
    }
}