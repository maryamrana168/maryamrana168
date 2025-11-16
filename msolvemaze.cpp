#include<iostream>
using namespace std;
#include<string>
#ifndef STACK_CLASS
#define STACK_CLASS



template<typename T>
class Stack
{
private:
	T* data;
	int top;
	int capacity;

public:
	Stack(int c);
	Stack(Stack& s);
	~Stack();
	void push(T d);
	T pop();
	Stack& operator=(const Stack& s);
	bool isfull();
	bool isempty();
	int getTop();
	T StackTop();
};

#endif
template<typename T>
Stack<T>::Stack(int c)
{
	if (c > 0) {
		capacity = c;
		data = new T[capacity];
		top = 0;
	}
	else
	{
		throw ("Capacity is negative. Stack object cannot be made.");
	}
}

template<typename T>
Stack<T>::Stack(Stack<T>& s)
{
	if (s.top != 0) {
		capacity = s.capacity;
		top = s.top;
		data = new T[capacity];
		for (int i = 0; i < top; i++)
		{
			data[i] = s.data[i];
		}
	}
	else
	{
		throw ("Copy constructor cannot copy bcz the object passed is empty.");
	}
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

template<typename T>
void Stack<T>::push(T d)
{
	if (!this->isfull())
	{
		data[top] = d;
		top++;
	}
}

template<typename T>
T Stack<T>::pop()
{
	if (!this->isempty())
	{
		top--;
		return data[top];
	}
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s)
{
	if (this != &s)
	{
		this->~Stack();
		capacity = s.capacity;
		top = s.top;
		data = new T[capacity];
		for (int i = 0; i < top; i++)
		{
			data[i] = s.data[i];
		}
		return *this;
	}
	else
	{
		throw ("The stack object passed is already same to the calling object");
	}
}

template<typename T>
bool Stack<T>::isfull()
{
	if (top == capacity)
	{
		return 1;
	}
	return 0;
}

template<typename T>
bool Stack<T>::isempty()
{
	if (top == 0)
	{
		return 1;
	}
	return 0;
}

template<typename T>
int Stack<T>::getTop()
{
	if (!this->isempty())
	{
		return top;
	}
	else
	{
		throw ("Stack is empty. Cannot get the top.");
	}
}

template<typename T>
T Stack<T>::StackTop()
{
	if (!this->isempty())
	{
		return data[top - 1];
	}
}

template class Stack<int>;
template class Stack<double>;
template class Stack<float>;
template class Stack<char>;
typedef struct Pair{
	int i,j;
	Pair(int _i=0, int _j=0){
		i=_i;
		j=_j;
	}
} Pair;

void solvemaze(char ar[6][6], Pair s, Pair d,int row=6, int col=6)
{
	Stack<Pair> st(row*col);
	 
	ar[s.i][s.j] = '.';
	st.push(s);
	while (!st.isempty())
	{
		Pair cur = st.StackTop();
		if(cur.i==d.i && cur.j==d.j)
		{
			cout << "Maze solved.\n";
			cout << "Path is: " << endl;
			while(!st.isempty())
			{
				cout << st.StackTop().i << "," << st.StackTop().j << " ";
				
				st.pop();
			}
			return;
		}
		//right.....
		if(ar[cur.i][cur.j+1]==' ' && cur.j + 1<col)
		{
			ar[cur.i][cur.j+1]='.';
			cur.j++;
			st.push(cur);
		}
		//left...
		else if(ar[cur.i][cur.j-1]==' ' && cur.j - 1 >= 0)
		{
			ar[cur.i][cur.j-1]='.';
			cur.j--;
			st.push(cur);
		}
		//down...
		else if (ar[cur.i + 1][cur.j] ==' '  && cur.i + 1 < row)
		{
			ar[cur.i + 1][cur.j] = '.';
			cur.i++;
			st.push(cur);
		}
		// up...
		else if(ar[cur.i-1][cur.j]==' ' && cur.i - 1 >= 0)
		{
			ar[cur.i - 1][cur.j] = '.';
			cur.i--;
			st.push(cur);
		}
		 
		else 
		{
			st.pop();
		}
	}
	cout << "No path found.\n";
}
int main()
{ 
		char maze1[6][6] = {
		{' ', '*', ' ', '*', ' ', ' '},
		{' ', '*', ' ', '*', ' ', ' '},
		{'P', ' ', ' ', ' ', '*', ' '},
		{'*', ' ', '*', '*', '*', ' '},
		{' ', ' ', ' ', ' ', '*', 'T'},
		{'*', ' ', ' ', ' ', ' ', ' '}
		};
		Pair start = { 2,0 };
		Pair dest = { 4,5 };
		solvemaze(maze1, start, dest, 6, 6);
		char maze2[6][6] = {

		{' ', '*', ' ', '*', ' ', ' '},
		{' ', '*', ' ', '*', ' ', ' '},
		{'P', ' ', ' ', ' ', '*', ' '},
		{'*', '*', '*', '*', '*', ' '},
		{' ', ' ', ' ', ' ', '*', 'T'},
		{'*', ' ', ' ', ' ', ' ', ' '}
		};
		solvemaze(maze2, start, dest, 6, 6);
		return 0;
	 
}
