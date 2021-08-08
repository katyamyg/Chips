#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class row_of_chips 
{
private:
    string line;
    char one;  //Символы последовательности цветов
    char two;
    char three;
public:
    row_of_chips(string s, char on, char tw, char th);
    string sorting(string s);  //Метод сортировки
    void print(string s);  //Метод печати каждого хода
};

row_of_chips::row_of_chips(string s, char on, char tw, char th)
{
    line = s;
    one = on;
    two = tw;
    three = th;
}

string row_of_chips::sorting(string s)
{
    int pos = 0; //Номер текущей позиции
    int n;       //Номер найденной позиции
    char now;    //Текущий символ из заданной последовательности цветов
    char help;   //Вспомогательная переменная для перестановки символа
    if (s.length() >= 3)
    { 
        while ( pos <= s.length())
        {
            if (s.find(one, pos) != -1)
                now = one;
            else if (s.find(two,pos) != -1)
                now = two;
            else if (s.find(three,pos) != -1)
                now = three;
            if (s[pos] != now)
            {
                n = s.find_first_of(now,pos+1);
                help = s[n];
                s[n] = s[pos];
                s[pos] = help;
            }
            row_of_chips::print(s);
            pos++;
        }
    }
    else cout << "Ошибка! N < 3." << endl;
}

void row_of_chips::print(string s)
{
    std::cout << s << "\n";
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Ошибка! Требуется аргумент." << endl;
        exit (1);
    }
    string chain;   //Последовательность цветов, исходя из которой надо отсортировать ряд фишек 
    chain = argv[1];
    char prior1 = chain[0]; //Присваиваем переменной первый элемент последовательности
    char prior2 = chain[1]; //Присваеваем второй эл-т
    char prior3 = chain[2]; //Присваиваем третий эл-т

    cout << "Введите исходный ряд фишек: " << endl;
    string line;
    cin >> line;
    row_of_chips X(line, prior1, prior2, prior3);
    X.sorting(line);

    return (0);
}
