#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class StudentName
{
    string name;
public:
    //constructor
    StudentName(string n)
    {
        int spaces = 0, indexofspace;
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] == ' ')
            {
                spaces++;
                indexofspace = i;
            }
        }
        if (spaces == 0)
        {
            name = n + ' ' + n + ' ' + n;
        }
        else if (spaces == 1)
        {
            name = n + n.substr(indexofspace);
        }
        else if (spaces >= 2)
        {
            name = n;
        }
    }
    //fun that print name
    void print()
    {
        cout << "(1)";
        int j = 2;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                cout << name[i];
            }
            else if (name[i] == ' ')
            {
                cout << endl;
                cout <<"(" << j << ")";
                j++;
            }
        }
        cout << endl;
    }
    //Replace function
    bool Replace(int i, int j)
    {
        string arr[10];
        string substring = "";
        int k = 0;
        //loop for dividing name and insert into arr
        for (int i = 0; i < name.length();)
        {
            if (name[i] != ' ')
            {
                substring += name[i];
            }
            if (name[i] == ' ')
            {
                arr[k] = substring;
                k++;
                substring = "";
            }
            i++;
            if (i == name.length())
            {
                arr[k] = substring;
            }
        }
        int sizeofarr = k + 1;
        if (i > sizeofarr || j > sizeofarr)
        {
            return false;
        }
        else
        {
            //replacing of two names
            string temp = arr[i - 1];
            arr[i - 1] = arr[j - 1];
            arr[j - 1] = temp;
            name = "";
            for (int i = 0; i < sizeofarr; i++)
            {
                if (i == (sizeofarr - 1))
                {
                    name = name + arr[i];
                }
                else
                {
                    name = name + arr[i] + ' ';
                }
            }
            return true;
        }
    }
};
int main()
{
        string arr[5] = { "asmaa omar refaat ahmed mohamed","nadeen Ahmed",
                          "toka","asmaa omar refaat ahmed" ,"asmaa omar refaat" };

        for (int i = 0; i < 5; i++)
        {
            string name = arr[i];
            StudentName obj(name);
            int Randomint1 = rand() % 5 + 1;
            int Randomint2 = rand() % 4 + 1;
            cout << "Case(" << i + 1 << ")" << endl;
            cout << "Name:" << name << " | Replecment Number: " << Randomint1 << ", " << Randomint2 << endl;
            if (obj.Replace(Randomint1, Randomint2))
            {

                cout << "True" << endl;
                obj.print();
                cout << endl;
            }
            else
            {
                cout << "False" << endl;
                obj.print();
                cout << endl;
            }
        }
    return 0;
}
