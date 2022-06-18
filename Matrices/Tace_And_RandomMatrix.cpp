#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MaxSize = 10; //max size of the square matrices.

void showMatrix(int m[][MaxSize],  int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrix(int m[][MaxSize],  int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << "Enter value (" << i+1 << "," << j+1 << "): ";
            cin >> m[i][j];
        }
    }
}

int traceMatrix(int m[][MaxSize], int rows, int columns){
    int trace = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if( i== j){
                trace += m[i][i];
            }
        }
    }
    return trace;
}

void fillRandomMatrix(int m[][MaxSize],int rows, int columns, int min, int max){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            m[i][j] = min + rand()%(max - min);
        }
    }
}

int main(){
    //definition of variables
    int m[MaxSize][MaxSize], dim; //matrix to get the trace
    int max, min, rows, columns, mRandom[MaxSize][MaxSize]; //variables to random matrix
    int opc;
    time_t t;
    srand( (unsigned) time(&t) );

    cout << "Welcome" << endl;
    do{ 
        //menu
        cout << "What do you want to do?: " << endl;
        cout << "1-Get the trace of a matrix." << endl;
        cout << "2-Get a matrix whit random integer values." << endl;
        cout << "3-Exit" << endl;
        cin >> opc;

        switch(opc){
            case 1:
                cout << "*You have chosen \"Get the trace of a matrix\"* " << endl;
                cout << ">Enter the dimension of the matrix (Max 10): ";
                cin >> dim;
                fillMatrix(m,dim,dim);
                cout << ">The matrix is: " << endl;
                showMatrix(m,dim,dim);
                cout << ">The trace is: ";
                cout << traceMatrix(m,dim,dim) << endl;
                break;
            case 2:
                cout << "*You have chosen \"Get a matrix whit random integer values\"* " << endl;
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
                cout << "The matrix is: " << endl;
                showMatrix(mRandom,rows,columns);
                break;
            case 3:
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }while(opc != 3);

    return 0;
}