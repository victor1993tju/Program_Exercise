#include<stdio.h>//NULL 的定义包含在这个头文件中
struct ListNode {
	int value;
	ListNode* pnext;
};

void AddToTail(ListNode** pHead,int value) {//如果只是读取可以用ListNode*，需要修改值的话使用ListNode**. 
	ListNode * pNewnode = new ListNode();//需要删除节点时的操作，delete pNewnode
	pNewnode->value = value;
	pNewnode->pnext = NULL; //因为尾节点的next指针为空
	//至此完成了一个节点的创建，接下来把这个节点放在尾指针.
	// * 运算符是取内容，&运算符是取地址。
	if(*pHead==NULL){//如果头指针指向的内容是空的，表明没有数据节点。
		*pHead = pNewnode;//让新建立的节点成为第一个数据节点	
	}
	else {//如果头指针指向的内容不为空则顺着链表找到尾节点。
		ListNode * pNode = *pHead;//将头指针指向的地址赋给一个新的指针。这个指针用于遍历整个链表，是必须的吗？
		//是必须的，如果将 pNode替换成 (*pHead)改变*phead的值的话函数退出的时候，*phead的值就改变了 因为它是输入参数
		//所以在函数里面定义一个临时的指针来做这种搬运工的事情，他们在函数退出的时候自动就消失了，我们也没有必要记录
		//指针在最后时刻的状态，完成了插入操作目的就达到了。
		while (pNode->pnext != NULL) {
			pNode = pNode->pnext;
		}
		pNode->pnext = pNewnode;
	}
}
void RemoveNode(ListNode** phead, int value) {
	//如果输入为空，或者指向的链表为空，则直接返回
	if (phead == NULL && *phead == NULL)
		return;
	else {
		ListNode * pDelete = NULL ;//用于指向待删除的节点,初始化指针使用NULL
		ListNode * pNode = *phead; 
		//1查找
		while ( pNode->pnext != NULL && pNode->pnext->value!=value){//先遍历
			pNode = pNode->pnext;//顺延至下一个元素
		}
		//2重新连接指针
		if (pNode->pnext != NULL && pNode->pnext->value == value) {
			pDelete = pNode->pnext;//
			pNode->pnext = pNode->pnext->pnext;//要把连接前后两个节点
		}
		//3删除空间
		if (pDelete != NULL) {
			delete pDelete;
			pDelete = NULL;
		}
	}
}

void main() {
	ListNode * pnodenew = new ListNode(); //ListNode nodenew = new ListNode()法是错误的，不能从ListNode * 转化为ListNode
	//new 返回的是一段地址， 也就是指向这个结构体的指针。
	pnodenew->value = 1;
	pnodenew->pnext = NULL;
	AddToTail(&pnodenew, 2);//
	AddToTail(&pnodenew, 3);
	AddToTail(&pnodenew, 4);
	AddToTail(&pnodenew, 5);
	RemoveNode(&pnodenew, 3);
	ListNode nodenew;//这种是静态的方式，不是动态分配，不推荐使用
	nodenew.value = 1;
	nodenew.pnext = NULL;
}