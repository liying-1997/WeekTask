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

int initSqlist(Sqlist *L,int max)                       //初始化
{
	L->data=(STD*)malloc(10*max*sizeof(STD));
	if(L->data==NULL)
	{
		printf("申请空间失败！\n");
		return 0;
	}
	L->listsize=10*max;
//	L->listsize=MAX;
	L->length=0;
	return 1;
}

int insertSqlist(Sqlist *L,int i,STD x)                 //插入
{
	int k;
	if(i<1||i>L->length+1)
	{
		printf("插入位置异常！\n");
		return 0;
	}
	if(L->length>=L->listsize)
	{
		printf("容量不够！输入的上一条信息无法保存，停止添加！\n");
		return 0;
	}
	for(k=L->length;k>=i;k--)
		L->data[k]=L->data[k-1];
	L->data[i-1]=x;
	 L->length=L->length+1;
	 return 1;
}

int deleteSqlist(Sqlist *L,int i,STD *x)               //删除
{
	int k;
	if(L->length==0)
	{
		printf("没有数据，不能删除！\n");
		return 0;
	}
	*x=L->data[i-1];
	if(i<=0||i>L->length)
	{
		printf("位置异常！\n");
		return 0;
	}
	for(k=i;k<L->length;k++)
		L->data[k-1]=L->data[k];
	 L->length=L->length-1;
	 return 1;
}



void creatSqlist(Sqlist *L,int maxsize)              //创建
{
	int n=0;
	STD x;
	char yn;
	initSqlist(L,maxsize);
	do
	{
		printf("请输入第%d个学生的学号、姓名和年龄，用空格隔开：",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertSqlist(L,n+1,x);
		n++;
		printf("是否继续输入？Y/N：");
		yn=getchar();
	}
	while(yn=='Y'||yn=='y');
}


void addSqlist(Sqlist *L)                                 //添加
{
	int n;
	STD x;
	char yn;
	n=L->length;
	do
	{
		printf("请输入第%d个学生的学号、姓名和年龄，用空格隔开：",n+1);
		scanf("%s%s%d",x.num,x.name,&x.age);
		getchar();
		insertSqlist(L,n+1,x);
		n++;
		printf("是否继续输入？Y/N：");
		yn=getchar();
	}
	while(yn=='Y'||yn=='y');
}




int xiugaiSqlist(Sqlist L,int i,STD x)                            //修改
{
	if(L.length==0)
	{
		printf("没有数据，不能修改！\n");
		return 0;
	}
	if(i<1||i>L.length)
	{
		printf("位置异常！\n");
		return 0;
	}
	L.data[i-1]=x;
	return 1;
}

int locationSqlist(Sqlist L,char *x)                             //按学号定位
{
	int i;
	if(L.length==0)
	{
		printf("没有数据！\n");
		return 0;
	}
	for(i=0;i<L.length;i++)
		if(strcmp(L.data[i].num,x)==0)
			return i+1;
		return 0;
}

int locationSqlistll(Sqlist L,char *x)                           //按姓名定位
{
	int i;
	if(L.length==0)
	{
		printf("没有数据！\n");
		return 0;
	}
	for(i=0;i<L.length;i++)
		if(strcmp(L.data[i].name,x)==0)
			return i+1;
		return 0;
}



int xianshiSqlist(Sqlist L)                          //遍历
{
	int i;
	if(L.length==0)
	{
		printf("没有数据！\n");
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
		if(n<0||n>10)
		{	printf("输入有误，请重新选择！按任意键继续\n");
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
			printf("请输入需要创建的学生人数：");
			scanf("%d",&maxsize);
			creatSqlist(&L,maxsize);
			printf("按任意键继续！\n");
			getch();
			break;
		case 2:
			printf("请输入需要插入的学生的学号姓名和年龄，用空格隔开：\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			int t;
			printf("请输入插入的位置（整形数字表示）：");
	        scanf("%d",&t);
			insertSqlist(&L,t,s);
			printf("按任意键继续！\n");
			getch();
			break;
		case 3:
			printf("请输入需要删除的学生的学号\n");
			scanf("%s",s.num);
			n=locationSqlist(L,s.num);
			deleteSqlist(&L,n,&s);
			printf("删除的学生数据为：%-10s%-10s%-4d\n",s.num,s.name,s.age);
			printf("按任意键继续！\n");
			getch();
			break;
		case 4:
			printf("请输入修改后的学生的学号姓名和年龄，用空格隔开：\n");
			scanf("%s%s%d",s.num,s.name,&s.age);
			n=locationSqlist(L,s.num);
			xiugaiSqlist(L,n,s);
			printf("按任意键继续！\n");
			getch();
			break;
		case 5:
			printf("请输入要查询的学生的学号：");
			scanf("%s",s.num);
			n=locationSqlist(L,s.num);
			if(n)
				printf("%-10s%-10s%-4d",L.data[n-1].num,L.data[n-1].name,L.data[n-1].age);
			else 
				printf("数据不存在！");
			printf("按任意键继续！\n");
			getch();
			break;
		case 6:
			printf("请输入要查询的学生的姓名：");
			scanf("%s",s.name);
			n=locationSqlistll(L,s.name);
			if(n)
				printf("%-10s%-10s%-4d",L.data[n-1].num,L.data[n-1].name,L.data[n-1].age);
			else 
				printf("数据不存在！");
			printf("按任意键继续！\n");
			getch();
			break;
		case 7:
			addSqlist(&L);
			printf("按任意键继续！\n");
			getch();
			break;
		case 8:
			printf("学生信息如下：\n");
			xianshiSqlist(L);
			printf("按任意键继续！\n");
			getch();
			break;
	
		case 0:
			exit(0);

		}
	}

}
