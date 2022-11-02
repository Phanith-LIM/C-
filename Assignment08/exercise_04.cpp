#include <iostream>
#include <map>
int main(){
    std::map <int, double> matrix;
    int index = 0;
    double sum = 0;
    // dimension 3x4 = 12
    for(int i = 0; i < 12; i += 4){
        std::cout << "Enter a 3-by-4 matrix row for row " << index << " : ";
        std::cin >> matrix[i] >> matrix[i + 1]>> matrix[i + 2] >> matrix[i + 3];
        fflush(stdin);
        index++;
    }
    for(int j = 0; j < 4; j++){
        sum = 0;
        for(int i = j; i < (9 + j); i +=4){
            sum = sum + matrix.at(i);
        }
        std::cout <<"Sum of the elements of columns "<< j <<" is " << sum << std::endl;
    }
    return 0;
}