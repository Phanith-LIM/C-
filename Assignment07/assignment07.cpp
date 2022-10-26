#include <iostream>
#include <vector>
struct Matrix {
    std::vector<std::vector<std::string>> matrix = {
        {" "," "," "},
        {" "," "," "},
        {" "," "," "},
    };
    std::string getValue(int r, int c){
        return matrix.at(r).at(c);
    }
    void setValue(int r, int c, std::string XO){
        matrix.at(r).at(c) = XO;
    }
};
void displayMatrix(Matrix matrix);
bool checkWinner(Matrix matrix);
bool isXPlayer(int number);
int main(){
    int row, column;
    bool isNotAllow = false;
    Matrix matrix;
    std::cout << "[TicTacToe Game]" << std::endl;
    displayMatrix(matrix);
    for (int i = 0; i < 9; i++){
        do{
            std::cout << "Enter row column for player "<< (isXPlayer(i) ? "X" : "O") << " : ";
            std::cin >> row >> column;
            fflush(stdin);
            isNotAllow = false;
            // isNegative or Out location matrix
            if((row < 0 || row > 2) || (column < 0 || column > 2)){
                std::cout << "[Error : Please enter number in positive or number of row and column"<< std::endl;
                isNotAllow = true;
            }
            //if the old already have the values
            if(!isNotAllow){
                if((matrix.getValue(row, column) == "X") || (matrix.getValue(row, column) == "O")) {
                    std::cout << "[Error : This block already has " << matrix.getValue(row, column) <<"]"<< std::endl;
                    isNotAllow = true;
                }
            }
        }while(isNotAllow);

        if(isXPlayer(i) == true){           // isXPlayer = true : Player X
            matrix.setValue(row, column, "X");
            displayMatrix(matrix);
        }else if(isXPlayer(i) == false){    // isXPlayer = false : Player O
            matrix.setValue(row, column, "O");
            displayMatrix(matrix);
        }
        if(i > 3) {
            //Start Check who is the winner
            if(checkWinner(matrix) == true) break;
            if(i == 8){
                if(checkWinner(matrix) == false){
                    std::cout << "X Player and O Player not one is the winner !!" << std::endl;
                    break;
                }
            }
        }
    }
    return 0;
}
bool isXPlayer(int number){
    if(number % 2 == 0){
        return true;
    }
    return false;
}
bool checkWinner(Matrix matrix){
    bool isWon = false;
    //check Horizontal
    for(int i = 0; i < 3; i++){
        if((matrix.getValue(i, 0)  == "X") && (matrix.getValue(i, 1) == "X") && (matrix.getValue(i, 2) == "X")){
            std::cout << "X Player is the winner!" << std::endl;
            isWon = true;
            break;
        }
        if((matrix.getValue(i, 0)  == "O") && (matrix.getValue(i, 1) == "O") && (matrix.getValue(i, 2) == "O")){
            std::cout << "O Player is the winner!" << std::endl;
            isWon = true;
            break;
        }
    }
    //check Vertical
    for(int i = 0; i < 3; i++){
        if((matrix.getValue(0, i) == "X") && (matrix.getValue(1, i) == "X") && (matrix.getValue(2, i) == "X")){
            std::cout << "X Player is the winner!" << std::endl;
            isWon = true;
            break;
        }
        if((matrix.getValue(0, i) == "O") && (matrix.getValue(1, i) == "O") &&(matrix.getValue(2, i) == "O")){
            std::cout << "O Player is the winner!" << std::endl;
            isWon = true;
            break;
        }
    }
    //check RightDown
    if((matrix.getValue(0, 2) == "X") &&( matrix.getValue(1, 1) == "X") && (matrix.getValue(2, 0) == "X")){
        std::cout << "X Player is the winner!" << std::endl;
        isWon = true;
    }else if((matrix.getValue(0, 2) == "O") &&( matrix.getValue(1, 1) == "O") && (matrix.getValue(2, 0) == "O")){
        std::cout << "O Player is the winner!" << std::endl;
        isWon = true;
    }
    //check Left Down
    if((matrix.getValue(0, 0) == "X") && (matrix.getValue(1, 1) == "X") && (matrix.getValue(2, 2) == "X")){
        std::cout << "X Player is the winner!" << std::endl;
        isWon = true;
    }else if((matrix.getValue(0, 0) == "O") && (matrix.getValue(1, 1) == "O") && (matrix.getValue(2, 2) == "O")){
        std::cout << "O Player is the winner!" << std::endl;
        isWon = true;
    }
    return isWon;
}
void displayMatrix(Matrix matrix){
    std::cout <<"-------------------"<<std::endl;
    std::cout <<"|  "<< matrix.getValue(0, 0) <<"  "<<"|  "<< matrix.getValue(0, 1) <<"  "<<"|  "<< matrix.getValue(0, 2) <<"  |"<<std::endl;
    std::cout <<"-------------------"<<std::endl;
    std::cout <<"|  "<< matrix.getValue(1, 0) <<"  "<<"|  "<< matrix.getValue(1, 1) <<"  "<<"|  "<< matrix.getValue(1, 2) <<"  |"<<std::endl;
    std::cout <<"-------------------"<<std::endl;
    std::cout <<"|  "<< matrix.getValue(2, 0) <<"  "<<"|  "<< matrix.getValue(2, 1) <<"  "<<"|  "<< matrix.getValue(2, 2) <<"  |"<<std::endl;
    std::cout <<"-------------------"<<std::endl;
}