#include <iostream>
#include <vector>

using namespace std;

//Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int n) {
        data = n;
        left = right = NULL;
    }
};

//BST class
class BST {
public:

    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* r, int val)
    {
        if (r == NULL)
        {
            Node* newnode = new Node(val);
            r = newnode;
        }
        else if (val < r->data)
        {
            r->left = insert(r->left, val);
        }
        else
        {
            r->right = insert(r->right, val);
        }
        return r;
    }
    /*method overloading change in parameters*/
    void insert(int val)
    {
        root = insert(root, val);
    }

    void preorder(Node* r)
    {
        if (r != NULL)
        {
            cout << r->data << "  ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    //function to traverse tree in order(left->root->right) and store elements in a vector
    // the vector will contain numbers asc ordering

    vector<int>vec;  //vector to store element of tree 

    void traverseinorder(Node* r)
    {
        if (r != NULL)
        {
            traverseinorder(r->left);
            vec.push_back(r->data);
            traverseinorder(r->right);
        }
    }
    /*function to sum the kth Smallest element*/

    void ksmallestSum(int key)
    {
        traverseinorder(root);
        int sum = 0;
        cout << "Key = " << key << endl;
        cout << "The " << key << "th Smallest element (";
        for (int i = 0; i < key; i++)
        {
            cout << vec[i] << " ";
            sum = sum + vec[i];
        }
        cout << ")" << endl;
        cout << "Summation of " << key << "th Smallest element is " << sum << endl<<endl;
    }
};

void fun(int arr[], int size, int key)
{
    BST t;
    for (int i = 0; i < size; i++)
    {
        t.insert(arr[i]);
    }
    static int count = 1;
    cout << "(test case " << count << ")" << "\ntree-> ";
    t.preorder(t.root);
    cout << endl;
    t.ksmallestSum(key);
    count++;
}

int main()
{
    /*test case 1
    45 15 79 90 10 55 12 20 50
              45
           /      \
          15      79
        /   \    /   \
       10   20  55    90
         \     /
          12  50
    */
    BST tree1;
    int arr1[9] = { 45,15,79,90,10,55,12,20,50 };
    fun(arr1, 9, 5);
    //-----------------------------------------------------------------------------------------
    /*test case 2
     54 51 75 85 74 52 49
              54
           /      \
          51      75
        /   \    /   \
       49   52  74    85
    */
    BST tree2;
    int arr2[7] = { 54,51,75,85,74,52,49 };
    fun(arr2, 7, 3);
    //--------------------------------------------------------------------------------------------
    /*test case 3
     20 8 4 12 10 14 22
             20
           /    \
          8     22
        /   \
       4     12
            /   \
           10    14
    */
    BST tree3;
    int arr3[7] = { 20,8,4,12,10,14,22 };
    fun(arr3, 7, 4);
    //------------------------------------------------------------------------
    /*test case 4
     8 3 10 1 6 4 7 13 14
              8
           /     \
          3      10
        /   \      \
       1     6      13
            /  \      \
           4    7      14
    */
    BST tree4;
    int arr4[9] = { 8,3,10,1,6,4,7,13,14 };
    fun(arr4, 9, 6);
    //----------------------------------------------
    /*test case 5
      40 45 30 35 32 22 50
               40
            /     \
          30       45
         /   \       \
       22     35      50
             /
            32
     */
    BST tree5;
    int arr5[7] = { 40 ,45 ,30 ,35 ,32 ,22 ,50 };
    fun(arr5, 7, 3);

}
