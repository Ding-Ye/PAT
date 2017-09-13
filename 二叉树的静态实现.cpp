1.静态二叉链表
struct node{
	typename data;
	int lchild;
	int rchild;
}Node[maxn];

2.创建
int index = 0;
int newNode(int v){
	Node[index].data = v;
	Node[index].lchild = -1;
	Node[index].rchild = -1;
	return index++;
}

3.二叉树的查找，插入，建立
void search(int root, int x, int newdata){
	if(root == -1){
		return;
	}
	if(Node[root].data == x){
		Node[root].data = newdata;
	}
	search(Node[root].lchild, x, newdata);
	search(Node[root].rchild, x, newdata);
}

void insert(int &root, int x){
	if(root == -1){
		root = newNode(x);
		return;
	}
	if(由二叉树的性质x应该插在左子树){
		insert(Node[root].lchild, x);
	}
	else{
		insert(Node[root].rchild, x);
	}
}

int Create(int data[], int n)













