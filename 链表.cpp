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



int initLinklist(Linklist *L)                               //初始化
{
	*L=(Linklist)malloc(sizeof(LNode));
	if(*L==NULL)
		return 0;
	(*L)->next=NULL;
	return 1;
}
int insertLinklist(Linklist L,int i,STD x)                   //插入
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
		printf("插入位置不合理！\n");
		return 0;
	}
	s=(Linklist)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
int deleteLinklist(Linklist L,int i,STD *x)                    //删除
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
		printf("链表为空或删除位置不合理！\n");
		return 0;
	}
	q=p->next;
	p->next=q->next;
	*x=q->data;
	free(q);
	return 1;
}
int updateLinklist(Linklist L,int i,STD x)                       //更新
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
		printf("位置不合理，不能更新！\n");
		return 0;
	}
	p->data=x;
	return 1;
	
}

int locationnumLinklist(Linklist L,char *x)           //根据学号定位
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

void findnumLinklist(Linklist L,char * x)                    //根据学号查找
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
		printf("没有查到该学号学生的信息！\n");
}
 
void findnameLinklist(Linklist L,char * x)                               //根据姓名查找
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
		printf("没有查到该姓名的学生的信息！\n");
}


int dispLinklist(Linklist L)                                    //遍历
{
	Linklist p=L->next;
	if(p==NULL)
	{
		printf("没有数据！\n");
		return 0;
	}
	while (p)
	{
		printf("%-10s%-10s%-4d\n",p->data.num,p->data.name,p->data.age);
		p=p->next;
	}
	return 1;
}

void rearcreatLinklist(Linklist *L)                            //尾插法创建链表
{
	int n=0;
	STD x;
	Linklist p,R;
	char yn;
	initLinklist(L);
	R=*L;
	do
	{
		printf("请输入第%d个学生的学号 姓名 年龄，用空格隔开：",++n);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		p=(Linklist)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		R->next=p;
		R=p;
		printf("继续输入吗？Y/N:");
		yn=getchar();

	}while(yn=='Y'||yn=='y');
}

void frontcreatLinklist(Linklist *L)                            //头插法创建链表
{
	int n=0;
	STD x;
	Linklist p;
	char yn;
	initLinklist(L);
	do
	{
		printf("请输入第%d个学生的学号 姓名 年龄，用空格隔开：",++n);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		p=(Linklist)malloc(sizeof(LNode));
		p->data=x;
		p->next=(*L)->next;
		(*L)->next=p;
		printf("继续输入吗？Y/N:");
		yn=getchar();

	}while(yn=='Y'||yn=='y');
}

int Linklistlength(Linklist L)                 //计算链表的长度
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

void addLinklist(Linklist L)                       //添加信息                    
{
	int n;
	STD x;
	char yn;
	n=Linklistlength(L);
	do
	{
		printf("请输入第%d个学生的学号 姓名 年龄，用空格隔开：",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertLinklist(L,n+1,x);
		n++;
		printf("是否继续输入？Y/N：");
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
		printf("****欢迎使用学生信息管理系统****\n");
		printf("1 创建学生数据表  2 插入学生数据\n");
		printf("3 删除学生数据    4 修改学生数据\n");
		printf("5 根据学号查询    6 根据姓名查询\n");
		printf("7 添加学生数据    8 显示学生数据\n");
		printf("0 退出信息系统 \n");
		printf("********************************\n");
		printf("请选择功能编号0-7  ");
			scanf("%d",&n);
		getchar();
		if(n<0||n>8)
		{	printf("输入有误，请重新选择！按任意键继续\n");
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
			rearcreatLinklist(&L);    //此处也可调用frontcreatLinklist函数用尾插法创建链表
			printf("按任意键继续！\n");
			getch();
			break;                                
		case 2:
			printf("请输入需要插入的学生的学号姓名和年龄，用空格隔开：\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			int t;
			printf("请输入插入的位置（整形数字表示）：");
	        scanf("%d",&t);
			insertLinklist(L,t,s);
			printf("按任意键继续！\n");
			getch();
			break;
		case 3:
			printf("请输入需要删除的学生的学号\n");
			scanf("%s",s.num);
			n=locationnumLinklist(L,s.num);
			deleteLinklist(L,n,&s);
			printf("删除的学生数据为：%-10s%-10s%-4d\n",s.num,s.name,s.age);
			printf("按任意键继续！\n");
			getch();
			break;
		case 4:
			printf("请输入需要修改的学生的学号姓名和年龄，用空格隔开：\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			n=locationnumLinklist(L,s.num);
			updateLinklist(L,n,s);
			printf("按任意键继续！\n");
			getch();
			break;
		case 5:
			printf("请输入要查询的学生的学号：");
			scanf("%s",s.num);
			findnumLinklist(L,s.num);
			printf("按任意键继续！\n");
			getch();
			break;
		case 6:
			printf("请输入要查询的学生的姓名：");
			scanf("%s",s.name);
			findnameLinklist(L,s.name);
			printf("按任意键继续！\n");
			getch();
			break;
		case 7:
			addLinklist(L);
			printf("按任意键继续！\n");
			getch();
			break;
		case 8:
			printf("学生信息如下：\n");
			dispLinklist(L);
			printf("按任意键继续！\n");
			getch();
			break;
		case 0:
			exit(0);

		}
	}

}
