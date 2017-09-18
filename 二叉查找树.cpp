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
	void insert(node* &root, int x){
		if(root == NULL){
			root = newNod.e(x);
			return;
		}
		if(x == root->data){
			return;
		}
		else if(x < root->data){
			insert(root->lchild, x);
		}
		else{
			insert(root->rchild, x);
		}
	}
	
	2.3建立
	node* Create(int data[], int n){
		node* root = NULL;
		for(int i = 0; i < n; i++){
			insert(root, data[i]);
		}
		
		return root;
	}
	
	2.4删除
		2.4.1后继
		node* findMax(node* root){
			while(root->rchild != NULL){
				root = root -> rchild;
			}
			return root;
		}
		
		2.4.2前驱
		node* findMix(node* root){
			while(root->lchild != NULL){
				root = root -> lchild;
			}
			return root;
		}
		
		2.4.3删除
		void deleteNode(node* &root, int x){
			if(root == NULL)
				return;
			if(root->data == x){
				if(root->lchild == NULL && root->rchild == NULL){
					root = NULL;
				}
				else if(root->lchild != NULL){
					node* pre = findMax(root->lchild);
					root->data = pre->data;
					deleteNode(root->lchild, pre->data);//????
				}
				else{
					node* next = findMin(root->rchild);
					root->data = next->data;
					deleteNode(root->rchild, next->data);//????
				}
			}
			else if(root->data > x){
				deleteNode(root->lchild, x);
			}
			else{
				deleteNode(root->rchild, x);
			}
		}
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	