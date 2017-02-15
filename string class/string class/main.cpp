#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include "MyString.h"

bool testCompare(const char *testName, const char *expectedValue, const char *actualValue)
{
	bool testResult;

	if (!actualValue && expectedValue == "") 
	{
		testResult = true;
	} else {
		testResult = (strcmp(expectedValue, actualValue) == 0);
	}

	cout << "test " << testName << ": ";
	if (testResult) {
		cout << " ok" << endl;
		return true;
	}
	else {
		cout << " FAILED exptected='" << expectedValue << "', actual='" << actualValue << "'" << endl;
		return false;
	}
}

bool test01()
{
	MyString x("hello");
	return testCompare("01", "hello", x);
}

bool test02()
{
	MyString x("hello");
	x = "hi";
	return testCompare("02", "hi", x);
}

bool test03()
{
	MyString x;
	x = "hi";
	x = "how";
	x = "bigger";
	return testCompare("03", "bigger", x);
}

bool test04()
{
	MyString x("hello");
	x = "hi";
	x = "how";
	x = "bigger";
	return testCompare("04", "bigger", x);
}

bool test05()
{
	MyString x("hello");
	x = NULL;
	return testCompare("05", "", x);
}

bool test06()
{
	MyString x("Hi");
	MyString *y = new MyString();
	*y = "Tuesday";
	x = *y;
	delete y;
	return testCompare("06", "Tuesday", x);
}

bool test07()
{
	MyString x = "unequal test";
	MyString y = "not equal";

	char results[5] = { 0, 0, 0, 0, 0 };
	results[0] = ((x == y) ? '1' : '0');
	results[1] = ((x != y) ? '1' : '0');
	results[2] = ((x < y) ? '1' : '0');
	results[3] = ((x > y) ? '1' : '0');
	return testCompare("07", "0101", results);
}

bool test08()
{
	MyString x = "equal test";
	MyString y = "equal test";

	char results[5] = { 0, 0, 0, 0, 0 };
	results[0] = ((x == y) ? '1' : '0');
	results[1] = ((x != y) ? '1' : '0');
	results[2] = ((x < y) ? '1' : '0');
	results[3] = ((x > y) ? '1' : '0');
	return testCompare("08", "1000", results);
}

bool test09()
{
	MyString x;
	MyString y("y");
	for (int i = 0; i < 10; i++)
	{
		x += "x";
		x += y;
	}
	return testCompare("09", "xyxyxyxyxyxyxyxyxyxy", x);
}

bool test10()
{
	MyString x;
	string s("hello");
	x += s;
	return testCompare("10", "hello", x);
}

bool test11()
{
	MyString x;
	string s("hello");
	x += s;
	char results[] = { 0, 0, 0, 0, 0, 0 ,0};
	results[0] = ((x[0] == 'h') ? '1' : '0');
	results[1] = ((x[1] == 'e') ? '1' : '0');
	results[2] = ((x[2] == 'l') ? '1' : '0');
	results[3] = ((x[3] == 'l') ? '1' : '0');
	results[4] = ((x[4] == 'o') ? '1' : '0');
	results[5] = ((x[2] == 'w') ? '1' : '0');
	results[6] = ((x[5] == '~') ? NULL : '!');
	return testCompare("11", "111110", results);
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
	test11();

	_CrtDumpMemoryLeaks();
}


