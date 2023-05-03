#include <iostream>
#include <cmath>
using namespace std;
double det(int n, double** a);
void Kramer(int n, double** aMain, double* freeVar, double* answer);
int main()
{
    int n;
    cout << "Enter a number of variables "; cin >> n;

    double** aMain;
    aMain = new double* [n];
    double* freeVar;
    freeVar = new double[n];

    double* answer = new double[n];



    for (int i = 0; i < n; i++)
        aMain[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "]="; 
            cin >> aMain[i][j];
        }



    cout << endl << "Please enter free variables" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i << "]=";
        cin >> freeVar[i];
    }

    Kramer(n, aMain, freeVar, answer);




    delete[] aMain;
    delete[] freeVar;
    delete[] answer;
    return 0;


}


double det(int n, double** mat)
{
    double d = 0;
    int c, subi, i, j, subj;
    double** submat;
    submat = new double* [n];
    for (int i = 0; i < n; i++)
        submat[i] = new double[n];

    if (n == 2)
    {
        return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for (c = 0; c < n; c++)
        {
            subi = 0;
            for (i = 1; i < n; i++)
            {
                subj = 0;
                for (j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
        }
    }
    delete[] submat;
    return d;
}

void Kramer(int n, double** aMain, double* freeVar, double* answer)
{
    double* detArray = new double[n];
    double deterMain;
    double* temp = new double[n];
    cout << "Finding determinant of main matrix" << endl;
    cout << "deterMain = "; deterMain = det(n, aMain); cout << deterMain << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j] = aMain[i][j];
            aMain[i][j] = freeVar[j];


        }
        detArray[i] = det(n, aMain);
        for (int k = 0; k < n; k++)
        {
            aMain[i][k] = temp[k];
        }
    }

    for (int i = 0; i < n; i++)
    {
        answer[i] = detArray[i] / deterMain;
        cout << answer[i] << endl;
    }
    delete[] detArray;
    delete[] temp;

}