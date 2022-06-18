#include <iostream>

using namespace std;

const int MaxSize = 10;

void fillMatrix(int m1[][MaxSize], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << "Enter value (" << i+1 << "," << j+1 << "): ";
            cin >> m1[i][j];
        }
    }
}

void showMatrix(int m1[][MaxSize], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
}

int** Product(int m1[][MaxSize], int m2[][MaxSize], int **&mProduct, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            mProduct[i][j] = 0;
            for(int k=0; k<size; k++){
                mProduct[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return mProduct;
}

int main(){
    int size;
    int matrix1[MaxSize][MaxSize], matrix2[MaxSize][MaxSize], matrixProduct[MaxSize][MaxSize], *ptr1[MaxSize], **prt2;
    char option = 'y';

    /* Use of a pointer and a pointer to pointer to pass 
    the matrix "matrixProduct" to function "sumMatrix()" and returner the matrix */
    for(int i=0; i<size; i++){
        ptr1[i] = matrixProduct[i];
    }
    prt2 = ptr1;

    //Begin the interaction and implementation of the program
    cout << "*** Welcome ***" << endl;
    while(option == 'y'){
        cout << "> Enter the number of rows and columns (max 10): ";
        cin >> size; 
        if(size>10){
            do{
             cout << "Max 10 plis: ";
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
        Product(matrix1, matrix2, prt2, size);
        cout << "> The product of the two matrices is: " << endl;
        showMatrix(matrixProduct, size);

        //Validation to continue or exit of implementation
        cout << "Do you want do other product of two matrix? (y/n): ";
        cin >> option;
    }

    return 0;
}