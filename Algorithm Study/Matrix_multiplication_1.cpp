#include <time.h>
#include <iostream>

#define N 3

using namespace std;

class Matrix {
public:
    Matrix() {}
    void GetData();
    void Display();
    Matrix& Multiply(Matrix&, Matrix&);
private:
    int Term[N][N];
};

void Matrix::GetData() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            Term[i][j] = rand() % 10;
    }
}

void Matrix::Display() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << Term[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}


Matrix& Matrix::Multiply(Matrix& b, Matrix& c) {
    for (int rows = 0; rows < N; rows++)
        for (int cols = 0; cols < N; cols++) {
            int sum = 0;
            for (int i = 0; i < N; i++)
                sum += Term[rows][i] * b.Term[i][cols];
            c.Term[rows][cols] = sum;
            sum = 0;
        }
    return c;
}

int main() {
    srand((unsigned int)time(NULL));
    Matrix a, b, c, d, e;
    a.GetData();
    b.GetData();
    a.Display();
    b.Display();
    e.GetData();
    e.Display();
   
    d.Display();
 

    system("pause");

    return 0;
}