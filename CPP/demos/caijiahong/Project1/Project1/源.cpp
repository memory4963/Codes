#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
void print_menu();
void	  input();
void 	   show();
void     search();
void    delete1();
void     insert();
struct student
{
	char identity[30];
	char name[15];
	char date_of_birth[8];
	char sex[10];
	char grade_point[2];
};
struct staff
{
	char identity[30];
	char name[15];
	char date_of_birth[8];
	char sex[10];
	char dept[15];
};
struct teacher
{
	char identity[30];
	char name[15];
	char date_of_birth[8];
	char sex[10];
	int  fund;
};
union character
{
	struct student stu;
	struct staff sta;
	struct teacher tea;
};
typedef struct Node
{
	int i;
	union character cha;
	struct Node *next;
}node;
node *head = NULL, *last = NULL, *curreut = NULL, *curreut_last = NULL;

void print_menu()
{
	char a[1];
	int k = 0;
	while (1)
	{
		system("cls");
		if (curreut != NULL)
		{
			if (curreut->i == 1)
			{
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ѧ��    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    ѧ��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", curreut->cha.stu.name, curreut->cha.stu.sex, curreut->cha.stu.identity, curreut->cha.stu.date_of_birth, curreut->cha.stu.grade_point);
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n");
			}
			else if (curreut->i == 2)
			{
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ����    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    Ա��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", curreut->cha.sta.name, curreut->cha.sta.sex, curreut->cha.sta.identity, curreut->cha.sta.date_of_birth, curreut->cha.sta.dept);
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n");
			}
			else if (curreut->i == 3)
			{
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |  ���о���  |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    ��ʦ    |%-12s|%-12s|%-20s|%-14s|%-12d|\n", curreut->cha.tea.name, curreut->cha.tea.sex, curreut->cha.tea.identity, curreut->cha.tea.date_of_birth, curreut->cha.tea.fund);
				printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n");
			}
		}
		if (k == 1)
			printf_s("1   ��Ϣ¼�룻\n2   ��ʾ������Ϣ��\n3   ֤���Ų�ѯ��\n4   ��յ�ǰ�ڵ���Ϣ��\n5   ��ǰ�ڵ�����һ����Ϣ��\n\n���������������ѡ��");
		else
			printf_s("1   ��Ϣ¼�룻\n2   ��ʾ������Ϣ��\n3   ֤���Ų�ѯ��\n4   ��յ�ǰ�ڵ���Ϣ��\n5   ��ǰ�ڵ�����һ����Ϣ��\n\n����ѡ��");
		scanf_s("%s", a);
		if (strcmp(a, "1") == 0)
		{
			k = 0; input();
		}
		else if (strcmp(a, "2") == 0)
		{
			k = 0; show();
		}
		else if (strcmp(a, "3") == 0)
		{
			k = 0; search();
		}
		else if (strcmp(a, "4") == 0)
		{
			k = 0; delete1();
		}
		else if (strcmp(a, "5") == 0)
		{
			k = 0; insert();
		}
		else
			k = 1;
	}
}

void 	   show()
{
	node *p;
	int t = 0;
	system("cls");
	p = head;
	while (p != NULL)
	{
		while (p != NULL)
		{
			if (p->i == 1)
			{
				t++;
				if (t == 1)
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ѧ��    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    ѧ��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", p->cha.stu.name, p->cha.stu.sex, p->cha.stu.identity, p->cha.stu.date_of_birth, p->cha.stu.grade_point);
			}
			p = p->next;
		}
		if (t != 0)
			printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n");

		p = head; t = 0;
		while (p != NULL)
		{
			if (p->i == 2)
			{
				t++;
				if (t == 1)
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ����    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    Ա��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", p->cha.sta.name, p->cha.sta.sex, p->cha.sta.identity, p->cha.sta.date_of_birth, p->cha.sta.dept);
			}
			p = p->next;
		}
		if (t != 0)
			printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n");

		p = head; t = 0;
		while (p != NULL)
		{
			if (p->i == 3)
			{
				t++;
				if (t == 1)
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |  ���о���  |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
				printf_s("\t      |    ��ʦ    |%-12s|%-12s|%-20s|%-14s|%-12d|\n", p->cha.tea.name, p->cha.tea.sex, p->cha.tea.identity, p->cha.tea.date_of_birth, p->cha.tea.fund);
			}
			p = p->next;
		}
		if (t != 0)
			printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n�밴�����������������������");
		_getch();
		print_menu();
	}
	printf_s("\n���κ���Ϣ����������˳���������������");
	_getch();
	print_menu();
}

void     search()
{
	char identity_date[30];
	node *p;
	int t = 0;
	system("cls");
	while (1)
	{
		p = head;
		if (p != NULL)
		{
			printf_s("\n��������Ҫ��ѯ��֤���ţ�");
			scanf_s("%s", identity_date);
		}
		while (p != NULL)
		{
			if (p->i == 1)
			{
				if (strcmp(p->cha.stu.identity, identity_date) == 0)
				{
					curreut = p; t++;
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ѧ��    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
					printf_s("\t      |    ѧ��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", curreut->cha.stu.name, curreut->cha.stu.sex, curreut->cha.stu.identity, curreut->cha.stu.date_of_birth, curreut->cha.stu.grade_point);
				}
			}
			else if (p->i == 2)
			{
				if (strcmp(p->cha.sta.identity, identity_date) == 0)
				{
					curreut = p; t++;
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |    ����    |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
					printf_s("\t      |    Ա��    |%-12s|%-12s|%-20s|%-14s|%-12s|\n", curreut->cha.sta.name, curreut->cha.sta.sex, curreut->cha.sta.identity, curreut->cha.sta.date_of_birth, curreut->cha.sta.dept);
				}
			}
			else if (p->i == 3)
			{
				if (strcmp(p->cha.tea.identity, identity_date) == 0)
				{
					curreut = p; t++;
					printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\t      |    ְҵ\t   |    ����\t|    �Ա�    |       ֤����       |   ��������   |  ���о���  |\n\t      +------------+------------+------------+--------------------+--------------+------------+\n");
					printf_s("\t      |    ��ʦ    |%-12s|%-12s|%-20s|%-14s|%-12d|\n", curreut->cha.tea.name, curreut->cha.tea.sex, curreut->cha.tea.identity, curreut->cha.tea.date_of_birth, curreut->cha.tea.fund);
				}
			}
			p = p->next;
		}
		if (t != 0)
		{
			t = 0;
			printf_s("\t      +------------+------------+------------+--------------------+--------------+------------+\n\n\n�밴�����������������������");
			_getch();
			print_menu();
		}
		else
		{
			printf_s("\n\n\n���κ���Ϣ����������˳���������������");
			_getch();
			print_menu();
		}
	}
}

void    delete1()
{
	system("cls");
	if (curreut != NULL)
	{
		if (curreut == head)
			head = head->next;
		else
		{
			curreut_last = head;
			while (curreut_last->next != curreut)
			{
				curreut_last = curreut_last->next;
			}
			curreut_last->next = curreut->next;
		}
		free(curreut);
		curreut = NULL;
		printf_s("\n\n\n��ǰ�ڵ���Ϣɾ���ɹ�����������˳���������������");
	}
	else
	{
		printf_s("\n\n\n��ǰ�ڵ㲻���ڣ���������˳���������������");
	}
	_getch();
	print_menu();
}
void     insert()
{
	int k = 0;
	char key_b_in[1], a[1];
	while (1)
	{
		system("cls");
		if (curreut == NULL)
		{
			printf_s("\n\n\n��ǰ�ڵ㲻���ڣ�����������ء�������������");
			_getch();
			print_menu();
		}
		else
			if (k == 1)
				printf_s("1 ����ѧ����Ϣ\n2 ����Ա����Ϣ\n3 ������ʦ��Ϣ\n\n����������������ѡ��");
			else
				printf_s("1 ����ѧ����Ϣ\n2 ����Ա����Ϣ\n3 ������ʦ��Ϣ\n\n����ѡ��");
		scanf_s("%s", a);
		if (strcmp(a, "1") == 0)
		{
			system("cls");
			printf_s("\n����������ѧ����Ϣ��\n\n");
			node   *pnew = (node*)malloc(sizeof(node));
			pnew->next = curreut->next;
			curreut->next = pnew;
			pnew->i = 1;
			printf_s("֤���ţ�");
			scanf_s("%s", pnew->cha.stu.identity);
			printf_s("������");
			scanf_s("%s", pnew->cha.stu.name);
			printf_s("�������£�");
			scanf_s("%s", pnew->cha.stu.date_of_birth);
			printf_s("�Ա�");
			scanf_s("%s", pnew->cha.stu.sex);
			printf_s("ѧ�֣�");
			scanf_s("%s", pnew->cha.stu.grade_point);
			printf_s("\n\nѧ��%s��Ϣ����ɹ�����������˳���������������", pnew->cha.stu.name);
			_getch();
			print_menu();
		}
		else if (strcmp(a, "2") == 0)
		{
			system("cls");
			printf_s("\n��¼������Ա����Ϣ��\n\n");
			node   *pnew = (node*)malloc(sizeof(node));
			pnew->next = curreut->next;
			curreut->next = pnew;
			pnew->i = 2;
			printf_s("֤���ţ�");
			scanf_s("%s", pnew->cha.sta.identity);
			printf_s("������");
			scanf_s("%s", pnew->cha.sta.name);
			printf_s("�������£�");
			scanf_s("%s", pnew->cha.sta.date_of_birth);
			printf_s("�Ա�");
			scanf_s("%s", pnew->cha.sta.sex);
			printf_s("���ţ�");
			scanf_s("%s", pnew->cha.sta.dept);
			printf_s("\n\nԱ��%s��Ϣ����ɹ�����������˳���������������", last->cha.sta.name);
			_getch();
			print_menu();
		}
		else if (strcmp(a, "3") == 0)
		{
			system("cls");
			printf_s("\n��¼��������ʦ��Ϣ��\n\n");
			node   *pnew = (node*)malloc(sizeof(node));
			pnew->next = curreut->next;
			curreut->next = pnew;
			pnew->i = 3;
			printf_s("֤���ţ�");
			scanf_s("%s", pnew->cha.tea.identity);
			printf_s("������");
			scanf_s("%s", pnew->cha.tea.name);
			printf_s("�������£�");
			scanf_s("%s", pnew->cha.tea.date_of_birth);
			printf_s("�Ա�");
			scanf_s("%s", pnew->cha.tea.sex);
			printf_s("���о��ѣ�");
			scanf_s("%d", &pnew->cha.tea.fund);
			printf_s("\n\n��ʦ%s��Ϣ����ɹ�����������˳���������������", pnew->cha.tea.name);
			_getch();
			print_menu();
		}
		else k = 1;
	}
}
void input()
{
	int k = 0;
	char key_b_in[1], a[1];
	while (1)
	{
		system("cls");
		if (k == 1)
			printf_s("1 ѧ����Ϣ¼��\n2 Ա����Ϣ¼��\n3 ��ʦ��Ϣ¼��\n\n����������������ѡ��");
		else
			printf_s("1 ѧ����Ϣ¼��\n2 Ա����Ϣ¼��\n3 ��ʦ��Ϣ¼��\n\n����ѡ��");
		scanf_s("%s", a);
		if (strcmp(a, "1") == 0)
		{
			while (1)
			{
				system("cls");
				printf_s("\n����������ѧ����Ϣ��\n\n");
				node   *pnew = (node*)malloc(sizeof(node));
				if (head == NULL)
					head = pnew;
				else
					last->next = pnew;
				last = pnew;
				last->next = NULL;
				last->i = 1;
				printf_s("֤���ţ�");
				scanf_s("%s", last->cha.stu.identity);
				printf_s("������");
				scanf_s("%s", last->cha.stu.name);
				printf_s("�������£�");
				scanf_s("%s", last->cha.stu.date_of_birth);
				printf_s("�Ա�");
				scanf_s("%s", last->cha.stu.sex);
				printf_s("ѧ�֣�");
				scanf_s("%s", last->cha.stu.grade_point);
				printf_s("\n\nѧ��%s��Ϣ¼��ɹ����Ƿ����¼��ѧ����Ϣ����Y ����,N �������˵���\n����ѡ��:", last->cha.stu.name);
				scanf_s("%s", key_b_in);
				while ((strcmp(key_b_in, "Y") != 0) && (strcmp(key_b_in, "y") != 0))
				{

					if ((strcmp(key_b_in, "N") == 0) || (strcmp(key_b_in, "n") == 0))
						print_menu();
					else
					{
						system("cls");
						printf_s("\n�Ƿ����¼��ѧ����Ϣ����Y ����,N �������˵���\n\n\n������������������룺");
						scanf_s("%s", key_b_in);
					}
				}
			}
		}
		else if (strcmp(a, "2") == 0)
		{
			while (1)
			{
				system("cls");
				printf_s("\n��¼������Ա����Ϣ��\n\n");
				node   *pnew = (node*)malloc(sizeof(node));
				if (head == NULL)
					head = pnew;
				else
					last->next = pnew;
				last = pnew;
				last->next = NULL;
				last->i = 2;
				printf_s("֤���ţ�");
				scanf_s("%s", last->cha.sta.identity);
				printf_s("������");
				scanf_s("%s", last->cha.sta.name);
				printf_s("�������£�");
				scanf_s("%s", last->cha.sta.date_of_birth);
				printf_s("�Ա�");
				scanf_s("%s", last->cha.sta.sex);
				printf_s("���ţ�");
				scanf_s("%s", last->cha.sta.dept);
				printf_s("\n\nԱ��%s��Ϣ¼��ɹ����Ƿ����¼��Ա����Ϣ����Y ����,N �������˵���\n����ѡ��:", last->cha.sta.name);
				scanf_s("%s", key_b_in);
				while ((strcmp(key_b_in, "Y") != 0) && (strcmp(key_b_in, "y") != 0))
				{

					if ((strcmp(key_b_in, "N") == 0) || (strcmp(key_b_in, "n") == 0))
						print_menu();
					else
					{
						system("cls");
						printf_s("\n�Ƿ����¼��Ա����Ϣ����Y ����,N �������˵���\n\n\n������������������룺");
						scanf_s("%s", key_b_in);
					}
				}
			}
		}
		else if (strcmp(a, "3") == 0)
		{
			while (1)
			{
				system("cls");
				printf_s("\n��¼��������ʦ��Ϣ��\n\n");
				node   *pnew = (node*)malloc(sizeof(node));
				if (head == NULL)
					head = pnew;
				else
					last->next = pnew;
				last = pnew;
				last->next = NULL;
				last->i = 3;
				printf_s("֤���ţ�");
				scanf_s("%s", last->cha.tea.identity);
				printf_s("������");
				scanf_s("%s", last->cha.tea.name);
				printf_s("�������£�");
				scanf_s("%s", last->cha.tea.date_of_birth);
				printf_s("�Ա�");
				scanf_s("%s", last->cha.tea.sex);
				printf_s("���о��ѣ�");
				scanf_s("%d", &last->cha.tea.fund);
				printf_s("\n\n��ʦ%s��Ϣ¼��ɹ����Ƿ����¼����ʦ��Ϣ����Y ����,N �������˵���\n����ѡ��:", last->cha.tea.name);
				scanf_s("%s", key_b_in);
				while ((strcmp(key_b_in, "Y") != 0) && (strcmp(key_b_in, "y") != 0))
				{

					if ((strcmp(key_b_in, "N") == 0) || (strcmp(key_b_in, "n") == 0))
						print_menu();
					else
					{
						system("cls");
						printf_s("\n�Ƿ����¼����ʦ��Ϣ����Y ����,N �������˵���\n\n\n������������������룺");
						scanf_s("%s", key_b_in);
					}
				}
			}
		}
		else k = 1;
	}
}

void main()
{
	print_menu();

}

