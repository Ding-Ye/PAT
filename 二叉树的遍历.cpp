1。先序遍历
void preorder(node* root){
	if(root == NULL){
		return;
	}
	printf("%d\n", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

2.中序遍历
void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->lchild);
	printf("%d", root->data);
	inorder(root->rchild);
}

3.后序遍历
void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root->lchild);
	postorder(roor->rchild);
	printf("%d", root->data);//访问根节点root，将其数据域输出
}

4.层序遍历
void LayerOrder(node* root){
	queue<node*> q;
	q.push(root);
	while(! q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if(now->lchild != NULL)
			q.push(now-lchild);
		if(now->rchild != NULL)
			q.push(now->rchild);
	}
}

5.根据遍历顺序重建这棵二叉树
5.1中序可以与先序，后序，层序中的任何一个构建唯一的二叉树
	其原因是先序，后序，层序都是提供跟结点
	中序你是用来区分左右子树
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node;//新建一个新结点，用来存放当前二叉树的根节点
	root->data = pre[prel];
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == pre[preL]){
			break;
		}
	}
	int numLeft = k - inL;
	
	//左子树的先序区间为[prel+1, preL+numLeft], 中序区间为[inL, k-1]
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	//右子树的先序区间为[preL+numLeft, preR], 中序区间为[k, inR]
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	return root	
}


















































