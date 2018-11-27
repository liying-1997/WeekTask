#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
typedef struct
{
	char num[10];
	char name[10];
	int age;
}STD;
typedef struct Lnode
{
	STD data;
	struct Lnode *next;
}LNode,*Linklist;


int initLinklist(Linklist *L);
int insertLinklist(Linklist L,int i,STD x);
int deleteLinklist(Linklist L,int i,STD *x);
int updateLinklist(Linklist L,int i,STD x);
int locationnumLinklist(Linklist L,char *x);
void findnumLinklist(Linklist L,char x);
void findnameLinklist(Linklist L,char x);
int dispLinklist(Linklist L);
void rearcreatLinklist(Linklist *L);
void frontcreatLinklist(Linklist *L);
int Linklistlength(Linklist L);
void addLinklist(Linklist L);
int menu();



int initLinklist(Linklist *L)                               //��ʼ��
{
	*L=(Linklist)malloc(sizeof(LNode));
	if(*L==NULL)
		return 0;
	(*L)->next=NULL;
	return 1;
}
int insertLinklist(Linklist L,int i,STD x)                   //����
{
	Linklist p=L,s;
	int pos=0;
	while(p!=NULL && pos<i-1)
	{
		p=p->next;
		pos++;
	}
	if(p==NULL||pos>i-1)
	{
		printf("����λ�ò�����\n");
		return 0;
	}
	s=(Linklist)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
int deleteLinklist(Linklist L,int i,STD *x)                    //ɾ��
{
	Linklist q,p=L;
	int pos=0;
	while(p->next!=NULL && pos<i-1)
	{
		p=p->next;
		pos++;
	}
	if(p->next==NULL || pos>i-1)
	{
		printf("����Ϊ�ջ�ɾ��λ�ò�����\n");
		return 0;
	}
	q=p->next;
	p->next=q->next;
	*x=q->data;
	free(q);
	return 1;
}
int updateLinklist(Linklist L,int i,STD x)                       //����
{
	Linklist p=L->next;
	int n=1;
	while(p && n<i)
	{
		p=p->next;
		n++;
	}
	if(p==NULL||n>i)
	{
		printf("λ�ò��������ܸ��£�\n");
		return 0;
	}
	p->data=x;
	return 1;
	
}

int locationnumLinklist(Linklist L,char *x)           //����ѧ�Ŷ�λ
{
	Linklist p=L->next;
	int j=1;
	while(p)
		if(strcmp(p->data.num,x))
		{
			p=p->next;
			j++;
		}
		else return j;
	if(p==NULL)
		return 0;


}

void findnumLinklist(Linklist L,char * x)                    //����ѧ�Ų���
{
	Linklist p=L->next;
	int flag=0;
	while(p)
	{
		if(strcmp(p->data.num,x)==0)
		{	
			printf("%-10s%-10s%-4d\n",p->data.num,p->data.name,p->data.age);
			flag=1;}
		p=p->next;
	}
	if(flag==0)
		printf("û�в鵽��ѧ��ѧ������Ϣ��\n");
}
 
void findnameLinklist(Linklist L,char * x)                               //������������
{
	Linklist p=L->next;
	int flag=0;
	while(p)
	{
		if(strcmp(p->data.name,x)==0)
		{
			printf("%-10s%-10s%-4d\n",p->data.num,p->data.name,p->data.age);
			flag=1;
		}

		p=p->next;
	}
	if(flag==0)
		printf("û�в鵽��������ѧ������Ϣ��\n");
}


int dispLinklist(Linklist L)                                    //����
{
	Linklist p=L->next;
	if(p==NULL)
	{
		printf("û�����ݣ�\n");
		return 0;
	}
	while (p)
	{
		printf("%-10s%-10s%-4d\n",p->data.num,p->data.name,p->data.age);
		p=p->next;
	}
	return 1;
}

void rearcreatLinklist(Linklist *L)                            //β�巨��������
{
	int n=0;
	STD x;
	Linklist p,R;
	char yn;
	initLinklist(L);
	R=*L;
	do
	{
		printf("�������%d��ѧ����ѧ�� ���� ���䣬�ÿո������",++n);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		p=(Linklist)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		R->next=p;
		R=p;
		printf("����������Y/N:");
		yn=getchar();

	}while(yn=='Y'||yn=='y');
}

void frontcreatLinklist(Linklist *L)                            //ͷ�巨��������
{
	int n=0;
	STD x;
	Linklist p;
	char yn;
	initLinklist(L);
	do
	{
		printf("�������%d��ѧ����ѧ�� ���� ���䣬�ÿո������",++n);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		p=(Linklist)malloc(sizeof(LNode));
		p->data=x;
		p->next=(*L)->next;
		(*L)->next=p;
		printf("����������Y/N:");
		yn=getchar();

	}while(yn=='Y'||yn=='y');
}

int Linklistlength(Linklist L)                 //��������ĳ���
{
	Linklist p=L->next;
	int n=0;
	while(p)
	{
		n++;
		p=p->next;
	}
	return n;
}

void addLinklist(Linklist L)                       //�����Ϣ                    
{
	int n;
	STD x;
	char yn;
	n=Linklistlength(L);
	do
	{
		printf("�������%d��ѧ����ѧ�� ���� ���䣬�ÿո������",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertLinklist(L,n+1,x);
		n++;
		printf("�Ƿ�������룿Y/N��");
		yn=getchar();
	}
	while(yn=='Y'||yn=='y');
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
		if(n<0||n>8)
		{	printf("��������������ѡ�񣡰����������\n");
		getch();}
		else
			return n;
	}
}


void main()
{
	Linklist L;
	STD s;
	int n;
	while(1)
	{
		n=menu();
		switch(n)
		{
		case 1:
			rearcreatLinklist(&L);    //�˴�Ҳ�ɵ���frontcreatLinklist������β�巨��������
			printf("�������������\n");
			getch();
			break;                                
		case 2:
			printf("��������Ҫ�����ѧ����ѧ�����������䣬�ÿո������\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			int t;
			printf("����������λ�ã��������ֱ�ʾ����");
	        scanf("%d",&t);
			insertLinklist(L,t,s);
			printf("�������������\n");
			getch();
			break;
		case 3:
			printf("��������Ҫɾ����ѧ����ѧ��\n");
			scanf("%s",s.num);
			n=locationnumLinklist(L,s.num);
			deleteLinklist(L,n,&s);
			printf("ɾ����ѧ������Ϊ��%-10s%-10s%-4d\n",s.num,s.name,s.age);
			printf("�������������\n");
			getch();
			break;
		case 4:
			printf("��������Ҫ�޸ĵ�ѧ����ѧ�����������䣬�ÿո������\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			n=locationnumLinklist(L,s.num);
			updateLinklist(L,n,s);
			printf("�������������\n");
			getch();
			break;
		case 5:
			printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
			scanf("%s",s.num);
			findnumLinklist(L,s.num);
			printf("�������������\n");
			getch();
			break;
		case 6:
			printf("������Ҫ��ѯ��ѧ����������");
			scanf("%s",s.name);
			findnameLinklist(L,s.name);
			printf("�������������\n");
			getch();
			break;
		case 7:
			addLinklist(L);
			printf("�������������\n");
			getch();
			break;
		case 8:
			printf("ѧ����Ϣ���£�\n");
			dispLinklist(L);
			printf("�������������\n");
			getch();
			break;
		case 0:
			exit(0);

		}
	}

}
