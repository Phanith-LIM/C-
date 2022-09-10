#include <iostream>
void sort_array_2d(int arr[2][5],int row, int column){
  int temp;
	for (int i = 0; i < row * column - 1; ++i) {
		for (int j = 0; j < row * column - 1 - i; ++j) {
			// row = j/m
			// column = j%m
			if (arr[j / column][j % column] > arr[(j + 1) / column][(j + 1) % column]) {
				temp = arr[(j + 1) / column][(j + 1) % column];
				arr[(j + 1) / column][(j + 1) % column] = arr[j / column][j % column];
				arr[j / column][j % column] = temp;
			}
		}
	}
}
int main(){
    int num[2][5] = {{10,4,8,7,6},{1,3,5,9,2}};

    sort_array_2d(num,2,5);

    for (int i = 0 ; i < 2; i++){
        for (int j = 0; j < 5; j++){
            std::cout<< "["<<i<<"]"<<"["<<j<<"]"<<" : "<<num[i][j]<<std::endl;
        }
    }
    return 0;
}