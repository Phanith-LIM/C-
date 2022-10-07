#include <iostream>
struct Address {
    int street;
    std::string district;
    std::string khan;
    std::string city;
    void displayAddress(){
        std::cout <<"Address:\t" << street<<", "<<khan<<", "<<district<<", "<<city<< std::endl;
    };
};
struct Student {
    int id;
    std::string name;
    int age;
    Address address;
    void displayInfo(){
        std::cout << "-------------------------------------"<< std::endl;
        std::cout << "id:\t\t" << id << std::endl;
        std::cout << "Name:\t\t" << name << std::endl;
        std::cout << "Age:\t\t" << age << std::endl;
        address.displayAddress();
    };
};
int main(){
    Student student[5] = {
        {1,"Max Planck",89,5,"Kammakor","Sangkat Svay Por"," Battambang"},
        {2,"Leonardo da Vinci",67,3,"Ampil Leu","Kampong Siem","Kampong Cham"},
        {3,"Nicola Tesla",86,007,"Toul Bangka","Khan Russei Kaev","PhnomPenh"},
        {4,"Albert Einstein",76,12,"Sangkat Slor Kram","Sangkat Slor Kram","Siem Reap"},
        {5,"Michael Faraday",75,4,"Prek Mohatep ","Sangkat Svay Por","Battambang"},
    };
    int sizeObject = sizeof(student) / sizeof(student[0]);
    char *input = new char;
    int *numInput = new int;
    if(input == NULL || numInput == NULL){
        std::cout << "Error! memory not allocated."<<std::endl;
        exit(1);
    }
    std::cout << "a.Display the names of all the students having age entered by the user."<<std::endl;
    std::cout << "b.Display the names of all the students having even roll no."<<std::endl;
    std::cout << "c.Display the information of the student whose roll no entered by the user."<<std::endl;
    std::cout << "Enter option : ";
    std::cin >> (*input);

    if((*input) == 'a'){
        do{
            std::cout << "Enter age : ";
            std::cin >> (*numInput);
        }while((*numInput) < 11 || (*numInput) > 18);
        for (int i = 0; i < sizeObject; i++) if (student[i].age == (*numInput)) student[i].displayInfo();
    }else if((*input) == 'b'){
        for (int i = 0; i < sizeObject; i++) if (student[i].id % 2 == 0) student[i].displayInfo();
    }else if ((*input) == 'c'){
        do{
            std::cout << "Enter roll no : ";
            std::cin >> (*numInput);
        }while((*numInput) > sizeObject);
        student[(*numInput) - 1].displayInfo();
    }
    delete input;
    delete numInput;
    return 0;
}