/* A program to run on console to sum two square matrices of 
max 10 rows and columnswith interaction with the user */

#include <iostream>

using namespace std;

const int MaxSize = 10;

void showMatrix(int m1[][MaxSize], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrix(int m1[][MaxSize], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << "Enter value (" << i+1 << "," << j+1 << "): ";
            cin >> m1[i][j];
        }
    }
}

int** sumMatrix(int m1[][MaxSize], int m2[][MaxSize], int **&mSum, int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            sum = m1[i][j] + m2[i][j];
            mSum[i][j] = sum;
        }
    }
    return mSum;
}

int main(){
    //Definition of variables and matrices
    int size;
    int matrix1[MaxSize][MaxSize], matrix2[MaxSize][MaxSize], matrixSum[MaxSize][MaxSize], *ptr1[MaxSize], **prt2;
    char option = 'y';

    /* Use of a pointer and a pointer to pointer to pass 
    the matrix "matrixSum" to function "sumMatrix()" and returner the matrix */
    for(int i=0; i<size; i++){
        ptr1[i] = matrixSum[i];
    }
    prt2 = ptr1;

    //Begin the interaction and implementation of the program
    cout << "*** Welcome to the sumator of two square matrices ***" << endl;
    while(option == 'y'){
        cout << "> Enter the number of rows and columns (max 10): ";
        cin >> size; 
        if(size>10){
            do{
             cout << "Minor to 10 plis: ";
             cin >> size;
            }while(size>10);
        }

        //Filling of the matrices
        cout << "> Enter the values of first matrix" << endl;
        fillMatrix(matrix1, size);
        cout << "> Enter the values of the second matrix" << endl;
        fillMatrix(matrix2, size);

        //Showing the matrices
        cout << "> The first matrix is: " << endl;
        showMatrix(matrix1, size);
        cout << "> The second matrix is: " << endl;
        showMatrix(matrix2, size);

        //Doing th sum and showing the result matrix
        sumMatrix(matrix1, matrix2, prt2, size);
        cout << "> The sum of the two matrices is: " << endl;
        showMatrix(matrixSum, size);

        //Validation to continue or exit of implementation
        cout << "Do you want sum other two matrix? (y/n): ";
        cin >> option;
    }
    return 0;
}