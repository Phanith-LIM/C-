#include <iostream>
#include <map>
#include <iomanip>
class Employee {
private:
    int id;
    std::string name;
    std::string department;
public:
    Employee(int id, std::string name, std::string department){
        this->id = id;
        this->name = name;
        this->department = department;
    }
    int getID(){
        return id;
    }
    std::string getDepartment(){
        return department; 
    }
    std::string getName(){
        return name; 
    }
    void display(){
        std::cout << std::setw(10) << std::left << id;
        std::cout << std::setw(20) << std::left << name;
        std::cout << std::setw(10) << std::left << department << std::endl;
    }
};
class EmployeeList {
private:
    std::map<int, Employee> employee_list;
public:
    EmployeeList(std::map<int, Employee> employee_list){
        this->employee_list = employee_list;
    }
    void display_all(){
         std::cout << std::setw(10) << std::left << "ID" << std::setw(20) << std::left << "Name" << std::setw(10) << std::left << "Department" << std::endl;
        for(auto i : employee_list){
            i.second.display();
        }
    }
    void add(int id, Employee employee){
        employee_list.insert({id, employee});
    }
    void remove(int id){
        employee_list.erase(id);
    }
    void search_by_id(int id){
        for(auto i : employee_list){
            if(id == i.first)  i.second.display();
        }
    }
    void display_sort_by_name(){
        std::map<std::string, Employee> employee_sort;
        for(auto i : employee_list){
            employee_sort.insert({i.second.getName(), i.second});
        }
        for(auto i : employee_sort){
            std::cout << "ID: " << i.second.getID() << std::endl;
            std::cout << "Name: " << i.second.getName() << std::endl;
            std::cout << "Department: " << i.second.getDepartment() << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }
};
int main(){
    EmployeeList employee_list = EmployeeList({
        {300, Employee(300, "Kratos", "ITE")},
        {301, Employee(301, "Atreus", "FTE")},
        {302, Employee(302, "Thor", "TTE")},
    });
    employee_list.add(303, Employee(303, "Odin", "ASCSE"));
    employee_list.add(304, Employee(304, "Freyr", "ASCSE"))
    employee_list.display_all();
    return 0;
}