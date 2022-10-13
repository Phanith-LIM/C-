#include <iostream>
#include <vector>
struct DateJoin {
    int years;
    int months;
    int days;
};
struct Employees {
    int id;
    std::string name;
    double salary;
    std::string department;
    DateJoin date;
};
DateJoin getDateJoin() {
    DateJoin date;
    bool isNotAllow;
    bool isNotTwelveMonth;
    do{
        isNotAllow = false;
        isNotTwelveMonth = false;
        std::cout << "JoinDate: ";
        std::cin >> date.years >> date.months >> date.days;
        if( date.months < 1 or  date.months > 12){
            std::cout << "\t[Error : Please Enter Month between January to December (1 - 12)]"<<std::endl;
            isNotAllow = true;
            isNotTwelveMonth = true;
        }
        if(!isNotTwelveMonth){
            if((date.months == 9) or ( date.months == 4) or ( date.months == 6) or ( date.months == 2)) {
                if( date.months == 2){
                    if(date.years % 4 == 0){
                        if(date.days > 29){
                            std::cout << "\t[Error : "<< date.years <<"is a Leap Years, The Limit February is 29 days]"<<std::endl;
                            isNotAllow = true;
                            isNotTwelveMonth = true;
                        }
                    }else {
                        if(date.days > 28){
                            std::cout << "\t[Error : "<< date.years <<" is not a Leap Years, The Limit of February is 28 days]"<<std::endl;
                            isNotAllow = true;
                            isNotTwelveMonth = true;
                        }
                    }    
                }
                if((date.months == 4) or (date.months == 6) or (date.months == 9)){
                    if(date.days > 30) {
                        std::cout << "\t[Error : Day in "<< date.months <<" is allow limit 30 day]"<<std::endl;
                        isNotAllow = true;
                        isNotTwelveMonth = true;
                    };
                }
            }else {
                if(date.days > 31) {
                    std::cout << "\t[Error : Day in "<< date.months <<" is allow limit 31 day]"<<std::endl;
                    isNotAllow = true;
                    isNotTwelveMonth = true;
                };
            }
        }
    }while (isNotTwelveMonth && isNotAllow);
    return date;
};
Employees getEmployees(){
    Employees employees;
    std::cout << "ID: ";
    std::cin >> employees.id;
    fflush(stdin);
    std::cout << "Name: ";
    getline(std::cin,employees.name);
    std::cout << "Salary: ";
    std::cin >> employees.salary;
    fflush(stdin);
    std::cout << "Department: ";
    getline(std::cin,employees.department);
    fflush(stdin);
    employees.date = getDateJoin();
    return employees;
}
void printAllInfor(std::vector<Employees> employees);
void printByAscendingSalary(std::vector<Employees> *employees);
void insertEmployees(std::vector<Employees> *employees);
void deletedEmployees(std::vector<Employees> *employees);
void updateEmployees(std::vector<Employees> *employees);
int main(){
    char *option = new char;
    std::vector<Employees> employees = {
        {1234,"Lim Phanith",128.23,"ITE",2002,12,23},
        {2123,"Lim Heng",342.23,"FTE",2001,12,23},
        {5232,"Lim Chila",242.23,"TEE",2003,11,19},
    };
    std::cout << "[Please Enter Option In Menu]" << std::endl;
    std::cout << "Option : ";
    std::cin >> (*option);
    fflush(stdin);
    switch(*option){
        case 'a' : 
            printAllInfor(employees); 
        break;
        case 'b' : 
            printByAscendingSalary(&employees);
        break;
        case 'c' : 
            insertEmployees(&employees);
        break;
        case 'd' : 
            deletedEmployees(&employees);
        break;
        case 'e' : 
            updateEmployees(&employees);
        break;
        default:
            std::cout << "Please enter only option in menu" << std::endl;
        break;
    }
    return 0;
}
void printAllInfor(std::vector<Employees> employees){
    for(int i = 0; i < employees.size(); i++){
        std::cout <<"---------------------------------------------------------------"<< std::endl;
        std::cout <<"Id:\t\t" << employees.at(i).id << std::endl;
        std::cout <<"Name:\t\t" << employees.at(i).name << std::endl;
        std::cout <<"Department:\t" << employees.at(i).department << std::endl;
        std::cout <<"Date:\t\t" << employees.at(i).date.years <<" "<<employees.at(i).date.months<<" "<<employees.at(i).date.days<< std::endl;
        std::cout <<"Salary:\t\t" << employees.at(i).salary << std::endl;
    }
}
void printByAscendingSalary(std::vector<Employees> *employees){
    for(int i = 0; i < employees->size(); i++){
        for(int j = i + 1; j < employees->size();j++){
            if(employees->at(i).salary > employees->at(j).salary){
                std::swap(employees->at(i), employees->at(j));
            }
        }
    }
    printAllInfor(*employees);
}
void insertEmployees(std::vector<Employees> *employees){
    Employees subEmp;
    std::cout << "[Insert New Employees]"<<std::endl;
    subEmp = getEmployees();
    employees->push_back(subEmp);
    printAllInfor(*employees);
}
void deletedEmployees(std::vector<Employees> *employees){
    int id;
    bool isNotFound = false;
    std::cout << "[Delete Employees]"<<std::endl;
    std::cout << "ID Employees : ";
    std::cin >> id;
    for(int i = 0; i < employees->size(); i++){
        if(employees->at(i).id == id){
            employees->erase(employees->begin() + i);
            isNotFound = true;
            break;
        }
    }
    if(isNotFound) printAllInfor(*employees);
    if(!isNotFound) std::cout << "[Error : There are not this "<< id <<" in list of employees]" << std::endl;
}
void updateEmployees(std::vector<Employees> *employees){
    int id;
    bool isNotFound = false;
    std::cout << "[Update Employees Information]"<<std::endl;
    std::cout << "ID Employees : ";
    std::cin >> id;
    for(int i = 0; i < employees->size(); i++){
        if(employees->at(i).id == id){
            employees->at(i) = getEmployees();
            isNotFound = true;
            break;
        }
    }
    if(isNotFound) printAllInfor(*employees);
    if(!isNotFound) std::cout << "[Error : There are not this "<< id <<" in list of employees]" << std::endl;
}