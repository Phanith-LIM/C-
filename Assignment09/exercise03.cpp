#include <iostream>
class Fan {
private:
    int speed;
    bool isTurnOn;
    float radius;
    std::string color;
public:
    Fan(int speed = 1, float radius = 5, std::string color = "blue", bool isTurnOn = false){
        this->speed = speed;
        this->isTurnOn = isTurnOn;
        this->radius = radius;
        this->color = color;
    }
    void display(){
        std::cout << "speed: " << speed << std::endl;
        std::cout << "radius: " << radius << std::endl;
        std::cout << "color: " << color << std::endl;
        std::cout << "turn: " << (isTurnOn ? "on" : "off") << std::endl;
    }
};
int main(){
    Fan fan1 = Fan(3, 10, "yellow", true);
    Fan fan2 = Fan(2, 5, "blue", false);
    std::cout << "[Fan 1]" << std::endl;
    fan1.display();
    std::cout << "[Fan 2]" << std::endl;
    fan2.display();
    return 0;
}