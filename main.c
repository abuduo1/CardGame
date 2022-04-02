#include"head.h" 

int main() {
	link *head;
	int i,card,order;
	head=Great_link();
	cout<<"请选择你要进行的操作："<<endl<<"1 添加结点；2 删除结点；3 保存到文件；4 从文件读入；5 打印循环链表；0 退出。"<<endl;
	while(1){
	cin>>order;
	if(order==0)  break;
	switch(order){
		case 1: Add_Node(head);break;
		case 2: Cut_Node(head);break;
		case 3: Store_link(head);break;
		case 4: Back_head(head);break;
		case 5: Print_link(head);break;
		default: cout<<"输入信息错误，请重新输入。"<<endl;break; 
	}
  }
	return 0;
}
