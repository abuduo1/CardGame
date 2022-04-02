#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std; 
typedef struct Node{
	int card_num;     //交换前卡牌数字 
	int card_num1;     //交换后卡牌数字
	char name[15];
	struct Node * next;
}link;

int Choose_card(void);
void Print_class(link *head);
link* exchange(link *head);
link* Great_link();
link * Add_Node(link *head);
link * Cut_Node(link *head);
link* Store_link(link *head);
link* Back_head(link *head);
void Print_link(link *head);
head.c:
#include"head.h" 

int Choose_card(void){
	static unsigned CardsStatus[2],Left_cards=52;
	srand(time(NULL));
	int n,i;
	n=rand()%Left_cards+1;
	for(i=0;i<n;i++){
		if(!(CardsStatus[i/32]&&(0x00000001<<(i%32))))
		  n--;
		if(n==0){
			CardsStatus[i/32]^=0x00000001<<(i%32);
			Left_cards--;}
		break;
	}
	return n;
}

void Print_class(link *head){
	link *p1;
	p1=head->next; 
	while(p1->next!=NULL){ 
		printf("学生名字：%s  扑克牌数字：%d\n",p1->name,p1->card_num);
		p1=p1->next;
	}
	printf("\n\n");
}

link* exchange(link *head){      //随机交换顺序 
	link *p,*p1,*p2;
	int i,t,a[20],stu_num=0;
	p=head->next;
	for(i=0;p->next!=NULL;i++){
		a[i]=p->card_num;
		stu_num++;
		p=p->next;
	}
	p1=head->next;
	for(i=0;i<stu_num;i++){
		t=rand()%stu_num+1; 
		p1->card_num1=a[t];
		p1=p1->next;
	}
	head->next=p1;
	return head;
} 

link* Great_link(){
	link *p,*p1,*q,*head;
	int i,j,stu_num;
	cout<<"请输入要参加游戏的同学的数量（参加的同学数量）："<<endl;
	cin>>stu_num; 
	cout<<"请输入要参加游戏的同学的名字："<<endl; 
	head=p=(link *)malloc(sizeof(link));
	for(i=0;i<stu_num;i++){
		q=(link*)malloc(sizeof(struct Node));
		q->card_num=Choose_card();
		q->card_num1=0;          //为交换前把数字都先设为0 
		scanf("%s",&q->name);
		p->next=q;
		p=q;
	}
	q->next=NULL;
	Print_class(head);
    return head;
}

link * Add_Node(link *head){
	char add_name[15];
	link *p,*q,*p1;
	cout<<"请输入你要增加学生的名字："<<endl;
	cin>>add_name; 
	p=head->next;
	q=(link*)malloc(sizeof(struct Node));
	q->card_num=Choose_card();
	cout<<"这个学生抽牌抽中 "<<q->card_num<<endl; 
	q->card_num1=0;                                             //为交换前把数字都先设为0 
	p->next=q;
	q->next=p->next;
	printf("增加后学生名字及其手中的扑克牌如下\n");
	Print_class(head);
	return head;
} 

link * Cut_Node(link *head){
	char cut_name[15];
	link *p,*q,*p1;
	cout<<"请选择你要删除的节点，输入此节点储存的学生的名字："<<endl;
	scanf("%s",cut_name); 
	p=head->next;
	while(p->next!=NULL){
		if(strcmp(p->name,cut_name)==0){
			q=p->next;
			q->next=p->next;
			free(q);
			p=p->next;
		}
		else p=p->next;
	}
	printf("删除后学生名字及其手中的扑克牌如下\n");
	Print_class(head);
	return head;
} 

link* Store_link(link *head){
	cout<<"结点的添加和删除操作已完成，保存到文件的学生数据有："<<endl;
	link *p1;
	p1=head->next; 
	while(p1->next!=NULL){
		printf("学生名字：%s  扑克牌数字：%d\n",p1->name,p1->card_num);
		p1=p1->next;
	}
	printf("\n\n");
	return head;
}

link* Back_head(link *head){          //交换数字后从程序输出交换前交换后的卡牌 
    link *p1;
	head=exchange(head);
	p1=head->next; 
	while(p1->next!=NULL){ 
		printf("学生名字：%s   扑克牌数字 交换前：%d  交换前：%d\n",p1->name,p1->card_num,p1->card_num1);
		p1=p1->next;
	}
	printf("\n\n");
}

void Print_link(link *head){       
	link *p,*q,*head_min,*p1,*p2;
	int min,out_num;
	p=head->next;               //寻找最小值
	while(p->next!=NULL){
		q=p->next;
		if(p->card_num>q->card_num)
		  min=q->card_num;
		else min=p->card_num;
		p=p->next;
	}
	 while(p->next!=NULL){
		if(p->card_num=min){
			head_min=p;
			break;
		}
		else p=p->next;
	}
	cout<<"出列规则为：从卡牌最小的同学开始，找到与他交换前数字相同的同学出列。"<<endl;
	cout<<"再根据出列同学交换前数字找到下一同学，依次循环，直至全部出列"<<endl; 
	cout<<"出列学生依次为："<<endl; 
	out_num=min;
	p1=head->next;
	while(1){
	while(p1->next!=NULL){
		if(p1->card_num1==out_num){
			printf("学生名字：%s   扑克牌数字 交换前：%d  交换前：%d\n",p1->name,p1->card_num,p1->card_num1);
			p1->card_num=out_num;
			p2=p1->next;
			p2->next=p1->next;
			free(p2);
			break;
		}
		else p1=p1->next;
	}
    }
}
