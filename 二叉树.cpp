1.二叉链表的定义
struct node {
	typename data;
	node* lchild;
	node* rchild;
}

2.创建新结点
node* newNode(int v){
	node* Node = new node;
	Node -> data = v;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}

3.查找并修改
void search(node* root, int x, int newdata){
	if(root == NULL){
		return;
	}
	if(root->data ==x){
		root->data = newdata;
	}
	search(root->lchild, x, newdata);
	search(root->rchild, x, newdata);
}

4.二叉树结点的插入//不是很懂
void insert(node* &root, int x){//node* &root  和node*root 之间的区别
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(由二叉树的性质， x应该插在左子树){
		inser(root->lchild, x);
	}
	else{
		insert(root->rchild, x);
	}
}

5.二叉树的创建
node* Create(int data[], int n){
	node* root = NULL;
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	}
	return root;
}





































































