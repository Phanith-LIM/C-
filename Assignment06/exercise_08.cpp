#include <iostream>
#include <vector>
#include <sstream>
std::vector<double> parseDouble(std::string str);
void printList(std::vector<std::vector<double>> listElement);
int main(){
    std::vector<std::vector<double>> listElement;
    std::vector<int> locationsLargest;
    std::string strInput;
    int numList;
    double largestNum;
    std::cout << "Enter the number of rows in the list : ";
    std::cin >> numList;
    fflush(stdin);
    //getList
    for(int i = 0; i < numList ; i++){
        std::cout << "Enter a row : ";
        getline(std::cin, strInput);
        listElement.push_back(parseDouble(strInput));
    }
    largestNum = listElement.at(0).at(0);
    locationsLargest = {0,0};
    for(int i = 0; i < listElement.size(); i++){
        for(int j = 0; j < listElement.at(i).size(); j++){
            if(largestNum < listElement.at(i).at(j)){
                largestNum = listElement.at(i).at(j);
                locationsLargest.clear();
                locationsLargest.push_back(i);
                locationsLargest.push_back(j);
            }
        } 
    } 
    printList(listElement);
    std::cout <<"The location of the largest element in at ("<< locationsLargest.at(0) <<", "<< locationsLargest.at(1) <<')'<< std::endl;
    return 0;
}
std::vector<double> parseDouble(std::string str){
    std::stringstream ss(str);
    std::vector<double> subList;
    double number;
    while(ss >> number){
        subList.push_back(number);
    }
    return subList;
}
void printList(std::vector<std::vector<double>> listElement){
    for(std::vector<double> i : listElement){
        for(double j : i){
            std::cout << j << "     ";
        }
        std::cout << std::endl;
    }
}