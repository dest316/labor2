#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    double BegInt, EndInt;
    int Count;
    
    double temp;
    cout << "Введите начало и конец отрезка, на котором будет высчитываться интеграл: " << endl;
    cin >> BegInt >> EndInt;
    if (BegInt > EndInt) { swap(BegInt, EndInt); }
    cout << "Теперь введите количество частей, на которое будет разбит отрезок (чем больше частей, тем выше точность)" << endl;
    cin >> Count;
    
    if (Count < 2) { Count = 2; }
    double* fvalue = new double[Count]; 
    cout << "Теперь вводите значения функции на этом отрезке. Должно быть минимум 2 значения - в точке начала и точке конца отрезка: " << endl;
    for (int i = 0; i < (Count); i++)
    {
        //cout << "Значение равно... ";
        //cin >> temp;
        double x = (BegInt + i * ((EndInt - BegInt) / (Count - 1)));
        fvalue[i] = (x*x) + 2*x + 1;
        cout << fvalue[i] << endl; 
       // cout << "_____________________" << endl;
    }
    double valueInt = 0;
    double h = (EndInt - BegInt) / (Count-1);
    for (int i = 0; i < (Count- 1); i++)
    {
        if (((fvalue[i] > 0) && (fvalue[i + 1] < 0)) || ((fvalue[i] < 0) && (fvalue[i + 1] > 0)))
        {
            cout << "Программа не смогла посчитать данный интеграл, поскольку в " << i << "-ом разбиении график переходит через ось Х" << endl;
            cout << "Интеграл равен = <Error>" << endl;
            //delete[] fvalue;
            return 1;
        }
        double a = ((abs(fvalue[i]) + abs(fvalue[i + 1])) / 2);
        
        valueInt += a * h;
    }
    cout << "Интеграл равен = " << valueInt << endl;
    delete[] fvalue;
    return 0;
}

