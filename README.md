先创建一个链表（void Print_class(link *head);）来存储要参加的学生的数据，然后再创建一个主菜单,给用户五个操作选择:
用switch case来表示五个选择的关系，分别制作一个模块函数；
（1 添加结点link * Add_Node(link *head);
2 删除结点link * Cut_Node(link *head); 
3 保存到文件link* Store_link(link *head); 
4 从文件读入link* Back_head(link *head);
6 直接break退出。）
而另外三个函数（int Choose_card(void);  void Print_class(link *head);  link* exchange(link *head);）是用于引用在其他函数中，简化操作。
其中Choose_card引用了二进制进行随机抽卡，用于创建链表中给同学卡牌；
由于要多次输出同学的所以数据，所以用Print_class来简化代码；exchange就是交换数据，用于选项5中循环输出中的操作。
最后用主函数连接。
