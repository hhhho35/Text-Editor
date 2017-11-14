#include "stdafx.h"
#include "StringList.h"

//����һ���յ�StringList
StringList::StringList()
{
	head = new MyString();
	current = head;
}

StringList::~StringList()
{
	Clear();
	delete head;
}

//�ж��Ƿ�Ϊ��
bool StringList::Empty()
{
	return head->next == NULL;
}

void StringList::Clear()
{
	while (Length() > 0)
		Delete(1);
}

//���ؿ�����ĳ���
int StringList::Length()
{
	int count = 0;
	for (MyString* tmp = head->next; tmp != NULL; tmp = tmp->next)
	{
		count++;
	}
	return count;
}

//���ص�pos������ָ�룬current����
MyString* StringList::GetPtr(int pos)
{
	MyString* tmp = head;
	int cur = 0;
	while (tmp != NULL&&cur < pos)
	{
		tmp = tmp->next;
		cur++;
	}
	if (tmp != NULL&&cur == pos)
	{
		current = tmp;
		return tmp;
	}
	else
		return NULL;
}

//��õ�pos����������
char* StringList::GetLine(int pos)
{
	if (pos<1 || pos>Length())
		return NULL;
	MyString* tmp = GetPtr(pos);
	return tmp->data;
}

MyString * StringList::GetCur()
{
	return current;
}

//���ĵ�pos����������
bool StringList::SetLine(int pos, char* c)
{
	if (pos<1 || pos>Length())
		return 0;
	MyString* tmp = GetPtr(pos);
	if (tmp == NULL)
		return 0;
	else {
		int i = 0;
		while (i < 80)
		{
			tmp->data[i] = c[i];
			i++;
		}
		return 1;
	}
}

//���ص�ǰ�����ϸ��������ݣ�current����
char*  StringList::PreLine()
{
	if (current->front == NULL)
		return NULL;
	else
		current = current->front;
		return current->data;
}

//���ص�ǰ�����¸��������ݣ�current����
char*  StringList::NextLine()
{
	if (current->next == NULL)
		return NULL;
	else
		current = current->next;
		return current->data;
}

//�ڵ�ǰ�ĵ�pos�����ǰ�����½�㣬current������������pos
bool StringList::Insert(int pos, MyString* m)
{
	if (pos<1 || pos>Length()+1)
		return 0;
	else
	{
		if (pos == Length()+1)
		{
			MyString* tmp = GetPtr(pos-1);
			tmp->next = m;
			m->front = tmp, m->next = NULL;
		}
		else
		{
			MyString* tmp = GetPtr(pos - 1);
			MyString* tmp2 = tmp->next;
			tmp->next = m, tmp2->front = m;
			m->front = tmp, m->next = tmp2;
			current = m;
		}
		return 1;
	}
}

//ɾ����ǰ��pos����㣬current������ɾ�����pos-1
bool StringList::Delete(int pos)
{
	if (pos<1 || pos>Length())
		return 0;
	else
	{
		if (pos < Length())
		{
			MyString* tmp = GetPtr(pos);
			MyString* tmp2 = tmp->next;
			MyString* tmp3 = tmp->front;
			tmp3->next = tmp2, tmp2->front = tmp3;
			delete tmp;
			current = tmp3;
		}
		else
		{
			MyString* tmp = GetPtr(pos);
			MyString* tmp3 = tmp->front;
			delete tmp;
			current = tmp3;
			tmp3->next = NULL;
		}
		return 1;
	}
}

void StringList::SetCur(MyString* s)
{
	current=s;
}
