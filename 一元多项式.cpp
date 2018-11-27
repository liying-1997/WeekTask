#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
typedef struct
{
	float coef; 
	int exp;
}Term;
typedef struct node
{
	Term data;
	struct node *next;
}Pnode, *Plink;
void insert(Plink L,Term x);
void creat(Plink *L);
void add(Plink La,Plink Lb,Plink *Lc);
void mul(Plink La,Plink Lb,Plink *Lc);
int menu();


void insert(Plink L,Term x)
{
	Plink p=L,q=L->next,s;
	while(p)
	{
		if(q!=NULL && x.exp>p->data.exp && x.exp<q->data.exp)
		{
			s=(Plink)malloc(sizeof(Pnode));
			s->data=x;
			s->next=q;
			p->next=s;
			return;
		}
		else if(q!=NULL && x.exp==q->data.exp)
		{
			if(fabs(q->data.coef+x.coef)<1.0E-6)
			{
				p->next=q->next;
				delete q;
				return;
			}
			else
			{
				q->data.coef=x.coef+q->data.coef;
				return;
			}
		}
		else if(q==NULL && x.exp>p->data.exp)
		{
			s=(Plink)malloc(sizeof(Pnode));
			s->data=x;
			s->next=p->next;
			p->next=s;
			return;
		}
		else
		{
			p=q;
			q=q->next;
		}
	}
}

void creat(Plink *L)
{
	Term x;
	*L=(Plink)malloc(sizeof(Pnode));
	(*L)->data.exp=-1;
	(*L)->next=NULL;
	do
	{
		printf("请输入系数和指数，用空格隔开，系数为0表示结束：");
		scanf("%f%d",&x.coef,&x.exp);
		if(fabs(x.coef)<=1.0e-6)
			break;
		insert(*L,x);
	}while(1);
}

void add(Plink La,Plink Lb,Plink *Lc)
{
	Plink s,pa,pb,pc;
	*Lc=(Plink)malloc(sizeof(Pnode));
	(*Lc)->data.exp=-1;
	(*Lc)->next=NULL;
	pa=La->next;
	pb=Lb->next;
	pc=*Lc;
	while(pa && pb)
	{
		if(pa->data.exp<pb->data.exp)
		{
			s=(Plink)malloc(sizeof(Pnode));
			s->data=pa->data;
			s->next=NULL;
			pc->next=s;
			pc=s;
			pa=pa->next;
		}
		else if(pa->data.exp==pb->data.exp)
		{
			if(fabs(pa->data.coef+pb->data.coef>1.0E-6))
			{
				s=(Plink)malloc(sizeof(Pnode));
				s->data.coef=pa->data.coef+pb->data.coef;
				s->data.exp=pa->data.exp;
				s->next=NULL;
				pc->next=s;
				pc=s;
			}
			pa=pa->next;
			pb=pb->next;

		}
		else
		{
			s=(Plink)malloc(sizeof(Pnode));
			s->data=pb->data;
			s->next=NULL;
			pc->next=s;
			pc=s;
			pb=pb->next;

		}

	}
	while(pa)
	{
		s=(Plink)malloc(sizeof(Pnode));
		s->data=pa->data;
		s->next=NULL;
		pc->next=s;
		pc=s;
		pa=pa->next;
	}
	while(pb)
	{
		s=(Plink)malloc(sizeof(Pnode));
		s->data=pb->data;
		s->next=NULL;
		pc->next=s;
		pc=s;
		pb=pb->next;
	}

}


void mul(Plink La,Plink Lb,Plink *Lc)
{
	Plink pa,pb;
	Term x;
	*Lc=(Plink)malloc(sizeof(Pnode));
	(*Lc)->data.exp=-1;
	(*Lc)->next=NULL;
	pa=La->next;
	while(pa)
	{
		pb=Lb->next;
		while(pb)
		{
			x.coef=pa->data.coef*pb->data.coef;
			x.exp=pa->data.exp+pb->data.exp;
			insert(*Lc,x);
			pb=pb->next;
		}
		pa=pa->next;
	}

}

void display(Plink L)
{
	Plink p=L->next;
	while(p)
	{
		if(p->data.coef<0)
			printf("%0.2fX^%d",p->data.coef,p->data.exp);
		else 
			printf("+%0.2fX^%d",p->data.coef,p->data.exp);
		p=p->next;
	}
	printf("\n");
}


int menu()
{
	int n;
	while(1)
	{
		system("cls");
		printf("****一元多项式的应用****\n");
		printf("1 创建第一个一元多项式\n");
		printf("2 创建第二个一元多项式\n");
		printf("3 进行多项式加法运算\n");
		printf("4 进行多项式乘法运算\n");
		printf("5 输出计算结果\n");
		printf("0 退出系统 \n");
		printf("************************\n");
		printf("请选择功能编号0-5  ");
			scanf("%d",&n);
		getchar();
		if(n<0||n>5)
		{	printf("输入有误，请重新选择！按任意键继续\n");
		getch();}
		else
			return n;
	}
}


void main()
{
	Plink L1,L2,L3;
	int n;
	while(1)
	{
		n=menu();
		switch(n)
		{
		case 1:
			printf("创建第一个多项式：\n");
			creat(&L1);
			printf("按任意键继续！\n");
			getch();
			break;       
		case 2:
			printf("创建第二个多项式：\n");
			creat(&L2);
			printf("按任意键继续！\n");
			getch();
			break;                          
		case 3:
			printf("将已创建的两个一元多项式进行加法运算\n");
			add(L1,L2,&L3);
			printf("按任意键继续！\n");
			getch();
			break;
		case 4:
			printf("将已创建的两个一元多项式进行乘法运算\n");
			mul(L1,L2,&L3);
			printf("按任意键继续！\n");
			getch();
			break;
		case 5:
			printf("计算结果如下：\n");
			display(L3);
			printf("按任意键继续！\n");
			getch();
			break;
	
		case 0:
			exit(0);

		}
	}

}




