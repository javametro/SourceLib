#include <iostream>
using namespace std;

struct NodeL {
	int value;
	NodeL *next;
	NodeL(int value_=0, NodeL* next_=NULL) : value(value_), next(next_){}	
};

int GetLinkLength(NodeL* head){
	int count = 0;
	while(head){
		head = head->next;
		count++;
	}

	return count;
}

NodeL* FindFirstEqualNode(NodeL* head1, NodeL* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;
		
	int len1 = GetLinkLength(head1);
	int len2 = GetLinkLength(head2);

	NodeL* longNode;
	NodeL* shortNode;
	
	int leftNodeCount;
	if(len1 > len2){
		longNode = head1;
		shortNode = head2;
		leftNodeCount = len1 - len2;
	}else{
		longNode = head2;
		shortNode = head1;
		leftNodeCount = len2 - len1;
	}

	for(int i=0; i<leftNodeCount; i++){
		longNode = longNode->next;
	}

	while(longNode && shortNode && longNode != shortNode){
		longNode = longNode->next;
		shortNode = shortNode->next;
	}

	if(longNode){
		return longNode;
	}

	return NULL;
}

void FindFirstEqualNodeTest(){
	NodeL* head1 = new NodeL(0);
	NodeL* head2 = new NodeL(0);
	NodeL* node1 = new NodeL(1);
	NodeL* node2 = new NodeL(2);
	NodeL* node3 = new NodeL(3);
	NodeL* node4 = new NodeL(4);
	NodeL* node5 = new NodeL(5);
	NodeL* node6 = new NodeL(6);
	NodeL* node7 = new NodeL(7);

	head1->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node6;

	head2->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	NodeL* node = FindFirstEqualNode(head1, head2);
	if(node){
		cout << node->value << endl;
	}else{
		cout << "doesnt have common node" << endl;
	}
}

NodeL* ReverseList(NodeL* head){
	if(head == NULL){
		return NULL;
	}

	NodeL* reverseHead = NULL;
	NodeL* curNode = head;
	NodeL* preNode = NULL;
	while(curNode != NULL){
		NodeL* nextNode = curNode->next;
		if(nextNode == NULL){
			reverseHead = curNode;
		}

		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}

	return reverseHead;
}

void ReverseListTest(){
	for(int k=0; k<=10; k++){
		NodeL* head = NULL;
		NodeL* cur = NULL;
		
		for(int i=0; i<k; i++){
			NodeL* tmpNode = new NodeL(i);

			if(i == 0){
				cur = head = tmpNode;
			}else{
				cur->next = tmpNode;
				cur = tmpNode;
			}
		}

		cur = ReverseList(head);
		while(cur){
			cout << cur->value << " ";
			cur = cur->next;
		}

		cout << endl;
	}

	cout << endl;
}

NodeL* MergeList(NodeL* head1, NodeL* head2){
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	NodeL* head = NULL;
	if(head1->value < head2->value){
		head = head1;
		head1 = head1->next;
	}else{
		head = head2;
		head2 = head2->next;
	}

	NodeL* tmpNode = head;
	while(head1 && head2){
		if(head1->value < head2->value){
			head->next = head1;
			head1 = head1->next;
		}else{
			head->next = head2;
			head2 = head2->next;
		}

		head = head->next;
	}

	if(head1){
		head->next = head1;
	}else{
		head->next = head2;
	}

	return tmpNode;
}

void MergeListTest(){
	NodeL* head1 = new NodeL(1);
	NodeL* cur = head1;
	for(int i=3; i<10; i+=2){
		NodeL *tmpNode = new NodeL(i);
		cur->next = tmpNode;
		cur = tmpNode;
	}

	NodeL* head2 = new NodeL(2);
	cur = head2;
	for(int i=4; i<10; i+=2){
		NodeL* tmpNode = new NodeL(i);
		cur->next = tmpNode;
		cur = tmpNode;
	}

	NodeL *head = MergeList(head1, head2);
	while(head){
		cout << head->value << " ";
		head = head->next;
	}

	cout << endl;
}

NodeL* FindKthToTail(NodeL* head, unsigned int k){
	if(head == NULL || k == 0){
		return NULL;
	}

	NodeL* tmpNode = head;
	for(int i=0; i<k; i++){
		if(tmpNode != NULL){
			tmpNode = tmpNode->next;
		}else{
			return NULL;
		}
	}

	NodeL* kNode = head;
	while(tmpNode != NULL){
		kNode = kNode->next;
		tmpNode = tmpNode->next;
	}

	return kNode;
}

void FindKthToTailTest(){
	int nodeCount = 10;
	for(int k=0; k<nodeCount; k++){
		NodeL * head = NULL;
		NodeL * cur = NULL;
		for(int i=0; i<nodeCount; i++){
			NodeL *tmpNode = new NodeL(i);
			if(i == 0){
				cur = head = tmpNode;
			}else{
				cur->next = tmpNode;
				cur = tmpNode;
			}
		}

		NodeL* kNode = FindKthToTail(head, k+3);
		if(kNode){
			cout << "the reverse " << k + 3 << "th node is: " << kNode->value << endl;
		}else{
			cout << "the reverse " << k + 3 << "th node is not exist in the list." << endl;
		}

	}
}

void DeleteNode(NodeL *head, NodeL* delNode){
	if(!head || !delNode){
		return;
	}

	if(delNode->next != NULL){
		NodeL* next = delNode->next;
		delNode->next = next->next;
		delNode->value = next->value;
		delete next;
		next = NULL;
	}else if(head == delNode){
		delete delNode;
		delNode = NULL;
		head = NULL;
	}else{
		NodeL* tmpNode = head;
		while(tmpNode && tmpNode->next != delNode){
			tmpNode = tmpNode->next;
		}

		if(tmpNode != NULL){
			delete delNode;
			delNode = NULL;
			tmpNode->next = NULL;
		}
	}
}

void DeleteNodeTest(){
	int nodeCount = 10;
	for(int k=0; k<nodeCount; k++){
		NodeL* head = NULL;
		NodeL* cur = NULL;
		NodeL* delNode = NULL;
		
		for(int i=0; i<nodeCount; i++){
			NodeL* tmpNode = new NodeL(i);
			if(i == 0){
				cur = head = tmpNode;
			}else{
				cur->next = tmpNode;
				cur = tmpNode;
			}

			if(i == k){
				delNode = tmpNode;
			}
		}

		DeleteNode(head, delNode);
	}
}

void ReversePrintNode(NodeL* head){
	if(head){
		ReversePrintNode(head->next);
		cout << head->value << " ";
	}

}

void ReversePrintNodeTest(){
	NodeL *head = new NodeL();
	NodeL *cur = head;
	
	for(int i=1; i<10; i++){
		NodeL *tmpNode = new NodeL(i);
		cur->next = tmpNode;
		cur = tmpNode;
	}

	ReversePrintNode(head);
	cout << endl;
}

struct NodeT{
	int value;
	NodeT* left;
	NodeT* right;
	NodeT(int value_=0, NodeT* left_=NULL, NodeT* right_=NULL): value(value_), left(left_), right(right_){}
};

void TreeClass(NodeT * root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	NodeT* tmpNode = root->left;
	root->left = root->right;
	root->right = tmpNode;
	TreeClass(root->left);
	TreeClass(root->right);
}

void PrintTree(NodeT *root){
	if(root){
		cout << root->value << " ";
		PrintTree(root->left);
		PrintTree(root->right);
	}
}

void TreeClassTest(){
	NodeT* root = new NodeT(8);
	NodeT* n1 = new NodeT(6);
	NodeT* n2 = new NodeT(10);
	NodeT* n3 = new NodeT(5);
	NodeT* n4 = new NodeT(7);
        NodeT* n5 = new NodeT(9);
        NodeT* n6 = new NodeT(11);

	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	PrintTree(root);
	cout << endl;
	TreeClass(root);
	PrintTree(root);
	cout << endl;
	
}

void MergeArray(int a[], int alen, int b[], int blen){
	int len = alen + blen -1;
	alen--;
	blen--;
	
	while(alen >= 0 && blen >= 0){
		if(a[alen] > b[blen]){
			a[len--] = a[alen--];
		}else{
			a[len--] = b[blen--];
		}
	}

	while(alen >= 0){
		a[len--] = a[alen--];
	}

	while(blen >= 0){
		a[len--] = b[blen--];
	}
}

void MergeArrayTest(){
	int a[] = {2, 4, 6, 8, 10, 0, 0, 0, 0, 0};
	int b[] = {1, 3, 5, 7, 9};
	
	MergeArray(a, 5, b, 5);
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
		cout << a[i] << " ";
	}
	
	cout << endl;
}

int main(){
	//MergeListTest();
	//MergeArrayTest();
	//ReversePrintNodeTest();
	//DeleteNodeTest();
	//	FindKthToTailTest();
	//	ReverseListTest();
	FindFirstEqualNodeTest();
	return 0;
}
