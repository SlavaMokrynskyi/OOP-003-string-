#include <iostream>
#include <string>

using namespace std;

class String
{
	char* str;
	int size;
public:
	static int count;
	String(int size, bool isNeedToBeInitialized)
	{
		this->size = size;
		this->str = new char[size];
		if (isNeedToBeInitialized == true)
		{
			cout << "Enter your string -> ";
			cin.getline(this->str, size);
		}
		count++;
	}
	String(int size) : String(size, false) { count++; }
	String() : String(80, false) { count++; }
	void Show(String* str)
	{
		cout << "Yout string: \n" << str->str << "\n";
	}
	~String()
	{
		delete[] str;
		count--;
	}
};

int String::count = 0;

int main()
{
	String str1(100, true);
	str1.Show(&str1);
}
