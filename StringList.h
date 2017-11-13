#pragma once
//结点，双向指针域，数据域为字符指针
struct MyString
{
	char *data;
	MyString* front;
	MyString* next;

	MyString()
	{
		data = NULL, next = NULL,front=NULL;
	}
	MyString(char c[], MyString* m, MyString* n)
	{
		data = c, next = n, front = m;
	}
	MyString(char c[])
	{
		data = c, next = 0, front = 0;
	}
};

class StringList
{
private:
	MyString *head;
	MyString *current;

public:
	StringList();
	~StringList();
	int Length();
	bool Empty();
	void Clear();
	MyString* GetPtr(int pos);
	char* GetLine(int pos);
	MyString* GetCur();
	bool SetLine(int pos, char* c);
	char* PreLine();
	char* NextLine();
	bool Insert(int pos, MyString* m);
	bool Delete(int pos);
	void SetCur(MyString* s);
}
;
