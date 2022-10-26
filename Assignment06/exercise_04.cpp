#include <iostream>
#include <vector>
std::vector<double> sumByColumn (std::vector<std::vector<double>> matrix);
int main(){
    std::vector<std::vector<double>> matrix;
    std::vector<double> subMatrix;
    double x, y, z, k;
    int row = 3;
    int column = 4;
    for(int i = 0; i < row; i++){
        std::cout << "Enter a "<<row<<"-by-"<<column<<" matrix for row "<< i << " : ";
        std::cin >> x >> y >> z >> k;
        subMatrix.push_back(x);
        subMatrix.push_back(y);
        subMatrix.push_back(z);
        subMatrix.push_back(k);
        matrix.push_back(subMatrix);
        subMatrix.clear();
    }
    subMatrix = sumByColumn(matrix);
    for(int i = 0; i < subMatrix.size(); i++){
        std::cout << "Sum of the elements of column "<< i << " is "<< subMatrix.at(i) << std::endl;
    }
    return 0;
}
std::vector<double> sumByColumn (std::vector<std::vector<double>> matrix){
    std::vector<double> listSumMatrix;
    int column = matrix[0].size();
    int row = matrix.size();
    int subColumn = 0;
    double sumValue;
    for(int k = 0 ; k < column ; k++){
        sumValue = 0;
        for(int i = 0; i < row ; i++){
            for(int j = subColumn; j < subColumn + 1; j++){
                sumValue = sumValue + matrix.at(i).at(j);
            }
        }
        subColumn++;
        listSumMatrix.push_back(sumValue);
    }
    return listSumMatrix;
}