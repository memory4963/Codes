#include<iostream>
#include<Cstring>
#include<conio.h>
#include<fstream>
using namespace std;
class Book {
private:
	char bookname[21];
	char writer[21];
	long ID;
	long publicationdate;
public:
	void SetInfo()
	{
		cin >> bookname >> writer >> ID >> publicationdate;
	}
	char *getName()
	{
		return bookname;
	}
	void PutInfo()
	{
		cout << "������" << bookname;
		cout << "\n" << "���ߣ�" << writer << endl;
		cout << "ID��" << ID << endl;
		cout << "�������ڣ�" << publicationdate << endl;
	}
	void outputToFile() {
		fstream myfile;
		myfile.open("D:/book.txt", ios::app | ios::out);
		if (!myfile) {
			cerr << "�ļ�û�б��򿪻���û�б�����!" << endl;
			exit(1);
		}
		myfile << bookname << " " << writer << " " << ID << " " << publicationdate;
		myfile.close();
	}
	void inputFromFile(fstream &myfile)
	{
		myfile << bookname << writer << ID << publicationdate;

	}
};
class Library {
private:
	Book bk[100];
	char d;
	int i = 0;
public:
	void AddBook();
	void QueryByName(char *namebook1, int n);
	void ListBook();
};
void Library::AddBook()
{
	fstream myfile;
	myfile.open("D:/book.txt", ios::app);
	if (!myfile) {
		cerr << "�ļ�û�б��򿪻���û�б�����!" << endl;
		exit(1);
	}
	do {
		bk[i].SetInfo();
		bk[i].outputToFile();
		while (1)
		{
			cout << "�Ƿ�������ͼ�飿" << endl;
			cout << "1.�������" << "\n" << "2.�������" << endl;
			cin >> d;
			if (d == '1' || d == '2')  break;
			else   cout << "�����������������!" << endl;
		}
		if (d == '2')  break;
		i++;
	} while (i < 100);
	myfile.close();
}
void Library::QueryByName(char *namebook1, int n)
{
	int found = 0;
	fstream myfile;
	myfile.open("D:/book.txt");
	if (!myfile) {
		cerr << "�ļ�û�б���!" << endl;
		exit(1);
	}
	for (i = 0; bk[i].getName() != 0; i++)
	{
		if (strcmp(bk[i].getName(), namebook1) == 0)
		{
			cout << "�Ѳ�ѯ����Ҫ���ҵ�ͼ�飬��Ϣ���£�" << endl;
			bk[i].inputFromFile(myfile);
			bk[i].PutInfo();
			cout << "�밴���������!" << endl;
			_getch();
			found = 1;
		}
	}
	if (found == 0) {
		cout << "�����û����Ҫ���ҵ���!" << endl;
		cout << "�밴���������!" << endl;
		_getch();
	}
}
void Library::ListBook()
{
	fstream myfile;
	myfile.open("D:/book.txt");
	if (!myfile) {
		cerr << "�ļ����ܱ���!" << endl;
		exit(1);
	}
	int k = 0;
	for (i = 0; !myfile.eof(); i++)
	{
		bk[i].inputFromFile(myfile);
		bk[i].PutInfo();
		k = 1;
	}
	if (k == 0) {
		cout << "��ǰ���û��ͼ��!" << endl;
		cout << "�밴���������!" << endl;
		_getch();
	}
	myfile.close();
}
int main()
{
	Library Li;//����һ�����󣡣��� 
	char d;
	char bookname[21];
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "��ӭ����ͼ��ݹ���ϵͳ";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while (1)
	{
		cout << "����ѡ�����������!" << endl;
		cout << "1.���ͼ��" << endl;
		cout << "2.��ѯͼ��" << endl;
		cout << "3.ͼ���б���" << endl;
		cout << "4.�˳�ϵͳ" << endl;
		d = _getch();
		if (d == '1') {
			Li.AddBook();
		}
		else if (d == '2') {
			cin >> bookname;
			Li.QueryByName(bookname, strlen(bookname));
		}
		else if (d == '3') {
			Li.ListBook();
		}
		else if (d == '4') {
			cout << "��ӭʹ��ͼ��ݹ���ϵͳ���ټ�!" << endl;
			break;
		}
		else  cout << "�����������������!" << endl;
	}
	return 0;

}