#pragma once

#include <string>
#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 256;


class MyString
{
private:
	char* word;
	int sizeOfWord;
public:

	//Constructors//
	MyString::MyString();
	MyString::MyString(char* w);
	MyString::MyString(char l, int s); //You asked for it but didn't test for it//

	//Convert constructors//
	operator char* () const;
	operator string () const;

	//Copy constructor//
	MyString::MyString(const MyString &right);

	//Destructor// not working//
	MyString::~MyString();

	//Overloaded operators//
	MyString operator=(MyString right);
	MyString operator+=(string right);
	char operator[] (int) const;

	//Length operator//
	int length() const {return sizeOfWord;}

	//Our friends//
	friend bool operator==(MyString left, MyString right);
	friend bool operator!=(MyString left, MyString right);
	friend bool operator<(MyString left, MyString right);
	friend bool operator>(MyString left, MyString right);
	friend ostream & operator<<(ostream &out, MyString obj);
	friend istream & operator>>(istream &in, MyString &obj);
};