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
	Stack() { data = "              "; }
	void initializeStack(int stackMaxSize);
	void pushStack(char v);
	void popStack();
	char returnStack();
	void justpopStack();
	int getStackSize();
	char returndata(int index);
	bool result();
	string data;
	int stackSize;
};

void Stack::initializeStack(int stackMaxSize)
{
	stackSize = 0;
}

void Stack::pushStack(char v)
{
	data[stackSize] = v;
	stackSize++;
}

void Stack::popStack()
{
	data[(stackSize) - 1] = 0;
	stackSize--;
	
}

char Stack::returnStack()
{
	char v;
	v = data[stackSize - 1];
	return v;
}

void Stack::justpopStack()
{
	data[(stackSize)-1] = 0;
	stackSize--;
}

int Stack::getStackSize()
{
	return stackSize;
}

char Stack::returndata(int index)
{
	return data[index];
}

bool and_cal(bool first, bool second)
{
	return first && second;
}
bool or_cal(bool first, bool second)
{
	return first || second;
}
bool implict_cal(bool first, bool second)
{
	if ((first == true) && (second == false))
		return false;
	else
		return true;
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
		char temp2 = Buffer[i];
		if (temp == temp2)
		{
			remember = i + 2;
		}
		if (isupper(Buffer[i]))
		{
			if (remember == i)
			{
				operand.pushStack(tolower(Buffer[i]));
			}
			else
				operand.pushStack(temp2);
		}
		else if (islower(Buffer[i]))
		{
			if (Buffer[i] == 'n')
				continue;
			else
				calculate.pushStack(Buffer[i]);
		}
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

	switch (prop)
	{
	case 1:
		int temp_opsize = operand.stackSize;

		bool value[2][2] = {
			{true, true},
			{false, true}
		};
		for (int i = 0; i < 2; i++)
		{
			cout << endl;
			int j = 0;
			int k = 0;
			bool a[10];

			for (; j < temp_opsize; j++)
			{
				if (value[i][0] == true)
				{
					if (isupper(operand.data[j]))
						a[j] = true;
					else
						a[j] = false;
				}
				else
				{
					if (isupper(operand.data[j]))
						a[j] = false;
					else
						a[j] = true;
				}
			}
			Stack copy = calculate;
			while (copy.stackSize > 0)
			{
				if (copy.returnStack() == 'o')
				{
					a[k + 1] = or_cal(a[k], a[k + 1]);
					k++;
					copy.popStack();
				}
				else if (copy.returnStack() == 'a')
				{
					a[k + 1] = and_cal(a[k], a[k + 1]);
					k++;
					copy.popStack();
				}
				else
				{
					a[k + 1] = implict_cal(a[k], a[k + 1]);
					k++;
					copy.popStack();
				}
			}
			value[i][1] = a[k];
			for (int t = 0; t < 2;t++)
			{
				if (value[i][t] == true)
					cout << "T ";
				else
					cout << "F ";
			}
			cout << endl;
		}
		break;
	}


	return 0;
}

