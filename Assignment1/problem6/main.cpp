#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class PhoneDirectory
{
private:
    string  fname;
    string  lname;
    string phonenum;
public:
    //vectors to store first name,last name and phone number
    vector<string>firstname;
    vector<string>lastname;
    vector<string>phonenumber;
    int length = 0; // to store the length of vector after adding or deleting entries

    //default constructor
    PhoneDirectory()
    {
        fname = " ";
        lname = " ";
        phonenum = " ";
    }
    //setters and getters
    void SetFirstName(string fn)
    {fname = fn;}
    string GetFirstName()
    {return fname;}
    void SetLastName(string ln)
    {lname = ln;}
    string GetLastName()
    {return lname;}
    void SetPhoneNumber(string pn)
    {phonenum = pn;}
    string GetPhoneNumber()
    {return phonenum;}
    /*add entry fun
    ask user for entering first name,last name and phone number
    then add each to its vector*/
    void Addentry()
    {
        cout << "First name :";
        cin >> fname;
        cout << "Last name :";
        cin >> lname;
        cout << "Phone Number :";
        cin >> phonenum;
        firstname.push_back(fname);
        lastname.push_back(lname);
        phonenumber.push_back(phonenum);
        cout << endl << "contact added successfully..." << endl;
        length++;
    }
    /*lookup by phone number
    search for a user using phone number*/
    void LookupByPhone()
    {
        bool check = false;
        if (length > 0 )
        {
            string num;
            cout << "Enter phone number :";
            cin >> num;
            for (int i = 0; i < length; i++)
            {
                if (num == phonenumber[i])
                {
                    check = true;
                    cout << phonenumber[i] << " this number belongs to '";
                    cout << firstname[i] << " " << lastname[i] << "'" << endl;
                    break;
                }
            }
        }
        if (check == false && length > 0)
        {
            cout << "This phone number doesn't exist.." << endl;
        }
        if (check == false && length == 0)
        {
            cout << "There are no contacts to search for in your directory" << endl;
        }
    }
    /*lookup by first name
    search for a user using his first name*/
    void LookupByFirstName()
    {
        bool check = false;
        if (length > 0)
        {
            string name;
            cout << "Enter First Name :";
            cin >> name;
            /*in the question it isn't clear if there is more than one
            person with the same name, will they all be displayed
            or display the first he found and also in the removal
            so i assumed that they all will be displayed and removed as well*/
            for (int i = 0; i < length; i++)
            {
                if (name == firstname[i])
                {
                    check = true;
                    cout << "Found " << firstname[i] << " as : " << firstname[i] << " " << lastname[i];
                    cout << "    Phone Number : " << phonenumber[i] << endl;
                }
            }
            /*insertion_Sort();
            check = binarySearch(name, length);*/
        }
        if (check == false && length > 0)
        {
            cout << "This name doesn't exist.." << endl;
        }
        if (check == false && length == 0)
        {
            cout << "There are no contacts to search for in your directory" << endl;
        }
    }
    /*delete an entry using first name*/
    void DeleteEntry()
    {
        bool check = false;
        if (length > 0)
        {
            string name;
            cout << "Enter the First Name from the contact you want to Delete :";
            cin >> name;
            for (int i = 0; i < length; i++)
            {
                if (name == firstname[i])
                {
                    check = true;
                    cout << "Contact " << firstname[i] << " " << lastname[i];
                    firstname[i].erase();
                    lastname[i].erase();
                    phonenumber[i].erase();
                    cout << " Is deleted successfully " << endl;
                    length--;
                    //break;
                }
            }
        }
        if (check == false && length > 0)
        {
            cout << "This name doesn't exist.." << endl;
        }
        if (check == false && length == 0)
        {
            cout << "There are no contacts to delete in your directory" << endl;
        }
    }
    /*list fun will print vectors if there are a contacts using 3 ways for sorting randomly*/
    void List()
    {
        if (length == 0)
        {
            cout << "your contact Directory is empty" << endl;

        }
        else
        {
            int Random = rand() % 3 + 1;
            if (Random == 1)
            {
                insertion_Sort();
            }
            else if (Random == 2)
            {
                bubble_Sort();
            }
            else
            {
                shell_Sort();
            }
            cout << "Your contacts.." << endl;
            cout << "  -Name-        ||       -Phone Number-" << endl;
            for (int i = 0; i < firstname.size(); i++)
            {
                cout << firstname[i] << " " << lastname[i];
                cout << "               " << phonenumber[i] << endl;
            }
        }
    }
    //sort vectors using insertion sort
    void insertion_Sort()
    {
        for (int i = 1, j; i < firstname.size(); i++)
        {
            string temp1 = firstname[i];
            string temp2 = lastname[i];
            string temp3 = phonenumber[i];
            for (j = i; j > 0 && temp1 < firstname[j - 1]; j--)
            {
                firstname[j] = firstname[j - 1];
                lastname[j] = lastname[j - 1];
                phonenumber[j] = phonenumber[j - 1];
            }
            firstname[j] = temp1;
            lastname[j] = temp2;
            phonenumber[j] = temp3;
        }
    }
    //sort vectors using bubble sort
    void bubble_Sort()
    {
        for (int i = 0; i < (firstname.size() - 1); i++)
        {
            for (int j = (firstname.size() - 1); j > i; j++)
            {
                if (firstname[j] < firstname[j - 1])
                {
                    swap(firstname[j], firstname[j - 1]);
                    swap(lastname[j], lastname[j - 1]);
                    swap(phonenumber[j], phonenumber[j - 1]);
                }
            }
        }
    }
    //sort vectors using shell sort
    void shell_Sort()
    {
        for (int interval = length / 2; interval > 0; interval /= 2)
        {
            for (int i = interval; i < length; i++)
            {
                string temp1 = firstname[i];
                string temp2 = lastname[i];
                string temp3 = phonenumber[i];
                int j = i;
                while (j >= interval && firstname[j - interval] > temp1)
                {
                    firstname[j] = firstname[j - interval];
                    lastname[j] = lastname[j - interval];
                    phonenumber[j] = phonenumber[j - interval];
                    j -= interval;
                }
                firstname[j] = temp1;
                lastname[j] = temp2;
                phonenumber[j] = temp3;
            }
        }
    }
    //binary search to search in the vector after sorting it
    /*bool binarySearch(string key, int size)
    {
        int low = 0;
        int high = size - 1;
        bool check = false;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int res = -1;
            if (key == (firstname[mid]))
            {
                res = 0;
            }
            if (res == 0)
            {
                cout << "Found " << firstname[mid] << " as " << firstname[mid] << " " << lastname[mid] ;
                cout << "    Phone Number : " << phonenumber[mid] << endl;
                return true;
            }
            if (key > (firstname[mid]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }*/
};
int main()
{   //user menu
    cout << "1. Add an entry to the directory" << endl;
    cout << "2. Look up a phone number" << endl;
    cout << "3. Look up by first name" << endl;
    cout << "4. Delete an entry from the directory" << endl;
    cout << "5. List All entries in phone directory" << endl;
    cout << "6. Exit form this program" << endl;
    int choice;
    PhoneDirectory obj;
    bool flag = true;
    while (flag)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "please enter your choice : ";
        cin >> choice;
        //if user enter 1 to add a contact
        if (choice == 1)
        {
            obj.Addentry();
        }
        //if user enter 2 to look for a contact by phone number
        if (choice == 2)
        {
            obj.LookupByPhone();
        }
        //if user enter 3 to look for a contact by first name
        if (choice == 3)
        {
            obj.LookupByFirstName();
        }
        //if user enter 4 delete a contact
        if (choice == 4)
        {
            obj.DeleteEntry();
        }
        //if user enter 5 list all contacts
        if (choice == 5)
        {
            obj.List();
        }
        //if user enter 6 exit
        if (choice == 6)
        {
            cout << "Exit.." << endl;
            flag = false;
        }
        // if user enter number doesn't exist in the menu
        if (choice > 6 )
        {
            cout << "This choice is not available...";
            cout << "please Enter a correct choice" << endl;
        }
    }
    return 0;
}
