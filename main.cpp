#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>

using std::cin;
using std::string;
using std::cout;
using std::endl;

class Stack
{
public:
	void initializeStack(int stackMaxSize);
	void pushStack(char v);
	char popStack();
	int getStackSize();
	char returndata(int index);
	bool result();

private:
	char* data;
	int stackSize;
};

void Stack::initializeStack(int stackMaxSize)
{
	data = (char*)calloc(stackMaxSize, sizeof(char));
	stackSize = 0;
}

void Stack::pushStack(char v)
{
	data[stackSize] = v;
	stackSize++;
}

char Stack::popStack()
{
	char v;
	v = data[stackSize - 1];
	data[(stackSize) - 1] = 0;
	stackSize--;
	return v;
}

int Stack::getStackSize()
{
	return stackSize;
}

char Stack::returndata(int index)
{
	return data[index];
}

int main(void)
{
	Stack operand;//피연산자 스택
	Stack calculate;//연산자 스택
	int prop, logic, sum;
	int remember= -2;// not 연산자의 인덱스를 기억하기 위한 배열
	int count(0);
	char temp = 'n';
	cin >> prop >> logic >> sum;
	while (getchar() != '\n');
	operand.initializeStack(prop);
	calculate.initializeStack(logic);
	string Buffer;
	getline(cin, Buffer);
	for (int i = 0; i < Buffer.length(); i = i + 2)
	{
		char temp2 = Buffer.at(i);
		if (temp = temp2)
		{
			remember = i + 2;
		}
		if (isupper(Buffer.at(i)))
		{
			operand.pushStack(Buffer.at(i));
		}
		else if (islower(Buffer.at(i)))
		{
			calculate.pushStack(Buffer.at(i));
			if (remember == i)
			{
				Buffer[i] = tolower(Buffer[i]);
			}
		}
		else
			exit(1);
	}
	switch (prop)
	{
	case 1:
		cout << "P ";
		break;
	case 2:
		cout << "P Q ";
		break;
	case 3:
		cout << "P Q R ";
		break;
	default:
		cout << "Error";
		break;
	}
	cout << "RESULT" << endl;

	
	bool** value = new bool* [pow(2, prop)];
	for (int i = 0; i < pow(2, prop);i++)
	{
		value[i] = new bool[prop];
	}
	//bool* value = (bool*)malloc(sizeof(bool) * prop);
	for (int i = 0; i < pow(2, prop);i++)
	{
		cout << endl;
		
	}
	








	return 0;
}















/*
typedef struct _stack
{
	char* data;
	int stacksize;
}stack;


void initializeStack(stack* s, int stackMaxSize)
{
	s->data = calloc(stackMaxSize, sizeof(int));
	s->stacksize = 0;
}

void pushStack(stack* s, char v)
{
	s->data[s->stacksize] = v;
	s->stacksize++;
}

char popStack(stack* s)
{
	char v;
	v = s->data[(s->stacksize) - 1];
	s->data[(s->stacksize) - 1] = 0;
	s->stacksize--;
	return v;
}

int main(void)
{
	stack operand;//피연산자 스택
	stack calculate;//연산자 스택
	int
}*/