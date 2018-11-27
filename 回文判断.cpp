#include<stdio.h>
#include<malloc.h>
typedef char Lelem;
typedef struct snode
{
	Lelem data;
	struct snode *next;
}Snode,*Slink;

void initstack(Slink *S)
{
	*S=NULL;
}
int stackempty(Slink S)
{
	if(S==NULL)
		return 1;
	else 
		return 0;
}
void pushstack(Slink *S,char e)
{
	Slink p=(Slink)malloc(sizeof(Snode));
	p->data=e;
	p->next=*S;
	*S=p;

}

int popstack(Slink *S,Lelem *e)
{
	Slink p=*S;
	if(*S==NULL)
		return 0;
	*S=(*S)->next;
	*e=p->data;
	return 1;
}

typedef struct qnode
{
	Lelem data;
	struct qnode *next;
}Qnode, *Queuelink;
typedef struct 
{
	Queuelink front;
	Queuelink rear;
}Qlink; 

int initqueue(Qlink *Q)
{
	Q->front=Q->rear=(Queuelink)malloc(sizeof(Qnode));
	if(Q->front==NULL)
		return 0;
	Q->front->next=NULL;
	return 1;
}

int queueempty(Qlink Q)
{
	if(Q.front==Q.rear)
		return 1;
	else 

		return 0;
}

int enqueue(Qlink *Q,Lelem e)
{
	Queuelink p=(Queuelink)malloc(sizeof(Qnode));
	if(p==NULL)
		return 0;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return 1;
}

int deletequeue(Qlink *Q,Lelem *e)
{
	Queuelink p;
	if(Q->front==Q->rear)
		return 0;
	*e=Q->front->next->data;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return 1;
}

int huiwen(char c[])
{
	Slink S;
	Qlink Q;
	char s,q;
	int i=0;
	initstack(&S);
	initqueue(&Q);
	while(c[i]!='&')
	{
		pushstack(&S,c[i++]);
	}

	 i++;
	while(c[i]!='@') 
	{
		enqueue(&Q,c[i++]);
	}
	while(!stackempty(S) && !queueempty(Q) )
	{
		popstack(&S,&s);
		deletequeue(&Q,&q);
		if(s!=q)
			break;
		}
		if(stackempty(S) && queueempty(Q))  
			return 1;
		else 
			return 0;

	

}

void main()
{
	printf("判断一串字符串是否为回文字符串\n");
	printf("请输入要判断的字符串，中间以&隔开，末尾添加@：");
	char c[80];
	scanf("%s",c);
//	printf("%s\n",c);
	int n;
	n=huiwen(c);
	if(n==1)
		printf("该字符串是回文字符串\n");
	else
		printf("该字符串不是回文字符串\n");


}