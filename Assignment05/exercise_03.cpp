#include <iostream>
#include <algorithm>
#include <cstring>
struct Address {
    int street;
    std::string district;
    std::string khan;
    std::string city;
    void displayAddress(){
        std::cout <<"Address:\t" << street<<", "<<khan<<", "<<district<<", "<<city<< std::endl;
    };
};
struct Marks {
    double chem_mark;
    double maths_mark;
    double phy_mark;
    double total_mark = chem_mark + maths_mark + phy_mark;
    void displayMarks(){
        std::cout <<"Marks:\t\t" << chem_mark <<", "<< maths_mark <<", "<< phy_mark << std::endl;
        std::cout <<"Total Marks:\t" << total_mark << std::endl;
    };
    void getMarts(){
        std::cout << "\tChemistry Mark: ";
        std::cin >> chem_mark;
        std::cout << "\tMath Mark: ";
        std::cin >> maths_mark;
        std::cout << "\tPhysics Mark: ";
        std::cin >> phy_mark;
        total_mark = chem_mark + maths_mark + phy_mark;
    }
};
struct Student {
    int id;
    std::string name;
    int age;
    Address address;
    Marks marks;
    void displayInfo(){
        std::cout << "---------------------------------------------------------------"<< std::endl;
        std::cout << "id:\t\t" << id << std::endl;
        std::cout << "Name:\t\t" << name << std::endl;
        std::cout << "Age:\t\t" << age << std::endl;
        address.displayAddress();
        marks.displayMarks();
    };
};
void sortByID(Student student[],int sizeStudent);
void sortByName(Student student[],int sizeStudent);
void sortByTotalMarks(Student student[],int sizeStudent);
int main(){
    Student student[5] = {
        {1,"Max Planck",89,5,"Kammakor","Sangkat Svay Por"," Battambang"},
        {2,"Leonardo da Vinci",67,3,"Ampil Leu","Kampong Siem","Kampong Cham"},
        {3,"Nicola Tesla",86,007,"Toul Bangka","Khan Russei Kaev","PhnomPenh"},
        {4,"Albert Einstein",76,12,"Sangkat Slor Kram","Sangkat Slor Kram","Siem Reap"},
        {5,"Michael Faraday",75,4,"Prek Mohatep ","Sangkat Svay Por","Battambang"},
    };
    int *sizeStudent = new int;
    char *input = new char;
    *sizeStudent = sizeof(student) / sizeof(student[0]);
    //Let User Enter marks for each student
    for (int i = 0; i < *sizeStudent; i++){
        std::cout<<"Student ID: "<<student[i].id<<std::endl;
        student[i].marks.getMarts();
    }
    //Option for user
    std::cout << "a.Display the student information sort by roll no."<<std::endl;
    std::cout << "b.Display the student information sort by names."<<std::endl;
    std::cout << "c.Display the student information sort by total scores"<<std::endl;
    std::cout << "Enter option : ";
    std::cin >> *input;
    if((*input) == 'a') sortByID(student, *sizeStudent);
    else if((*input) == 'b') sortByName(student, *sizeStudent);
    else if ((*input) == 'c') sortByTotalMarks(student, *sizeStudent);
    else {
        std::cout << "Please Enter Option in Menu"<<std::endl;
        exit(1);
    };
    //Display Information Student after sort
    for (int i = 0; i < *sizeStudent; i++){
        student[i].displayInfo();
    }
    delete sizeStudent;
    delete input;
    return 0;
}
void sortByID(Student student[],int sizeStudent){
    for (int i = 0; i < sizeStudent; i++){
        for (int j = i + 1; j < sizeStudent; j++){
            if(student[i].id < student[j].id){
                std::swap(student[i],student[j]);
            }
        }
    }
}
void sortByName(Student student[],int sizeStudent){
    for (int round = 1; round < sizeStudent; round++){
        for (int i = 0 ; i < sizeStudent - round; i++){
            if((student[i].name.compare(student[i + 1].name)) > 0){
                std::swap(student[i],student[i+ 1]);
            }
        }
    }
}
void sortByTotalMarks(Student student[],int sizeStudent){
    for (int i = 0; i < sizeStudent; i++){
        for (int j = i + 1; j < sizeStudent; j++){
            if(student[i].marks.total_mark > student[j].marks.total_mark){
                std::swap(student[i],student[j]);
            }
        }
    }
}