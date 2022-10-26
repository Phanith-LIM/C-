#include <iostream>
#include <vector>
struct EmployeesWorkTime {
    int index;
    int sunday;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int totalHour = sunday + monday + tuesday + wednesday + thursday + friday + saturday;
};
int main(){
    std::vector<EmployeesWorkTime> employees  = {
        {0,2,4,3,4,5,8,8},
        {1,7,3,4,3,3,4,4},
        {2,3,3,4,3,3,2,2},
        {3,9,3,4,7,3,4,1},
        {4,3,5,4,3,6,3,8},
        {5,3,4,4,6,3,4,4},
        {6,3,7,4,8,3,8,4},
        {7,6,3,5,9,2,7,9},
    };
    
    for (int i = 0; i < employees.size(); i++){
    for (int j = i + 1; j < employees.size(); j++){
            if(employees.at(i).totalHour < employees.at(j).totalHour){
                std::swap(employees.at(i),employees.at(j));
            }
        }
    }
    std::cout << "\t\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT"<< std::endl;
    for(int i = 0; i < employees.size(); i++){
        std::cout << "[Employee "<< employees.at(i).index <<"] ";
        std::cout <<"\t"<< employees.at(i).sunday <<"\t"<< employees.at(i).monday <<"\t"<< employees.at(i).tuesday <<"\t"<< employees.at(i).wednesday <<"\t"<< employees.at(i).thursday <<"\t"<< employees.at(i).friday <<"\t"<< employees.at(i).saturday <<"\t"<< employees.at(i).totalHour;
        std::cout << std::endl;
    }
    return 0;
}