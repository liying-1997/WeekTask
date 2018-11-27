#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct snode
{
	char data;
	struct snode *next;
}node,*Link;

typedef struct
{
	char data[MAX];
	int front;
	int rear;
	int maxSize;
}queue;

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

void initQ(queue &Q)
{
	Q.front=Q.rear=0;
	Q.maxSize=MAX;
}

int enterQ(queue &Q,char e)
{
	if((Q.rear+1)%Q.maxSize==Q.front)
	{
		printf("队列已满!");
		return 0;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.maxSize;
	return 1;
}

int outQ(queue &Q,char *e)
{
	if(Q.front==Q.rear)
	{
		printf("队列为空!");
		return 0;
	}
    *e=Q.data[Q.front];
	Q.front=(Q.front+1)%Q.maxSize;
	return 1;
}

void huiwen(char c[])
{
	Link S;
	queue Q;
	initS(S);
	initQ(Q);
	char s1,q1;
	int n=0,i;
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
		printf("是回文!\n");
	else
		printf("不是回文!\n");
	}
}

void main()
{
	char ch[80];
	printf("输入一串字符:");
	gets(ch);
	huiwen(ch);
}


