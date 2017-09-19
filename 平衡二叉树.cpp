1.定义
	1.1二叉查找树
	1.2左子树与右子树之差的绝对值不超过1
	1.3
		struct node{
			int v, height;
			node*lchild, *rchild;
		} 
		
2.查找
void search(node* root, int x){
	if(root == NULL){
		printf("search failed\n");
		return;
	}
	if(x == root->data){
		printf("%d\n", root->data);
	}
	else if(x < root->data){
		search(root->lchild, x);
	}
	else{
		search(root->rchild, x);
	}
}

3.插入操作
	3.1左旋
	void L(node* &root){
		node* temp = root->rchild;
		root->rchild = temp->lchild;
		temp->lchild = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}
	3.2右旋
	void R(node* &root){
		node* temp = root->lchild;
		root->lchild = temp->rchild;
		temp->rchild = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}




















