#include <iostream>
#include <string>

using namespace std;

template<class T >
class Node
{
public:
	T data;
	Node* next;
	Node(T val)
	{
		data = val;
		next = NULL;
	}
};
template<class T>
class Stack
{
	Node<T>* top;
public:
	Stack()
	{
		top = NULL;
	}
	bool IsEmpty()
	{
		return top == NULL;
	}
	void push(T val)
	{
		Node<T>* newnode = new Node<T>(val);
		if (IsEmpty())
		{
			newnode->next = NULL;
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
	}
	void pop()
	{
		Node<T>* delptr = top;
		top = top->next;
		delete delptr;
	}
	T peek()
	{
		return top->data;
	}
	int size()
	{
		int counter = 0;
		Node<T>* temp = top;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	void display()
	{
		Node<T>* temp = top;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
		cout << endl << endl;
	}
};


string simplify_path(string path)
{
	Stack<string> tempStack;

	string temp;
	for (size_t i = 0; i < path.length(); i++)
	{
		temp = "";
		while (i < path.length() && path[i] != '/')
		{
			temp = temp + path[i];
			i++;
		}
		if (temp.find("..") == 0 && !tempStack.IsEmpty())
		{
			tempStack.pop();
		}
		else if (temp.find(".") == 0)
		{
			continue;
		}
		else if (temp.length() != 0)
		{
			tempStack.push(temp);
		}
	}

	Stack <string> stack;

	while (tempStack.IsEmpty()==false)
	{
		stack.push(tempStack.peek());
		tempStack.pop();
	}
	string simpleString="";
	if (stack.IsEmpty()==false) 
	{
		for (int i = 0; i < stack.size() + 1; i++)
		{
			simpleString = simpleString + '/' + stack.peek();
			stack.pop();
		}
	}
	else
	{
		simpleString = "/";
	}
	return simpleString;
}

int main()
{
	string arr[3] = { "/home/","/../","/home//foo/" };
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Test Case " << i + 1 << endl;
		cout << "Input path : " << arr[i] << endl;
		cout<<"Output path : "<< simplify_path(arr[i])<<endl<<endl;
	}

} 
