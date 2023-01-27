#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>vectorofelement;

void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        vectorofelement.push_back(soFar);
    else // Still more chars   // For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }
}
// "wrapper" function
void ListPermutations(string s)
{
    RecPermute("", s);
    cout << "The permutations of " << s << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    //sort vector using insertion sort before remove duplicate words
    for (int i = 1, j; i < vectorofelement.size(); i++)
    {
        string temp1 = vectorofelement[i];
        for (j = i; j > 0 && temp1 < vectorofelement[j - 1]; j--)
        {
            vectorofelement[j] = vectorofelement[j - 1];
        }
        vectorofelement[j] = temp1;
    }
    vector<string>tempvector; //insert into tempvector word without duplicate

    string x = vectorofelement[0];
    /*loop to insert word in temporary vector and remove duplicate*/
    for (int i = 1; i < vectorofelement.size();)
    {
        if (x != vectorofelement[i])
        {
            tempvector.push_back(x);
            x = vectorofelement[i];
        }
        i++;
        if (i == vectorofelement.size())
        {
            tempvector.push_back(vectorofelement[i - 1]);
        }
    }
    vectorofelement = tempvector;
    //print vector after removing duplicate words
    for (vector<string>::iterator it = vectorofelement.begin(); it != vectorofelement.end(); it++)
    {
        cout << *it << " | ";
    }

}
int main()
{
    ListPermutations("makka");
    return 0;
}
