#include<stdio.h>
#include <stdlib.h>
int main()
{
	float b, c, sum, aver;
	int i;
	sum = 0;
	for (i = 2000;i <= 2015;i++)
	{
		printf("������%d����ߵĳ�����ݣ�", i);
		scanf_s("%f", &b);
		c = i - b;
		while (c <= 0)
		{
			printf("������Ч�������䣺");
			printf("������%d����ߵĳ�����ݣ�", i);
			scanf_s("%f", &b);
			c = i - b;
		}
		sum = sum + c;
	}
	aver = sum / 16;
	printf("16λŵ������ѧ������߻�ʱ��ƽ��������%6.1f\n", aver);
	system("pause");
	return 0;
}
