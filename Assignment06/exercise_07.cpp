#include <iostream>
#include <vector>
std::vector<std::vector<double>> addMatrix(std::vector<std::vector<double>> matrixA, std::vector<std::vector<double>> matrixB);
std::vector<std::vector<double>> getMatrix(char nameMatrix);
int main(){
    std::vector<std::vector<double>> matrixA;
    std::vector<std::vector<double>> matrixB;
    std::vector<std::vector<double>> matrixC;
    int row_column = 3;
    std::cout << "[Add Two Matrix]" << std::endl;
    matrixA = getMatrix('A');
    matrixB = getMatrix('B');
    matrixC = addMatrix(matrixA,matrixB);
    std::cout << "[Matrix Added]" << std::endl;
    
    for(int i = 0; i < row_column ; i++){
        std::cout << '[';
        for(int j = 0; j < row_column ; j++){
            std::cout << matrixA.at(i).at(j) << (j != (row_column - 1) ? '\t' : ']');
        }
        std::cout << '\t';
        std::cout << '[';
        for(int j = 0; j < row_column ; j++){
            std::cout << matrixB.at(i).at(j) << (j != (row_column - 1) ? '\t' : ']');
        }
        std::cout << '\t';
        std::cout << '[';
        for(int j = 0; j < row_column ; j++){
            std::cout << matrixC.at(i).at(j) << (j != (row_column - 1) ? '\t' : ']');
        }
        std::cout << std::endl;
    }
    return 0;
}
std::vector<std::vector<double>> getMatrix(char nameMatrix){
    std::vector<double> subMatrix;
    std::vector<std::vector<double>> matrix;
    double x, y, z, k, p, q, m, n ,o;
    std::cout << "Matrix "<<nameMatrix<<" : ";
    std::cin >> x >> y >> z >> k >> p >> q >> m >> n >> o;
    subMatrix.push_back(x);
    subMatrix.push_back(y);
    subMatrix.push_back(z);
    matrix.push_back(subMatrix);
    subMatrix.clear();

    subMatrix.push_back(k);
    subMatrix.push_back(p);
    subMatrix.push_back(q);
    matrix.push_back(subMatrix);
    subMatrix.clear();

    subMatrix.push_back(m);
    subMatrix.push_back(n);
    subMatrix.push_back(o);
    matrix.push_back(subMatrix);
    subMatrix.clear();
    return matrix;
}
std::vector<std::vector<double>> addMatrix(std::vector<std::vector<double>> matrixA, std::vector<std::vector<double>> matrixB){
    std::vector<std::vector<double>> matrixC;
    std::vector<double> subMatrix;
    int row_column = matrixA.size();
    double sum = 0;
    for(int i = 0; i < row_column; i++){
        sum = 0;
        for(int j = 0; j < row_column; j++){
            sum = matrixA.at(i).at(j) + matrixB.at(i).at(j);
            subMatrix.push_back(sum);
        }
        matrixC.push_back(subMatrix);
        subMatrix.clear();
    }
    return matrixC;
}
