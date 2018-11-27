#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100
struct student
{
	char num[10];
	char name[10];
	int age;
};
typedef struct student STD;
typedef struct
{
	STD *data;
	int listsize;
	int length;
}Sqlist;

int initSqlist(Sqlist *L,int max);
int insertSqlist(Sqlist *L,int i,STD x);
int deleteSqlist(Sqlist *L,STD *x);
void creatSqlist(Sqlist *L,int maxsise);
int xiugaiSqlist(Sqlist *L,int i,STD x);
int locationSqlist(Sqlist L,char *x);
int locationSqlistll(Sqlist L,char *x);
void addSqlist(Sqlist *L);
int xianshiSqlist(Sqlist L);
int menu();

int initSqlist(Sqlist *L,int max)                       //��ʼ��
{
	L->data=(STD*)malloc(10*max*sizeof(STD));
	if(L->data==NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		return 0;
	}
	L->listsize=10*max;
//	L->listsize=MAX;
	L->length=0;
	return 1;
}

int insertSqlist(Sqlist *L,int i,STD x)                 //����
{
	int k;
	if(i<1||i>L->length+1)
	{
		printf("����λ���쳣��\n");
		return 0;
	}
	if(L->length>=L->listsize)
	{
		printf("�����������������һ����Ϣ�޷����棬ֹͣ��ӣ�\n");
		return 0;
	}
	for(k=L->length;k>=i;k--)
		L->data[k]=L->data[k-1];
	L->data[i-1]=x;
	 L->length=L->length+1;
	 return 1;
}

int deleteSqlist(Sqlist *L,int i,STD *x)               //ɾ��
{
	int k;
	if(L->length==0)
	{
		printf("û�����ݣ�����ɾ����\n");
		return 0;
	}
	*x=L->data[i-1];
	if(i<=0||i>L->length)
	{
		printf("λ���쳣��\n");
		return 0;
	}
	for(k=i;k<L->length;k++)
		L->data[k-1]=L->data[k];
	 L->length=L->length-1;
	 return 1;
}



void creatSqlist(Sqlist *L,int maxsize)              //����
{
	int n=0;
	STD x;
	char yn;
	initSqlist(L,maxsize);
	do
	{
		printf("�������%d��ѧ����ѧ�š����������䣬�ÿո������",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertSqlist(L,n+1,x);
		n++;
		printf("�Ƿ�������룿Y/N��");
		yn=getchar();
	}
	while(yn=='Y'||yn=='y');
}


void addSqlist(Sqlist *L)                                 //���
{
	int n;
	STD x;
	char yn;
	n=L->length;
	do
	{
		printf("�������%d��ѧ����ѧ�š����������䣬�ÿո������",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertSqlist(L,n+1,x);
		n++;
		printf("�Ƿ�������룿Y/N��");
		yn=getchar();
	}
	while(yn=='Y'||yn=='y');
}




int xiugaiSqlist(Sqlist L,int i,STD x)                            //�޸�
{
	if(L.length==0)
	{
		printf("û�����ݣ������޸ģ�\n");
		return 0;
	}
	if(i<1||i>L.length)
	{
		printf("λ���쳣��\n");
		return 0;
	}
	L.data[i-1]=x;
	return 1;
}

int locationSqlist(Sqlist L,char *x)                             //��ѧ�Ŷ�λ
{
	int i;
	if(L.length==0)
	{
		printf("û�����ݣ�\n");
		return 0;
	}
	for(i=0;i<L.length;i++)
		if(strcmp(L.data[i].num,x)==0)
			return i+1;
		return 0;
}

int locationSqlistll(Sqlist L,char *x)                           //��������λ
{
	int i;
	if(L.length==0)
	{
		printf("û�����ݣ�\n");
		return 0;
	}
	for(i=0;i<L.length;i++)
		if(strcmp(L.data[i].name,x)==0)
			return i+1;
		return 0;
}



int xianshiSqlist(Sqlist L)                          //����
{
	int i;
	if(L.length==0)
	{
		printf("û�����ݣ�\n");
		return 0;
	}
	for(i=0;i<L.length;i++)
		printf("%-10s%-10s%-4d\n",L.data[i].num,L.data[i].name,L.data[i].age);
	return 1;

}

int menu()
{
	int n;
	while(1)
	{
		system("cls");
		printf("****��ӭʹ��ѧ����Ϣ����ϵͳ****\n");
		printf("1 ����ѧ�����ݱ�  2 ����ѧ������\n");
		printf("3 ɾ��ѧ������    4 �޸�ѧ������\n");
		printf("5 ����ѧ�Ų�ѯ    6 ����������ѯ\n");
		printf("7 ���ѧ������    8 ��ʾѧ������\n");
		printf("0 �˳���Ϣϵͳ \n");
		printf("********************************\n");
		printf("��ѡ���ܱ��0-7  ");
			scanf("%d",&n);
		getchar();
		if(n<0||n>10)
		{	printf("��������������ѡ�񣡰����������\n");
		getch();}
		else
			return n;
	}
}


void main()
{
	Sqlist L;
	STD s;
	int n,maxsize;
	while(1)
	{
		n=menu();
		switch(n)
		{
		case 1:
			printf("��������Ҫ������ѧ��������");
			scanf("%d",&maxsize);
			creatSqlist(&L,maxsize);
			printf("�������������\n");
			getch();
			break;
		case 2:
			printf("��������Ҫ�����ѧ����ѧ�����������䣬�ÿո������\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			int t;
			printf("����������λ�ã��������ֱ�ʾ����");
	        scanf("%d",&t);
			insertSqlist(&L,t,s);
			printf("�������������\n");
			getch();
			break;
		case 3:
			printf("��������Ҫɾ����ѧ����ѧ��\n");
			scanf("%s",s.num);
			n=locationSqlist(L,s.num);
			deleteSqlist(&L,n,&s);
			printf("ɾ����ѧ������Ϊ��%-10s%-10s%-4d\n",s.num,s.name,s.age);
			printf("�������������\n");
			getch();
			break;
		case 4:
			printf("�������޸ĺ��ѧ����ѧ�����������䣬�ÿո������\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			n=locationSqlist(L,s.num);
			xiugaiSqlist(L,n,s);
			printf("�������������\n");
			getch();
			break;
		case 5:
			printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
			scanf("%s",s.num);
			n=locationSqlist(L,s.num);
			if(n)
				printf("%-10s%-10s%-4d",L.data[n-1].num,L.data[n-1].name,L.data[n-1].age);
			else 
				printf("���ݲ����ڣ�");
			printf("�������������\n");
			getch();
			break;
		case 6:
			printf("������Ҫ��ѯ��ѧ����������");
			scanf("%s",s.name);
			n=locationSqlistll(L,s.name);
			if(n)
				printf("%-10s%-10s%-4d",L.data[n-1].num,L.data[n-1].name,L.data[n-1].age);
			else 
				printf("���ݲ����ڣ�");
			printf("�������������\n");
			getch();
			break;
		case 7:
			addSqlist(&L);
			printf("�������������\n");
			getch();
			break;
		case 8:
			printf("ѧ����Ϣ���£�\n");
			xianshiSqlist(L);
			printf("�������������\n");
			getch();
			break;
	
		case 0:
			exit(0);

		}
	}

}
