#include <iostream>
#include <time.h>

using namespace std;

const int MaxSize = 10; //max size of the square matrices.

void fillMatrixZero(int m[][MaxSize],  int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            m[i][j] = 0;
        }
    }
}

void showMatrix(int m[][MaxSize],  int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void fillRandomMatrix(int m[][MaxSize],int rows, int columns, int min, int max){
    srand( time(NULL) );
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            m[i][j] = min + rand()%(max - min);
        }
    }
}

int main(){
    int max, min, mRandom[MaxSize][MaxSize],rows,columns; //variables to random matrix
    time_t t;
    srand( (unsigned) time(&t) );
    cout<< " Welcome " << endl;
    cout << ">Enter the number of rows: ";
    cin >> rows;
    cout << ">Enter the number of columns: ";
    cin >> columns;
    cout << ">Enter the range to generate randoms integer: " << endl;
    cout << "Min: ";
    cin >> min;
    cout << "Max: " ;
    cin >> max;
    fillRandomMatrix(mRandom,rows,columns,min,max);
    showMatrix(mRandom,rows,columns);
    cout << "END!" << endl;
    return 0;
}