// TextEditor.cpp : 定义控制台应用程序的入口点。
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
		cout << "请输入指令：" ;
		cin >> c1;
		while (c1!='r'&&c1!='h'&&c1!='x')
		{
			cout << "请输入正确的指令：" ;
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
	cout << "欢迎使用行编辑器，designed by LY " << endl;
	cout << "本程序具有基本的基于行的文本编辑功能" << endl;
	cout << "读入文件请输入r、退出系统请输入x、帮助请输入h（区分大小写）" << endl;
	cout << "祝您使用愉快！" << endl;
	cout << '\n';
}

void help()
{
	cout << "以下是帮助模块，将为您介绍本程序的用法和注意事项" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "帮助请输入h、退出系统请输入x、读入文件请输入r（区分大小写）" << endl;
	cout << "读入文件成功后不能直接退出，输入b返回,输入r重新加载文件，输入e可以操作文件的copy" << endl;
	cout << "操作文件的copy时，可以使用以下功能：" << endl;
	cout << "保存当前文件（替换原文件or保存至新文件处）：s"
		 << '\n' << "统计文件行数及字符数：S" << '\n' << "返回：b" << endl;
	cout << "到第一行：1、到最后一行：9" << '\n' << "到指定的某一行：5、";
	cout << "到前一行：p、到下一行：n" << '\n' << "插入一行：i、删除一行：d、替换指定行：R" << endl;
	cout << "替换某个子串：t、查找指定的某个子串：c (只能在指定行中)" << endl;
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
		cout << "请输入指令：";
		cin >> c1;
		while (c1 != 'r'&&c1 != 'h'&&c1 != 'x')
		{
			cout << "请输入正确的指令：";
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
	cout << "进入文件操作模块" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "操作文件的copy时，可以使用以下功能：" << endl;
	cout << "保存当前文件（替换原文件or保存至新文件处）：s"
		 <<'\n'<<"统计文件行数及字符数：S" << '\n' << "返回：b" << endl;
	cout << "到第一行：1、到最后一行：9" << '\n' << "到指定的某一行：5、" ;
	cout << "到前一行：p、到下一行：n"<< '\n' << "插入一行：i、删除一行：d、替换指定行：R" << endl;
	cout << "替换某个子串：t、查找指定的某个子串：c (只能在指定行中)" << endl;
	char c1;
	do {
		cout << '\n' << "请输入指令：";
		cin >> c1;
		while (c1 != 's'&&c1 != 'S'&&c1 != '1'&&c1 != '9'
			&&c1 != 'p'&&c1 != 'n'&&c1 != '5'&&c1 != 'b'
			&&c1 != 'i'&&c1 != 'd'&&c1 != 't'&&c1 != 'c'
			&&c1 != 'R')
		{
			cout << "请输入正确的指令：";
			cin >> c1;
		}

		//switch中要用的局部变量
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
				cout << "该文件为空，没有第一行" << endl;
			}
			else
			{
				cout << newstr->GetLine(1) << endl;
			}
			break;
		case'9':
			if (newstr->GetLine(1) == NULL)
			{
				cout << "该文件为空，没有最后一行" << endl;
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
				cout << "已经是第一行" << endl;
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
				cout << "已经是最后一行" << endl;
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
			cout << "请输入要显示的行数 " ;
			cin >> pos;
			while (newstr->GetLine(pos)==NULL)
			{
				cout<< "请输入正确的行数 ";
				cin >> pos;
			}
			cout << newstr->GetLine(pos) << endl;
			break;
		case'i':
			InsertStr(newstr);
			break;
		case'd':
			cout << "请输入要删除的行数 ";
			cin >> pos;
			while (!newstr->Delete(pos))
			{
				cout << "请输入正确的行数 ";
				cin >> pos;
			}
			cout << "删除成功" << endl;
			break;
		case't':
			replaceSubStr(newstr);
			break;
		case'c':
			searchSubStr(newstr);
			break;
		case'R':
			cout << "请输入要替换的内容（最多为80个字符） ";
			cin >> c;
			cout << "请输入要替换的行数 ";
			cin >> pos;
			while (!newstr->SetLine(pos, c))
			{
				cout << "请输入正确的行数 ";
				cin >> pos;
			}
			cout << "替换成功" << endl;
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
	cout << "请输入文件名" << endl;
	char filename[100] = { 0 };
	cin >> filename;
	fstream f;
	f.open(filename, ios::in);
	while (f.fail())
	{
		cout << "打开文件失败" << endl;
		cout << "请输入正确的已存在的文件名" << endl;
		cin >> filename;
		f.open(filename, ios::in);
	}
	cout << "文件打开成功" << endl;
	StringList* newstr = new StringList();
	int i = 0, j = 1;
	char a[100][81] = { { 0 } };

	//读入文件内容至块链表并关闭文件
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

	//文件操作模块
	char c1;
	do
	{
		cout << '\n' << "请输入指令：";
		cin >> c1;
		while (c1 != 'r'&&c1 != 'h'&&c1 != 'b'&&c1 != 'e')
		{
			cout << "请输入正确的指令：";
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
	cout << "请输入目标文件名，若不存在将自动创建 ";
	cin >> name;
	fstream f;
	f.open(name, ios::out);
	while (f.fail())
	{
		cout << "打开文件失败" << endl;
		cout << "请输入正确的文件名 " ;
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
	cout << "保存成功！" << endl;
}

void statistics(StringList* newstr)
{
	cout << "文件行数（以80个字符为一行，若进行替换、插入操作，改变的那一行即使不满80个字符仍然算作一行）" << endl;
	cout << newstr->Length() << endl;
	int num = 80 * (newstr->Length() - 1),i = 0;
	char* c = newstr->GetPtr(newstr->Length())->data;
	while (c[i]!='\0')
	{
		num++, i++;
	}
	cout << "文件中的字符数为：" << num;
}

void searchSubStr(StringList* newstr)
{
	int pos = 0;
	cout << "请输入要操作的行数 ";
	cin >> pos;
	while (newstr->GetPtr(pos) == NULL)
	{
		cout << "请输入正确的行数 ";
		cin >> pos;
	}
	char sub[80] = { 0 };
	cout << "请输入想要搜索的子串 ";
	cin >> sub;
	string *str = new string(newstr->GetPtr(pos)->data);
	int pos2 = str->find(sub);
	if (pos2 == -1)
	{
		cout << "该行中没有此子串" << endl;
	}
	else
	{
		cout << "此子串在该行中第一次出现的位置为第" << pos2+1 << "个字符处" << endl;
	}
}

void replaceSubStr(StringList* newstr)
{
	int pos = 0;
	cout << "请输入要操作的行数 ";
	cin >> pos;
	while (newstr->GetPtr(pos) == NULL)
	{
		cout << "请输入正确的行数 ";
		cin >> pos;
	}
	string *str = new string(newstr->GetPtr(pos)->data);
	char* c = newstr->GetPtr(pos)->data;
	char sub[80] = { 0 };
	cout << "请输入想要替换的子串 ";
	cin >> sub;
	char trg[80] = { 0 };
	cout << "请输入想要更新的子串 ";
	cin >> trg;
	string s2(sub);
	string s3(trg);
	string::size_type a = s2.size();
	string::size_type b = s3.size();
	int i = 0;
	cout << "想要全部替换输入1，想要替换第一处输入0" << endl;
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
			cout << "替换成功" << endl;
		}
		else
		{
			cout << "该行中没有此子串" << endl;
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
			cout << "替换成功" << endl;
		}
		else
		{
			cout << "该行中没有此子串" << endl;
		}
	}
}

void InsertStr(StringList * newstr)
{
	MyString* m = new MyString();
	int pos = 1;
	char c[81] = { 0 };
	cout << "请输入要插入的内容（最多为80个字符） ";
	cin >> c;
	int i = 0;
	string *s = new string(c);
	m->data = (char*)s->c_str();
	/*while (i < 80)
	{
		m->data[i] = c[i];
		i++;
	}*/
	cout << "请输入要插入的行数 ";
	cin >> pos;
	while (!newstr->Insert(pos, m))
	{
		cout << "请输入正确的行数 ";
		cin >> pos;
	}
	cout << "插入成功" << endl;
}

/*
fstream f;
f.open("test.txt", ios::in);
while (f.fail())
{
cout << "打开文件失败" << endl;
cout << "请输入正确的已存在的文件名" << endl;
//cin >> filename;
//f.open(filename, ios::in);
}
cout << "文件打开成功" << endl;
StringList* newstr = new StringList();
int i = 0, j = 1;
char a[100][81] = { { 0 } };

//读入文件内容至块链表并关闭文件
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