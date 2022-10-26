#include <iostream>
#include <map>
#include <iomanip>
void printEmployees(std::map<int , std::map<std::string , std::string>> employees);
int main() {
    std::map<int , std::map<std::string , std::string>> employees = {
            {1212, {{"name","Lim Phanith"},{"salary","543"},{"department","ITE"}}},
            {3231, {{"name","Lim Heng"},{"salary","142"},{"department","FTE"}}},
            {1201, {{"name","Lim Chila"},{"salary","512"},{"department","TTE"}}}
    };
    printEmployees(employees);
    return 0;
}
void printEmployees(std::map<int , std::map<std::string , std::string>> employees){
    std::cout << std::setw(4) << std::left << "ID" <<"\t"<< std::setw(20) << std::left << "Name" << std::setw(10) << std::left << "Salary" << std::setw(10) << std::left << "Department" << std::endl;
    for(auto e : employees){
        std::cout << std::setw(4) << std::left << e.first <<"\t"<< std::setw(20) << std::left << e.second["name"] << std::setw(10) << std::left << e.second["salary"] << std::setw(10) << std::left << e.second["department"] << std::endl;
    }
}