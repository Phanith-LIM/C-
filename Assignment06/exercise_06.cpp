#include <iostream>
#include <vector>
int main(){
    std::vector<std::vector<double>> studentScore;
    std::vector<double> subScore; 
    double firstNum;
    double secondNum;
    double x, y, z;
    double total;
    for(int i = 0 ; i < 4 ; i++){
        std::cout << "STUDENT "<< i <<std::endl;
        std::cout << "  Subject : ";
        std::cin >> x >> y >> z;
        total = x + y + z;
        subScore.push_back(i);
        subScore.push_back(x);
        subScore.push_back(y);
        subScore.push_back(z);
        subScore.push_back(total);
        studentScore.push_back(subScore);
        subScore.clear();
    }
    for(int i = 0; i < studentScore.size(); i++){
        for(int j = i + 1 ; j < studentScore[i].size() - 1; j++){
            firstNum = studentScore.at(i).at(studentScore.size());
            secondNum = studentScore.at(j).at(studentScore.size());
            if(firstNum < secondNum) {
                std::swap(studentScore.at(i),studentScore.at(j));
            }
        }
    }
    for(int i = 0; i < studentScore.size(); i++){
        std::cout << "STUDENT "<< studentScore.at(i).at(0) <<" :\t";
        for(int j = 1; j < studentScore[i].size() - 1; j++){
            std::cout << studentScore.at(i).at(j) <<"\t";
        }
        std::cout << "TOTAL : " << studentScore.at(i).at(studentScore.size());
        std::cout << std::endl;
    }
    return 0;
}