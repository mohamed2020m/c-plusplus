#include<iostream>
#include<string>

using namespace std;

void initialse(int** matrix, int length);
void fillMatrix(int** matrix, int length, string str);
void matrixMultiplication(int** result, int** matrix1, int** matrix2, int length);
void printMatrix(int** matrix, int length, string str);
void free(int** matrix, int length);

int main(){
    // arrya dimenstions
    int n;
    cout << "what's the dimention of your matrix ?" << endl;
    cin >> n;

    cout << "dim of the matrix will be: " << "(" << n << "x" << n << ")" << endl;

    int** first_matrix = new int*[n];
    int** second_matrix = new int*[n];
    int** product_matrix = new int*[n];

    // filling the matrices

    fillMatrix(first_matrix, n, "fill the first matrix:");
    fillMatrix(second_matrix, n, "fill the second matrix:");

    // initialising the product_matrix matrix
    initialse(product_matrix, n);

    // product of first matrix with second_matrix
    matrixMultiplication(product_matrix, first_matrix, second_matrix, n);

    // output the matrices
    printMatrix(first_matrix, n ,"First Matrix:");
    printMatrix(second_matrix, n ,"Seconde Matrix:");
    printMatrix(product_matrix, n ,"The result of multiplication of the two matrices is:");

    // free memory
    free(first_matrix, n);
    free(second_matrix, n);
    free(product_matrix, n);

    return 0;
}

void printMatrix(int** matrix, int length, string str){
    cout << str;
    cout << "{";
    for(int i=0; i < length; i++){
        cout << "{";
        for(int j=0; j < length; j++){
            cout << matrix[i][j];
            if(j < length - 1 ) cout << ", ";
        }
        cout << "}";
        if(i < length - 1 ) cout << ", ";
    }
    cout << "}" << endl;
}


void free(int** matrix, int length){
    for(int k=0; k < length; k++){
        delete [] matrix[k];
    }
    delete [] matrix;
}

void initialse(int** matrix, int length){
    for(int i = 0; i < length; i++){
        int* row = new int[length];
        for(int j = 0; j < length; j++){
            row[j] = 0;
        }
        matrix[i] = row; 
    }
}

void fillMatrix(int** matrix, int length, string str){
    cout << str << endl;
    for(int i = 0; i < length; i++){
        int* row = new int[length];
        for(int j = 0; j <length; j++){
            int m;
            cin >> m;
            row[j] = m;
        }
        matrix[i] = row;  
    }
}

void matrixMultiplication(int** result, int** matrix1, int** matrix2, int length){
    for(int i = 0; i < length; i++){
        int* row = new int[length];
        // initialse row with zeros;
        for(int k = 0; k < length;k++){
            row[k] = 0;
        }
        // multiplication of matrix1 and matrix2
        for(int j = 0; j < length; j++){
            for(int k = 0; k < length; k++){
                row[j] += matrix1[i][k] * matrix2[k][j];
            }
        }
        result[i] = row;
    }
}
