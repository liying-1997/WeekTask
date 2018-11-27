/*��ͷ���ĵ������������ñ���*/

//����Ԥ��������
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//�Զ������������
typedef struct ss
{
	int data;
	struct ss*next;
}NODE,*LINK;


//��������
int initHeadLink(LINK &);//��ʼ��
void creatHeadLink(LINK &);//����
int insertHeadLink(LINK,int,int);//����
int deleteHeadLink(LINK,int);//ɾ��
void dispHeadLink(LINK);//��������
int lenHeadLink(LINK);//�����ݸ���
int menu();//�˵�
void wait();//�ȴ�



//��������
/*��ʼ�������Ĺ����ǽ���һ����ͷ���Ŀ�����*/
int initHeadLink(LINK &H)
{
	H=new NODE;//����ͷ���Ŀռ�
	H->next=NULL;
	return 1;

}

/*���뺯���Ĺ����ǽ����ݰ�ָ����λ�ò��뵽������*/
int insertHeadLink(LINK H,int pos,int x)
{
     LINK p=H,s; int k=0;
	 //��p�Ƶ���pos-1�����
	 while(p!=NULL && k<pos-1)
	 {
		 k++; p=p->next;
	 }
     //�ж�λ���Ƿ�Ϸ�
	 if(k>pos-1)
	 {
		 printf("λ�ù�С��\n");return 0;
	 }
     if(p==NULL)
	 {
		 printf("λ�ù���\n");return 0;
	 }
	 //�����½�㣬������
	 s=new NODE; s->data=x;
	 s->next=p->next;  p->next=s;
	 return 1;
}

/*ɾ�������Ĺ����ǽ�ָ����λ�õĽ��ɾ��*/
int deleteHeadLink(LINK H,int pos)
{
     LINK p=H,q; int k=0;
	 //�ж������Ƿ�Ϊ��
     if(H->next==NULL)
	 {
		 printf("û������!\n");
		 return 0;
	 }
	 //��p�Ƶ���pos-1�����
	 while(p->next!=NULL && k<pos-1)
	 {
		 k++; p=p->next;
	 }
     //�ж�λ���Ƿ�Ϸ�
	 if(k>pos-1)
	 {
		 printf("λ�ù�С��\n");return 0;
	 }
     if(p->next==NULL)
	 {
		 printf("λ�ù���\n");return 0;
	 }
	 //ɾ�����
	 q=p->next;
	 p->next=q->next;  delete q;
	 return 1;
}

/*���ò��뺯���������������������*/
void creatHeadLink(LINK &H)
{
    int x,n=1,yn;
	initHeadLink(H);//����������
	do 
	{
		printf("������һ��������");
		scanf("%d",&x);
		getchar();//�Իس�
        insertHeadLink(H,n,x);
		n++;
		printf("������yes=1,no=0: ");
		scanf("%d",&yn);
		getchar();//�Իس�
		if(yn==0)break;
	} while (1);
}

/*�������������ÿһ�����*/
void dispHeadLink(LINK H)
{
	if(H->next==NULL)
	{
		printf("û�����ݣ�\n"); return ;
	}
    printf("\n�����е�����Ϊ:\n");
	H=H->next;
	while(H)
	{
		printf("%d ",H->data);
		H=H->next;//�Ƶ���һ�����
	}
	printf("\n");
}
 
/*�ȴ�*/
void wait()
{
	printf("�����������!\n");
	getch();
}

/*�������е����ݸ���*/
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
		printf("*****��ͷ���ĵ�������*****\n");
		printf("     1--����    2--����\n");
		printf("     3--ɾ��    4--��ʾ\n");
		printf("     0--�˳�\n");
		printf("****************************\n");
		printf("      ��ѡ����:");
		scanf("%d",&n);
		if(n>=0&&n<=4)return n;
	}
}

/*������*/
void main()
{
	LINK H; int num,pos,x,len;
	initHeadLink(H);//����������
	while(1)
	{
		num=menu();//���ò˵��������õ����ܱ�� 
		switch(num)
		{
		case 1://����
			   creatHeadLink(H);
			   dispHeadLink(H);
			   wait();
			   break;

		case 2://����
			   len=lenHeadLink(H);//�����ݸ���
			   printf("����������λ��[1,%d]",len+1);
			   scanf("%d",&pos);
			   if(pos<1 || pos>len+1)printf("λ�÷Ƿ�!\n");
			   else
			   {
    			   printf("��������������:");
 	     		   scanf("%d",&x);
                   if(insertHeadLink(H,pos,x)==1)
				   dispHeadLink(H);
			   }
			   wait();
			   break;

		case 3://ɾ��
			   len=lenHeadLink(H);//�����ݸ���
			   if(len==0)		   
				   printf("û������!\n");
			   else
			   {
				   printf("������ɾ����λ��[1,%d]",len);
			       scanf("%d",&pos);
			       if(deleteHeadLink(H,pos)==1)
				         dispHeadLink(H);
			   }
			   wait();
			   break;

		case 4://��ʾ
			   dispHeadLink(H);
			   wait();
			   break;

		case 0:exit(0);
		}
	}
}