#include <iostream>
struct DateJoin {
    int years;
    int months;
    int days;
    bool isNotAllow;
    bool isNotTwelveMonth;
    void getDateJoin(){
        do{
            isNotAllow = false;
            isNotTwelveMonth = false;
            std::cout << "JoinDate: ";
            std::cin >> years >> months >> days;
            if(months < 1 || months > 12){
                std::cout << "\t[Error : Please Enter Month between January to December (1 - 12)]"<<std::endl;
                isNotAllow = true;
                isNotTwelveMonth = true;
            }
            if(!isNotTwelveMonth){
                if((months == 9) || (months == 4) || (months == 6) || (months == 9) || (months == 2)) {
                    if(months == 2){
                        if(years % 4 == 0){
                            if(days > 29){
                                std::cout << "\t[Error : "<< years <<"is a Leap Years, The Limit February is 29 days]"<<std::endl;
                                isNotAllow = true;
                                isNotTwelveMonth = true;
                            }
                        }else {
                            if(days > 28){
                                std::cout << "\t[Error : "<< years <<" is not a Leap Years, The Limit of February is 28 days]"<<std::endl;
                                isNotAllow = true;
                                isNotTwelveMonth = true;
                            }
                        }    
                    }
                    if((months == 4) || (months == 6) || (months == 9)){
                        if(days > 30) {
                            std::cout << "\t[Error : Day in "<< months <<" is allow limit 30 day]"<<std::endl;
                            isNotAllow = true;
                            isNotTwelveMonth = true;
                        };
                    }
                }else {
                    if(days > 31) {
                        std::cout << "\t[Error : Day in "<< months <<" is allow limit 31 day]"<<std::endl;
                        isNotAllow = true;
                        isNotTwelveMonth = true;
                    };
                }
            }
        }while (isNotTwelveMonth && isNotAllow);
    };
};
struct Employees {
    int id;
    std::string name;
    double salary;
    std::string department;
    DateJoin date;
    void getEmployees() {
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "Name: ";
        std::cin >> name;
        fflush(stdin);
        std::cout << "Salary: ";
        std::cin >> salary;
        std::cout << "Department: ";
        std::cin >> department;
        fflush(stdin);
        date.getDateJoin();
    };
    void displayEmployees(){
        std::cout <<"---------------------------------------------------------------"<< std::endl;
        std::cout <<"Id:\t\t" << id << std::endl;
        std::cout <<"Name:\t\t" << name << std::endl;
        std::cout <<"Department:\t" << department << std::endl;
        std::cout <<"Date:\t\t" << date.years <<", "<<date.months<<", "<<date.days<< std::endl;
        std::cout <<"Salary:\t\t" << salary << std::endl;
    }
};
void printAllInfor(Employees employees[], int n);
void printByAscendingSalary(Employees employees[], int n);
void printByAscendingDate(Employees employees[], int n);
void printByDepartments(Employees employees[], int n, std::string department);
int main(){
    int *n = new int;
    char *input = new char;
    std::string *department = new std::string;
    if(n == NULL || input == NULL || department == NULL){
        printf("Error! memory not allocated.");
        exit(1);
    }
    do {
        std::cout << "Enter Number of Employees: ";
        std::cin >> (*n);
        if((*n) <= 0){
            std::cout << "\t[Please enter number higher than 0]"<<std::endl;
        }
    }while ((*n) <= 0);
    Employees *employees = new Employees[(*n)];
    if(employees == NULL){
        printf("Error! memory not allocated.");
        exit(1);
    }
    for(int i = 0; i < *n ; i++){
        std::cout << "[Employee "<<i<<"]"<<std::endl;
        employees[i].getEmployees();
        std::cout << std::endl;
    }
    std::cout << "a.Display the employee information."<<std::endl;
    std::cout << "b.Display the employee information in ascending order according to their salary."<<std::endl;
    std::cout << "c.display the employee information in ascending order according to their date of joining."<<std::endl;
    std::cout << "d.display the employee information by departments."<<std::endl;
    std::cout << "Enter option : ";
    std::cin >> *input;
    if((*input) == 'a') printAllInfor(employees,*n);
    else if((*input) == 'b') printByAscendingSalary(employees,*n);
    else if((*input) == 'c') printByAscendingDate(employees,*n);
    else if((*input) == 'd') {
        std::cout << "Enter Department: ";
        std::cin >> *department;
        printByDepartments(employees,*n,*department);
    };
    delete employees;
    delete input;
    delete department;
    delete n;
    return 0;
}
void printAllInfor(Employees employees[],int n){
    for(int i = 0; i < n; i++){
        employees[i].displayEmployees();
    }
}
void printByAscendingSalary(Employees employees[],int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(employees[i].salary > employees[j].salary){
                std::swap(employees[i],employees[j]);
            }
        }
    }
    printAllInfor(employees,n);
}
void printByAscendingDate(Employees employees[],int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(employees[i].date.years > employees[j].date.years){
                std::swap(employees[i],employees[j]);
            }else if((employees[i].date.years == employees[j].date.years) && (employees[i].date.months > employees[j].date.months)){
                std::swap(employees[i],employees[j]);
            }else if((employees[i].date.years == employees[j].date.years) && (employees[i].date.months == employees[j].date.months) && (employees[i].date.days > employees[j].date.days)){
                 std::swap(employees[i],employees[j]);
            }
        }
    }
    printAllInfor(employees,n);
}
void printByDepartments(Employees employees[], int n, std::string department){
    for (int i = 0; i < n; i++)
    {
        if(employees[i].department == department){
            employees[i].displayEmployees();
        }
        if(employees[i].department != department) {
            std::cout << "These are not employees in this "<<department<<std::endl;
        };
    }
}