#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node{
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

node* creat(int postL, int postR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node;
	
}



















































