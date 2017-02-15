#include"MyString.h"

//Constructors//
MyString::MyString()
{
	sizeOfWord = 0;
	word = new char [sizeOfWord + 1];
	word[0] = '\0';
}

MyString::MyString(char* w)
{
	if (w == NULL)
	{
		word = NULL;
		sizeOfWord = 0;
	}
	else
	{
		sizeOfWord = strlen(w);
		word = new char [sizeOfWord + 1];
		strcpy(word,w);
	}
}

MyString::MyString(char l, int s)
{
	sizeOfWord = s;

	if (sizeOfWord <= 0 || sizeOfWord > 300)
	{
		cout << "The size can only be between 1-300" << endl;
		exit(1);
	}

	word = new char[sizeOfWord];

	int i;

	for (i = 0; i < sizeOfWord; i++)
	{
		*(word + i) = l;
	}

	word[i] = NULL;
}

//Copy constructor//
MyString::MyString(const MyString &right)
{
	sizeOfWord = right.sizeOfWord;
	word = new char [sizeOfWord + 1];

	if (right.word == NULL)
	{
		word = NULL;
		sizeOfWord = 0;
	}
	else
	{
		strcpy(word, right.word);
	}
}

//Destructor//
MyString::~MyString()
{
	if (sizeOfWord != 0)
	{
		delete [] word;
	}
}

//**************************************************************************************************************************//

//Convert constructors//
MyString::operator char* () const
{
	return word;
}

MyString::operator string () const
{
	return word;
}


//**************************************************************************************************************************//

//Operators overloading - member functions//
MyString MyString::operator=(MyString right)
{
	if (sizeOfWord != 0)
	{
		delete [] word;
	}

	if (right.word == NULL)
	{
		word = NULL;
		sizeOfWord = 0;
		return *this;
	}

	word = new char [(right).sizeOfWord + 1];
	strcpy(word, right.word);
	sizeOfWord = (right).sizeOfWord;
	return *this;

}

char MyString::operator[] (int i) const
{
	if (i < 0 || i >= sizeOfWord)
	{
		return '~';
	}

	return word[i];
}

MyString MyString::operator+=(string right)
{
	char* temp = word;
	word = new char [sizeOfWord + right.length() + 1];
	strcpy(word, temp);
	strcat(word, right.data());

	if (sizeOfWord != 0)
	{
		delete [] temp;
	}

	sizeOfWord += right.length();
	return *this;
}

//**************************************************************************************************************************//

//Operator overloading - friend functions//
bool operator==(MyString left, MyString right)
{
	return strcmp(left.word, right.word) == 0;
}

bool operator!=(MyString left, MyString right)
{
	return strcmp(left.word, right.word) != 0;
}

bool operator<(MyString left, MyString right)
{
	return strcmp(left.word, right.word) < 0;
}

bool operator>(MyString left, MyString right)
{
	return strcmp(left.word, right.word) > 0;
}

ostream & operator<<(ostream &out, MyString obj)
{
	out << obj.word;
	return out;
}

istream & operator>>(istream &in, MyString &obj)
{
	char buffer[SIZE];
	in.getline(buffer,SIZE);
	obj = buffer;
	return in;
}

//**************************************************************************************************************************//

