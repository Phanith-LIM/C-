#include <iostream>
#include <map>
#include <iomanip>
void displayMap(std::map < short int, std::map < short int , std::map < char, float>>> student);
std::map < short int, std::map < short int , std::map < char, float>>> getScore();
int main(){
    std::map < short int, std::map < short int , std::map < char, float>>> student;
    student = getScore();
    displayMap(student);
    return 0;
}
std::map < short int, std::map < short int , std::map < char, float>>> getScore(){
    std::map < short int, std::map < short int , std::map < char, float>>> student;
    std::cout << "[ENTER SCORE STUDENT]" << std::endl;
    for(int i = 1; i <= 2; i++){
        std::cout << "GROUP: " << i << std::endl;
        std::cout << "•••••••••••••••••••••••••••••••••••••••••••••••••••••••" << std::endl;
        for (int j = (i == 2 ? j = 4 : j = 0); j < (i * 4); j ++){
            std::cout << "STUDENT: "<< j + 1 << std::endl;
            std::cout << " - maths: ";
            std::cin >> student[i][j]['m'];
            std::cout << " - physics: ";
            std::cin >> student[i][j]['p'];
            std::cout << " - chemistry: ";
            std::cin >> student[i][j]['c'];
            student[i][j]['t'] = student[i][j]['m'] + student[i][j]['p'] + student[i][j]['c'];
        }
    }
    return student;
}
void displayMap(std::map < short int, std::map < short int , std::map < char, float>>> student){
    double total_score = 0;
    for(auto i : student){
        total_score = 0;
        std::cout << "Group: " << i.first << std::endl;
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << std::setw(15) << std::left << "Name" << std::setw(15) << std::left << "Maths" << std::setw(15) << std::left << "Physics" << std::setw(15) << std::left << "Chemistry" << std::setw(15) << std::left << "Total" << std::endl;
        std::cout << "----------------------------------------------------------------------" << std::endl;
        for(auto j : i.second){
            total_score = total_score + j.second.at('t');
            std::cout << "Student " << std::setw(7) << std::left << j.first + 1;
            std::cout << std::setw(15) << std::left << j.second.at('m') << std::setw(15) << std::left << j.second.at('p') << std::setw(15)<< std::left << j.second.at('c') << std::setw(15) << std::left <<  j.second.at('t');
            std::cout << std::endl;
        }
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << std::setw(60) << std::right << "Total Score: " << total_score << std::endl;
    }
}