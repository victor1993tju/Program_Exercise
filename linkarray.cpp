#include<stdio.h>//NULL �Ķ�����������ͷ�ļ���
struct ListNode {
	int value;
	ListNode* pnext;
};

void AddToTail(ListNode** pHead,int value) {//���ֻ�Ƕ�ȡ������ListNode*����Ҫ�޸�ֵ�Ļ�ʹ��ListNode**. 
	ListNode * pNewnode = new ListNode();//��Ҫɾ���ڵ�ʱ�Ĳ�����delete pNewnode
	pNewnode->value = value;
	pNewnode->pnext = NULL; //��Ϊβ�ڵ��nextָ��Ϊ��
	//���������һ���ڵ�Ĵ�����������������ڵ����βָ��.
	// * �������ȡ���ݣ�&�������ȡ��ַ��
	if(*pHead==NULL){//���ͷָ��ָ��������ǿյģ�����û�����ݽڵ㡣
		*pHead = pNewnode;//���½����Ľڵ��Ϊ��һ�����ݽڵ�	
	}
	else {//���ͷָ��ָ������ݲ�Ϊ����˳�������ҵ�β�ڵ㡣
		ListNode * pNode = *pHead;//��ͷָ��ָ��ĵ�ַ����һ���µ�ָ�롣���ָ�����ڱ������������Ǳ������
		//�Ǳ���ģ������ pNode�滻�� (*pHead)�ı�*phead��ֵ�Ļ������˳���ʱ��*phead��ֵ�͸ı��� ��Ϊ�����������
		//�����ں������涨��һ����ʱ��ָ���������ְ��˹������飬�����ں����˳���ʱ���Զ�����ʧ�ˣ�����Ҳû�б�Ҫ��¼
		//ָ�������ʱ�̵�״̬������˲������Ŀ�ľʹﵽ�ˡ�
		while (pNode->pnext != NULL) {
			pNode = pNode->pnext;
		}
		pNode->pnext = pNewnode;
	}
}
void RemoveNode(ListNode** phead, int value) {
	//�������Ϊ�գ�����ָ�������Ϊ�գ���ֱ�ӷ���
	if (phead == NULL && *phead == NULL)
		return;
	else {
		ListNode * pDelete = NULL ;//����ָ���ɾ���Ľڵ�,��ʼ��ָ��ʹ��NULL
		ListNode * pNode = *phead; 
		//1����
		while ( pNode->pnext != NULL && pNode->pnext->value!=value){//�ȱ���
			pNode = pNode->pnext;//˳������һ��Ԫ��
		}
		//2��������ָ��
		if (pNode->pnext != NULL && pNode->pnext->value == value) {
			pDelete = pNode->pnext;//
			pNode->pnext = pNode->pnext->pnext;//Ҫ������ǰ�������ڵ�
		}
		//3ɾ���ռ�
		if (pDelete != NULL) {
			delete pDelete;
			pDelete = NULL;
		}
	}
}

void main() {
	ListNode * pnodenew = new ListNode(); //ListNode nodenew = new ListNode()���Ǵ���ģ����ܴ�ListNode * ת��ΪListNode
	//new ���ص���һ�ε�ַ�� Ҳ����ָ������ṹ���ָ�롣
	pnodenew->value = 1;
	pnodenew->pnext = NULL;
	AddToTail(&pnodenew, 2);//
	AddToTail(&pnodenew, 3);
	AddToTail(&pnodenew, 4);
	AddToTail(&pnodenew, 5);
	RemoveNode(&pnodenew, 3);
	ListNode nodenew;//�����Ǿ�̬�ķ�ʽ�����Ƕ�̬���䣬���Ƽ�ʹ��
	nodenew.value = 1;
	nodenew.pnext = NULL;
}