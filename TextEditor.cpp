// TextEditor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"StringList.h"

void welcome();
void help();
void myExit();
void myBack();
void editFile(StringList* newstr);
void readFile();
void save(StringList* newstr);
void statistics(StringList* newstr);
void searchSubStr(StringList* newstr);
void replaceSubStr(StringList* newstr);
void InsertStr(StringList* newstr);

int main()
{
	welcome();
	char c1;
	do
	{
		cout << "������ָ�" ;
		cin >> c1;
		while (c1!='r'&&c1!='h'&&c1!='x')
		{
			cout << "��������ȷ��ָ�" ;
			cin >> c1;
		}
		switch (c1)
		{
		case'r':
			readFile();
			break;
		case'h':
			help();
			break;
		default:
			break;
		}
	} while ((c1)!='x');
	myExit();
    return 0;
}

void welcome()
{
	cout << "��ӭʹ���б༭����designed by LY " << endl;
	cout << "��������л����Ļ����е��ı��༭����" << endl;
	cout << "�����ļ�������r���˳�ϵͳ������x������������h�����ִ�Сд��" << endl;
	cout << "ף��ʹ����죡" << endl;
	cout << '\n';
}

void help()
{
	cout << "�����ǰ���ģ�飬��Ϊ�����ܱ�������÷���ע������" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "����������h���˳�ϵͳ������x�������ļ�������r�����ִ�Сд��" << endl;
	cout << "�����ļ��ɹ�����ֱ���˳�������b����,����r���¼����ļ�������e���Բ����ļ���copy" << endl;
	cout << "�����ļ���copyʱ������ʹ�����¹��ܣ�" << endl;
	cout << "���浱ǰ�ļ����滻ԭ�ļ�or���������ļ�������s"
		 << '\n' << "ͳ���ļ��������ַ�����S" << '\n' << "���أ�b" << endl;
	cout << "����һ�У�1�������һ�У�9" << '\n' << "��ָ����ĳһ�У�5��";
	cout << "��ǰһ�У�p������һ�У�n" << '\n' << "����һ�У�i��ɾ��һ�У�d���滻ָ���У�R" << endl;
	cout << "�滻ĳ���Ӵ���t������ָ����ĳ���Ӵ���c (ֻ����ָ������)" << endl;
	cout << "------------------------------------------------" << endl;
}

void myExit()
{
	exit(0);
}

void myBack()
{
	cout << '\n' << '\n';
	cout << "------------------------------------------------" << endl;
	char c1;
	do
	{
		cout << "������ָ�";
		cin >> c1;
		while (c1 != 'r'&&c1 != 'h'&&c1 != 'x')
		{
			cout << "��������ȷ��ָ�";
			cin >> c1;
		}
		switch (c1)
		{
		case'r':
			readFile();
			break;
		case'h':
			help();
			break;
		default:
			break;
		}
	} while ((c1) != 'x');
	myExit();
}

void editFile(StringList* newstr)
{
	cout << '\n' << '\n';
	cout << "�����ļ�����ģ��" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�����ļ���copyʱ������ʹ�����¹��ܣ�" << endl;
	cout << "���浱ǰ�ļ����滻ԭ�ļ�or���������ļ�������s"
		 <<'\n'<<"ͳ���ļ��������ַ�����S" << '\n' << "���أ�b" << endl;
	cout << "����һ�У�1�������һ�У�9" << '\n' << "��ָ����ĳһ�У�5��" ;
	cout << "��ǰһ�У�p������һ�У�n"<< '\n' << "����һ�У�i��ɾ��һ�У�d���滻ָ���У�R" << endl;
	cout << "�滻ĳ���Ӵ���t������ָ����ĳ���Ӵ���c (ֻ����ָ������)" << endl;
	char c1;
	do {
		cout << '\n' << "������ָ�";
		cin >> c1;
		while (c1 != 's'&&c1 != 'S'&&c1 != '1'&&c1 != '9'
			&&c1 != 'p'&&c1 != 'n'&&c1 != '5'&&c1 != 'b'
			&&c1 != 'i'&&c1 != 'd'&&c1 != 't'&&c1 != 'c'
			&&c1 != 'R')
		{
			cout << "��������ȷ��ָ�";
			cin >> c1;
		}

		//switch��Ҫ�õľֲ�����
		int pos = 1;
		char c[81] = { 0 };
		int count = 0;
		int i = 0;

		switch (c1)
		{
		case's':
			save(newstr);
			break;
		case'S':
			statistics(newstr);
			break;
		case'1':
			if (newstr->GetLine(1) == NULL)
			{
				cout << "���ļ�Ϊ�գ�û�е�һ��" << endl;
			}
			else
			{
				cout << newstr->GetLine(1) << endl;
			}
			break;
		case'9':
			if (newstr->GetLine(1) == NULL)
			{
				cout << "���ļ�Ϊ�գ�û�����һ��" << endl;
			}
			else
			{
				cout << newstr->GetLine(newstr->Length()) << endl;
			}
			break;
		case'p':
		{
			MyString* s = newstr->GetCur();
			if ( s == newstr->GetPtr(1))
			{
				cout << "�Ѿ��ǵ�һ��" << endl;
				newstr->SetCur(s);
			}
			else
			{
				cout << s->front->data << endl;
				newstr->SetCur(s->front);
			}
			break; 
		}
		case'n':
		{
			MyString* s = newstr->GetCur();
			if (s == newstr->GetPtr(newstr->Length()))
			{
				cout << "�Ѿ������һ��" << endl;
				newstr->SetCur(s);
			}
			else
			{
				cout << s->next->data << endl;
				newstr->SetCur(s->next);
			}
			break; 
}
		case'5':
			cout << "������Ҫ��ʾ������ " ;
			cin >> pos;
			while (newstr->GetLine(pos)==NULL)
			{
				cout<< "��������ȷ������ ";
				cin >> pos;
			}
			cout << newstr->GetLine(pos) << endl;
			break;
		case'i':
			InsertStr(newstr);
			break;
		case'd':
			cout << "������Ҫɾ�������� ";
			cin >> pos;
			while (!newstr->Delete(pos))
			{
				cout << "��������ȷ������ ";
				cin >> pos;
			}
			cout << "ɾ���ɹ�" << endl;
			break;
		case't':
			replaceSubStr(newstr);
			break;
		case'c':
			searchSubStr(newstr);
			break;
		case'R':
			cout << "������Ҫ�滻�����ݣ����Ϊ80���ַ��� ";
			cin >> c;
			cout << "������Ҫ�滻������ ";
			cin >> pos;
			while (!newstr->SetLine(pos, c))
			{
				cout << "��������ȷ������ ";
				cin >> pos;
			}
			cout << "�滻�ɹ�" << endl;
			break;
		default:
			
			break;
		}
	} while (c1 != 'b');
	delete newstr;
	
	myBack();
	
}

void readFile()
{
	cout << '\n' ;
	cout << "�������ļ���" << endl;
	char filename[100] = { 0 };
	cin >> filename;
	fstream f;
	f.open(filename, ios::in);
	while (f.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		cout << "��������ȷ���Ѵ��ڵ��ļ���" << endl;
		cin >> filename;
		f.open(filename, ios::in);
	}
	cout << "�ļ��򿪳ɹ�" << endl;
	StringList* newstr = new StringList();
	int i = 0, j = 1;
	char a[100][81] = { { 0 } };

	//�����ļ��������������ر��ļ�
	while (!f.eof())
	{

		for (i = 0; i < 80; i++)
		{
			if (f.eof())
			{
				break;
			}
			else
			{
				f >> a[j - 1][i];
			}

		}
		MyString* tmp = new MyString(a[j - 1]);
		newstr->Insert(j, tmp);
		j++;	
	}
	f.close();

	//�ļ�����ģ��
	char c1;
	do
	{
		cout << '\n' << "������ָ�";
		cin >> c1;
		while (c1 != 'r'&&c1 != 'h'&&c1 != 'b'&&c1 != 'e')
		{
			cout << "��������ȷ��ָ�";
			cin >> c1;
		}
		switch (c1)
		{
		case'r':
			delete newstr;
			readFile();
			break;
		case'h':
			help();
			break;
		case'e':
			editFile(newstr);
			break;
		default: 
			break;
		}
	} while ((c1) != 'b');
	cout << 12 << endl;
	delete newstr;
	cout << 13 << endl;
	myBack();
}

void save(StringList* newstr)
{
	char name[80] = { 0 };
	cout << "������Ŀ���ļ������������ڽ��Զ����� ";
	cin >> name;
	fstream f;
	f.open(name, ios::out);
	while (f.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		cout << "��������ȷ���ļ��� " ;
		cin >> name;
		f.open(name, ios::out);
	}
	int num = newstr->Length();
	int i = 0,j = 0;
	MyString* m = new MyString();
	for (i=0;i<num-1;i++)
	{
		m = newstr->GetPtr(i + 1);
		j = 0;
		while (m->data[j] != '\0'&&j < 80)
		{
			f << m->data[j];
			j++;
		}
	}
	m = newstr->GetPtr(i + 1);
	j = 0;
	while (m->data[j]!='\0')
	{
		f << m->data[j];
		j++;
	}
	f.close();
	cout << "����ɹ���" << endl;
}

void statistics(StringList* newstr)
{
	cout << "�ļ���������80���ַ�Ϊһ�У��������滻������������ı����һ�м�ʹ����80���ַ���Ȼ����һ�У�" << endl;
	cout << newstr->Length() << endl;
	int num = 80 * (newstr->Length() - 1),i = 0;
	char* c = newstr->GetPtr(newstr->Length())->data;
	while (c[i]!='\0')
	{
		num++, i++;
	}
	cout << "�ļ��е��ַ���Ϊ��" << num;
}

void searchSubStr(StringList* newstr)
{
	int pos = 0;
	cout << "������Ҫ���������� ";
	cin >> pos;
	while (newstr->GetPtr(pos) == NULL)
	{
		cout << "��������ȷ������ ";
		cin >> pos;
	}
	char sub[80] = { 0 };
	cout << "��������Ҫ�������Ӵ� ";
	cin >> sub;
	string *str = new string(newstr->GetPtr(pos)->data);
	int pos2 = str->find(sub);
	if (pos2 == -1)
	{
		cout << "������û�д��Ӵ�" << endl;
	}
	else
	{
		cout << "���Ӵ��ڸ����е�һ�γ��ֵ�λ��Ϊ��" << pos2+1 << "���ַ���" << endl;
	}
}

void replaceSubStr(StringList* newstr)
{
	int pos = 0;
	cout << "������Ҫ���������� ";
	cin >> pos;
	while (newstr->GetPtr(pos) == NULL)
	{
		cout << "��������ȷ������ ";
		cin >> pos;
	}
	string *str = new string(newstr->GetPtr(pos)->data);
	char* c = newstr->GetPtr(pos)->data;
	char sub[80] = { 0 };
	cout << "��������Ҫ�滻���Ӵ� ";
	cin >> sub;
	char trg[80] = { 0 };
	cout << "��������Ҫ���µ��Ӵ� ";
	cin >> trg;
	string s2(sub);
	string s3(trg);
	string::size_type a = s2.size();
	string::size_type b = s3.size();
	int i = 0;
	cout << "��Ҫȫ���滻����1����Ҫ�滻��һ������0" << endl;
	cin >> i;
	if (i == 1)
	{
		string::size_type pos = 0;
		if ((pos = str->find(s2, pos)) != string::npos)
		{
			str->replace(pos, a, s3);
			while ((pos = str->find(s2, pos)) != string::npos)
			{
				str->replace(pos, a, s3);
				pos += b;
			}
			const char* c2 = str->c_str();
			while (c2[i - 1] != '\0')
			{
				c[i - 1] = c2[i - 1];
				i++;
			}
			cout << "�滻�ɹ�" << endl;
		}
		else
		{
			cout << "������û�д��Ӵ�" << endl;
		}	
	}
	else
	{
		string::size_type pos = 0;
		if ((pos = str->find(s2, pos)) != string::npos)
		{
			str->replace(pos, a, s3);
			const char* c2 = str->c_str();
			while (c2[i - 1] != '\0')
			{
				c[i - 1] = c2[i - 1];
				i++;
			}
			cout << "�滻�ɹ�" << endl;
		}
		else
		{
			cout << "������û�д��Ӵ�" << endl;
		}
	}
}

void InsertStr(StringList * newstr)
{
	MyString* m = new MyString();
	int pos = 1;
	char c[81] = { 0 };
	cout << "������Ҫ��������ݣ����Ϊ80���ַ��� ";
	cin >> c;
	int i = 0;
	string *s = new string(c);
	m->data = (char*)s->c_str();
	/*while (i < 80)
	{
		m->data[i] = c[i];
		i++;
	}*/
	cout << "������Ҫ��������� ";
	cin >> pos;
	while (!newstr->Insert(pos, m))
	{
		cout << "��������ȷ������ ";
		cin >> pos;
	}
	cout << "����ɹ�" << endl;
}

/*
fstream f;
f.open("test.txt", ios::in);
while (f.fail())
{
cout << "���ļ�ʧ��" << endl;
cout << "��������ȷ���Ѵ��ڵ��ļ���" << endl;
//cin >> filename;
//f.open(filename, ios::in);
}
cout << "�ļ��򿪳ɹ�" << endl;
StringList* newstr = new StringList();
int i = 0, j = 1;
char a[100][81] = { { 0 } };

//�����ļ��������������ر��ļ�
while (!f.eof())
{

for (i = 0; i < 80; i++)
{
if (f.eof())
{
break;
}
else
{
f >> a[j - 1][i];
}

}
MyString* tmp = new MyString(a[j - 1]);
newstr->Insert(j, tmp);
j++;


}f.close();
cout << newstr->GetLine(1)<<endl;
cout << newstr->GetLine(2)<<endl;
cout << newstr->Length() << endl;
cout << newstr->GetPtr(2) << endl;
cout << newstr->GetPtr(1) << endl;
delete newstr;
*/