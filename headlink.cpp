/*带头结点的单向链表，用引用变量*/

//编译预处理命令
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//自定义的数据类型
typedef struct ss
{
	int data;
	struct ss*next;
}NODE,*LINK;


//函数声明
int initHeadLink(LINK &);//初始化
void creatHeadLink(LINK &);//创建
int insertHeadLink(LINK,int,int);//插入
int deleteHeadLink(LINK,int);//删除
void dispHeadLink(LINK);//遍历函数
int lenHeadLink(LINK);//求数据个数
int menu();//菜单
void wait();//等待



//函数定义
/*初始化函数的功能是建立一个带头结点的空链表*/
int initHeadLink(LINK &H)
{
	H=new NODE;//申请头结点的空间
	H->next=NULL;
	return 1;

}

/*插入函数的功能是将数据按指定的位置插入到链表中*/
int insertHeadLink(LINK H,int pos,int x)
{
     LINK p=H,s; int k=0;
	 //将p移到第pos-1个结点
	 while(p!=NULL && k<pos-1)
	 {
		 k++; p=p->next;
	 }
     //判断位置是否合法
	 if(k>pos-1)
	 {
		 printf("位置过小！\n");return 0;
	 }
     if(p==NULL)
	 {
		 printf("位置过大！\n");return 0;
	 }
	 //生成新结点，并插入
	 s=new NODE; s->data=x;
	 s->next=p->next;  p->next=s;
	 return 1;
}

/*删除函数的功能是将指定的位置的结点删除*/
int deleteHeadLink(LINK H,int pos)
{
     LINK p=H,q; int k=0;
	 //判断链表是否为空
     if(H->next==NULL)
	 {
		 printf("没有数据!\n");
		 return 0;
	 }
	 //将p移到第pos-1个结点
	 while(p->next!=NULL && k<pos-1)
	 {
		 k++; p=p->next;
	 }
     //判断位置是否合法
	 if(k>pos-1)
	 {
		 printf("位置过小！\n");return 0;
	 }
     if(p->next==NULL)
	 {
		 printf("位置过大！\n");return 0;
	 }
	 //删除结点
	 q=p->next;
	 p->next=q->next;  delete q;
	 return 1;
}

/*调用插入函数，将数据依序放入链表*/
void creatHeadLink(LINK &H)
{
    int x,n=1,yn;
	initHeadLink(H);//创建空链表
	do 
	{
		printf("请输入一个整数：");
		scanf("%d",&x);
		getchar();//吃回车
        insertHeadLink(H,n,x);
		n++;
		printf("继续吗？yes=1,no=0: ");
		scanf("%d",&yn);
		getchar();//吃回车
		if(yn==0)break;
	} while (1);
}

/*遍历，依序访问每一个结点*/
void dispHeadLink(LINK H)
{
	if(H->next==NULL)
	{
		printf("没有数据！\n"); return ;
	}
    printf("\n链表中的数据为:\n");
	H=H->next;
	while(H)
	{
		printf("%d ",H->data);
		H=H->next;//移到下一个结点
	}
	printf("\n");
}
 
/*等待*/
void wait()
{
	printf("按任意键继续!\n");
	getch();
}

/*求链表中的数据个数*/
int lenHeadLink(LINK H)
{
	int n=0;
	if(H->next==NULL)return n ;
	H=H->next;
	while(H)
	{ 
		n++;
		H=H->next;
	}
	return n;
}


int menu()
{
	int n;
	while(1)
	{
		system("cls");
		printf("*****带头结点的单向链表*****\n");
		printf("     1--创建    2--插入\n");
		printf("     3--删除    4--显示\n");
		printf("     0--退出\n");
		printf("****************************\n");
		printf("      请选择编号:");
		scanf("%d",&n);
		if(n>=0&&n<=4)return n;
	}
}

/*主函数*/
void main()
{
	LINK H; int num,pos,x,len;
	initHeadLink(H);//创建空链表
	while(1)
	{
		num=menu();//调用菜单函数，得到功能编号 
		switch(num)
		{
		case 1://创建
			   creatHeadLink(H);
			   dispHeadLink(H);
			   wait();
			   break;

		case 2://插入
			   len=lenHeadLink(H);//求数据个数
			   printf("请输入插入的位置[1,%d]",len+1);
			   scanf("%d",&pos);
			   if(pos<1 || pos>len+1)printf("位置非法!\n");
			   else
			   {
    			   printf("请输入插入的整数:");
 	     		   scanf("%d",&x);
                   if(insertHeadLink(H,pos,x)==1)
				   dispHeadLink(H);
			   }
			   wait();
			   break;

		case 3://删除
			   len=lenHeadLink(H);//求数据个数
			   if(len==0)		   
				   printf("没有数据!\n");
			   else
			   {
				   printf("请输入删除的位置[1,%d]",len);
			       scanf("%d",&pos);
			       if(deleteHeadLink(H,pos)==1)
				         dispHeadLink(H);
			   }
			   wait();
			   break;

		case 4://显示
			   dispHeadLink(H);
			   wait();
			   break;

		case 0:exit(0);
		}
	}
}