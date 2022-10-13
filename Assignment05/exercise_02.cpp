#include <iostream>
struct Birthday {
    int year;
    int month;
    int day;
};
struct Person {
    int id;
    std::string name;
    Birthday birthday;
};
void compareAge(Person *person1,Person *person2);
int main(){
    Person person[2] = {
        {1,"Lim Phanith",2002,11,19},
        {2,"Joe Biden",2002,11,19},
    };
    compareAge(&person[0],&person[1]);
    return 0;
}
void compareAge(Person *person1,Person *person2) { 
    if((person1->birthday.year == person2->birthday.year) && (person1->birthday.month == person2->birthday.month) && (person1->birthday.day == person2->birthday.day)){
        std::cout << "Birthdays are equal"<<std::endl;
        exit(0);
    }

    if(person1->birthday.year > person2->birthday.year){
        std::cout <<person1->name<< " is younger than "<<person2->name<<std::endl;
        std::cout <<person2->name<< " is older than "<<person1->name<<std::endl;
        exit(0);
    }else if(person1->birthday.year < person2->birthday.year){
        std::cout <<person1->name<< " is older than "<<person2->name<<std::endl;
        std::cout <<person2->name<< " is younger than "<<person1->name<<std::endl;
        exit(0);
    }

    if((person1->birthday.year == person2->birthday.year) && (person1->birthday.month > person2->birthday.month)){
        std::cout <<person1->name<< " is younger than "<<person2->name<<std::endl;
        std::cout <<person2->name<< " is older than "<<person1->name<<std::endl;
        exit(0);
    }else if((person1->birthday.year == person2->birthday.year) && (person1->birthday.month < person2->birthday.month)){
        std::cout <<person2->name<< " is younger than "<<person1->name<<std::endl;
        std::cout <<person1->name<< " is older than "<<person2->name<<std::endl;
        exit(0);
    }
    
    if((person1->birthday.year == person2->birthday.year) && (person1->birthday.month == person2->birthday.month) && (person1->birthday.day > person2->birthday.day)){
        std::cout <<person1->name<< " is younger than "<<person2->name<<std::endl;
        std::cout <<person2->name<< " is older than "<<person1->name<<std::endl;
        exit(0);
    }else if((person1->birthday.year == person2->birthday.year) && (person1->birthday.month == person2->birthday.month) && (person1->birthday.day < person2->birthday.day)){
        std::cout <<person2->name<< " is younger than "<<person1->name<<std::endl;
        std::cout <<person1->name<< " is older than "<<person2->name<<std::endl;
        exit(0);
    }
}