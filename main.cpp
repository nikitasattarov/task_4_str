#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
#include <locale.h>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    setlocale(0, "Russian");
    ifstream input; // создаем объект класса ifstream
    input.open("input.txt"); // открываем файл
    string s;
    string str;
    getline(input, str);
    cout << "Индивидуальное задание: удалить последнюю букву в каждом слове и избавиться от лишних пробелов." << endl;
    cout << "Изначальная строка: " << str << endl;



    bool space = false;
    string res;
    string :: iterator istr = str.begin();
    int size = str.length();

    for (int i = 0; i < size; i++){
        if (*istr == ' ' && space == true){
            istr++;
            continue;
        }
        if (*istr == ' ' && space == false){
            res.push_back(*istr);
            space = true;
            istr++;
        }
        else {
            res.push_back(*istr);
            space = false;
            istr++;
        }

    }
    int i;
    str = res;
    i = str.length();
    if (str[i - 1] == '.'){
        i--;
        str.erase(i);
        while (str[i - 1] == ' '){
            i--;
            str.erase(i);
            i = str.length();
        }
    }

    size = str.length();
    if (str[size - 1] == ' ') str.erase(size - 1, 1);


    //cout << "result (without space) = " << str;
    s = "Строка без пробелов: " + str + "\n";
    res.clear();
    size = str.length();
    for (int i = size - 1; i > 0; i--)
    {
        if (str[i] == '.') continue;
        if (str[i] != ' ') res += str[i];
        else break;
    }
    size = res.length();
    reverse(res.begin(), res.end());
    //cout << "\n\nlast word = " << res;
    s = s + "Последнее слово: " + res + "\n";
    string word, rwl, rwd;
    int sizer;

    size = str.length();
    for (int i = 0; i < size; i++)
    {
        if(str[i] != ' ') word += str[i];
        else if (word != res)
            {   rwd += word;
                rwl += word;
                sizer = rwl.length();
                if (sizer != 0) rwl.erase(sizer - 1, 1);
                rwl += ' ';
                rwd += ' ';
                word.clear();
            }
        else word.clear();

    }
    rwd.erase(rwd.length(), 1);
    res = "";
    str = rwl;
    istr = str.begin();
    size = str.length();

    for (int i = 0; i < size; i++){
        if (*istr == ' ' && space == true){
            istr++;
            continue;
        }
        if (*istr == ' ' && space == false){
            res.push_back(*istr);
            space = true;
            istr++;
        }
        else {
            res.push_back(*istr);
            space = false;
            istr++;
        }

    }

    str = res;
    size = str.length();
    if (str[size - 1] == ' ') str.erase(size - 1, 1);



    s = s + "Строка без последнего слова: " + rwd + "\n";
    s = s + "Строка без последней буквы в каждом слове: " + str + "\n";
    //cout <<"\n\nresult (without last word) = " << resres;
    //cout << "\n\nresult (without last letter) = " << resresres;
    cout << s;
    return 0;
}
