1.亮点：把先序遍历转换成后序遍历
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror; 	//是不是镜像
vector<int> pre;  //先序
vector<int> post; //后序
void getpost(int root, int tail){// 用了递归， root-头， tail--尾， 分而治之--很像快速排序的写法
	if(root > tail)//递归边界1
		return;
	
	int  i = root + 1;
	int j = tail;
	if(!isMirror){
		while(i <= tail && pre[root] > pre[i])
			i++;
		while(j > root && pre[root] <= pre[j])
			j--;
	}
	else{ //这里利用了二叉查找树的性质，而且像是利用了双指针
		while(i <= tail && pre[root] <= pre[i]) 
			i++;
		while(j > root && pre[root] > pre[j])
			j--;
	}
	
	if(i - j != 1)
		return;
	
	getpost(root + 1, j);//递归式 -- 左子树   ！！这二个顺序不能换
	getpost(i, tail);//递归式 -- 右子树
	
	post.push_back(pre[root]); //后序  怎么将先序转换成后序
}

int main(){
	int n;
	scanf("%d", &n);
	pre.resize(n);  //resize 函数重新分配大小，改变容器的大小，并创建对象 就是重新定义长度
	for(int i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	
	getpost(0, n-1);
	
	if(post.size() != n){
		isMirror = true;
		post.clear();
		getpost(0, n-1);
	}
	if(post.size() == n){
		printf("YES\n %d", post[0]);
		for(int i = 1; i < n; i++){
			printf(" %d", post[i]);
		}
	else{
			printf("NO");
		}
	}
	return 0;
}

