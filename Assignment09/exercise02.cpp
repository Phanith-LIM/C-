#include <iostream>
class Account {
private:
    int id;
    float balance;
    float annual_interest_rate;
public:
    Account(int id = 0, float balance = 100, float annual_interest_rate = 0){
        this->id = id;
        this->balance = balance;
        this->annual_interest_rate = annual_interest_rate;
    }
    //Getter
    int getID(){
        return id;
    }
    float getBalance(){
        return balance;
    }
    float getRate(){
        return annual_interest_rate;
    }
    //Setter
    void setID(int id){
        this->id = id;
    }
    void setBalance(float balance){
        this->balance = balance;
    }
    void setRate(float annual_interest_rate){
        this->annual_interest_rate = annual_interest_rate;
    }
    //Method
    float get_monthly_interestRate() {
        return (annual_interest_rate / 100) / 12;
    }
    float get_monthly_interest() {
        return balance * get_monthly_interestRate();
    }
    void withdraw(float number){
        this->balance = balance - number;
    }
    void deposit(float number){
        this->balance = balance + number;
    }
    void display(){
        std::cout << "ID: " << id << std::endl;
        std::cout << "Balance: " << balance <<"$"<< std::endl;
        std::cout << "Monthly interestRate: " << get_monthly_interestRate() << std::endl;
        std::cout << "Monthly interest: " << get_monthly_interest() << std::endl;
    }
};
int main(){
    Account phanith = Account(1122, 20000, 4.5);
    phanith.display();
    return 0;
}