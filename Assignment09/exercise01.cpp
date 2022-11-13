#include <iostream>
#include <iomanip>
class Stock{
private:
    std::string symbol;
    std::string name;
    float previous_closing_price;
    float current_price; 
public:
    Stock( std::string symbol, std::string name,  float previous_closing_price, float current_price){
        this->symbol = symbol;
        this->name = name;
        this->previous_closing_price = previous_closing_price;
        this->current_price = current_price;
    }
    float getChangePercent(){
        float change_percent = ((current_price - previous_closing_price) / previous_closing_price) * 100;
        return change_percent;
    }
    //Getter
    std::string getName() {
        return name;
    }
    std::string getSymbol(){
        return symbol;
    }
    float getPreviousPrice() {
        return previous_closing_price;
    }
    float getCurrentPrice() {
        return current_price;
    }
    //Setter
    void setPreviousPrice(float previous_closing_price) {
       this->previous_closing_price = previous_closing_price;
    }
    void setCurrentPrice(float current_price) {
       this->current_price = current_price;
    }
};

int main(){
    Stock macBook = Stock("INTC", "Intel", 20.5, 20.35);
    std::cout << std::setprecision(2) << "Price Change Percentage: " << macBook.getChangePercent() << "%" << std::endl;
    return 0;
}