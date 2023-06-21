#include <iostream>
using namespace std;

int main() { 
    int M ;
    int N ; 
    int i, j;
    int** matrix;
    cin >> M;
    cin >> N;

    matrix = new int*[M]; 
    for ( i = 0; i < M; i++) 
        matrix[i] = new int[N];

    int b = 0;
    for ( i = 0; i < M; i++) {
        for ( j = 0; j < N; j++) { 
            // cout << "Inter element " << "[" << i << "][" << j << "]  "; 
            // cin >> matrix[i][j];
            matrix[i][j] = ++b; 
        }
    } 
        

    cout << endl;
    for ( i = 0; i < M; i++) {
        for ( j = 0; j < N; j++) { 
            cout << matrix[i][j] << " "; 
        } 
        cout << endl;
    }
        
}