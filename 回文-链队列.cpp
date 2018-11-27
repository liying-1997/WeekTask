#include<stdio.h>
#include<stdlib.h>

typedef struct snode
{
	char data;
	struct snode *next;
}node,*Link;

typedef struct qnode
{
	char data;
	struct qnode *next;
}Qnode,*Queue;

typedef struct
{
	Queue front;
	Queue rear;
}Qlink;

void initS(Link &S)
{
	S=NULL;
}

void pushS(Link &S,char e)
{
	Link p=new snode;
	p->data=e;
	p->next=S;
	S=p;
}

int popS(Link &S,char *e)
{
	if(S==NULL)
	{
		printf("栈为空!");
		return 0;
	}
	Link p=S;
	*e=p->data;
	S=p->next;
	delete p;
	return 1;
}

int initQ(Qlink &Q)
{
	Q.front=Q.rear=new qnode;
	if(Q.front==NULL)
		return 0;
	Q.front->next=NULL;
	return 1;
}

int enterQ(Qlink &Q,char e)
{
	Queue p=new qnode;
	if(p==NULL)
		return 0;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

int outQ(Qlink &Q,char *e)
{
	Queue p;
	if(Q.rear==Q.front)
		return 0;
	*e=Q.front->next->data;
	p=Q.front->next;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	delete p;
	return 1;
}

void huiwen(char c[])
{
	Link S;
	Qlink Q;
	initS(S);
	initQ(Q);
	int n=0,i;
	char e,q1,s1;
	while(c[n]!='\0')
		n++;
	if(n%2!=0)
		printf("不是回文!");
	else
	{
		for(i=0;i<n/2;i++)
			pushS(S,c[i]);
		for(i=n/2;i<n;i++)
			enterQ(Q,c[i]);
		while(S!=NULL&&Q.front!=Q.rear)
		{
			popS(S,&s1);
			outQ(Q,&q1);
			if(s1!=q1)
				break;
		}
		if(S==NULL&&Q.front==Q.rear)
			printf("是回文!");
		else
			printf("不是回文!");
	}
}

void main()
{
	char str[80];
	printf("请输入一串字符:");
	gets(str);
	huiwen(str);
}