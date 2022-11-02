#include <iostream>
#include <map>
#include <iomanip>
void printEmployees(std::map<int , std::map<std::string , std::string>> employees);
void addInformation(std::map<int , std::map<std::string , std::string>> *employees, int id);
void methodInformation(std::map<int , std::map<std::string , std::string>> *employees, std::string method);
bool checkID(std::map<int , std::map<std::string , std::string>> employees, int id);
int main() {
    std::map<int , std::map<std::string , std::string>> employees = {
        {1212,{{"name","Lim Phanith"},{"salary","543"},{"department","ITE"}}},
        {3231,{{"name","Lim Heng"},{"salary","142"},{"department","FTE"}}},
        {1201,{{"name","Lim Chila"},{"salary","512"},{"department","TTE"}}}
    };
    char my_char;
    std::cout << "a.Display all employees." << std::endl;
    std::cout << "b.Add a new employee." << std::endl;
    std::cout << "c.Delete an employee by id." << std::endl;
    std::cout << "d.Update an employee given an id." << std::endl;
    std::cout << "e.Exit the program." << std::endl;
    std::cout << "Enter Option : ";
    std::cin >> my_char;
    fflush(stdin);
    if(my_char == 'a') printEmployees(employees);
    if(my_char == 'b') methodInformation(&employees, "add");
    if(my_char == 'c') methodInformation(&employees, "remove");
    if(my_char == 'd') methodInformation(&employees, "update");
    if(my_char == 'e') exit(0);
    else exit(1);
    return 0;
}
void printEmployees(std::map<int , std::map<std::string , std::string>> employees){
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::setw(4) << std::left << "ID" <<"\t"<< std::setw(20) << std::left << "Name" << std::setw(15) << std::left << "Salary" << std::setw(15) << std::left << "Department" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    for(auto e : employees){
        std::cout << std::setw(4) << std::left << e.first <<"\t"<< std::setw(20) << std::left << e.second["name"] << std::setw(15) << std::left << e.second["salary"] << std::setw(15) << std::left << e.second["department"] << std::endl;
    }
}
bool checkID(std::map<int , std::map<std::string , std::string>> employees, int id){
    for(auto e : employees) if(e.first == id) return true;
    return false;
}
void addInformation(std::map<int , std::map<std::string , std::string>> *employees, int id){
    std::string str;
    std::cout << "Enter Name : ";
    getline(std::cin, str);
    (*employees)[id]["name"] = str;
    std::cout << "Enter Salary : ";
    getline(std::cin, str);
    (*employees)[id]["salary"] = str;
    std::cout << "Enter Department : ";
    getline(std::cin, str);
    (*employees)[id]["department"] = str;
}
void methodInformation(std::map<int , std::map<std::string , std::string>> *employees, std::string method){
    bool is_found;
    int id;
    if(method == "add" || method == "update" || method == "remove"){
        do{
            std::cout << "Enter ID : ";
            std::cin >> id;
            fflush(stdin);
            is_found = checkID(*employees, id);
            method == "add" ? is_found = is_found : is_found = !is_found;
            if(method == "add") if(is_found == true) std::cout << id <<" has been in the list." << std::endl;
            if(method != "add") if(!is_found == false) std::cout << id <<" does't have in the list." << std::endl;
        }while(is_found);
        if(method == "add") std::cout << "[Add New Employee ID : "<< id <<" ]" << std::endl;
        if(method == "update") std::cout << "[Update Employee ID : "<< id <<" ]" << std::endl;
        if(method != "remove") addInformation(&(*employees), id);
        if(method == "remove") {
            std::cout << "[Remove Employee ID : "<< id <<" ]" << std::endl;
            (*employees).erase(id);
        };
        printEmployees(*employees);
    }else std::cout << "This function is only Add, Update and Remove" << std::endl;
}