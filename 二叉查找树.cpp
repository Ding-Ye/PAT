1.二叉查树的定义
	1.1一棵空树
	1.2左子树小于或等于根节点，右子树大于根节点
	
2.二叉树的基本操作
	2.1查找
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
	
	2.2插入