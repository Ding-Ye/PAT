1.定义
	1.1堆是一棵完全二叉树
	1.3父亲结点的值大于或等于孩子结点的值（大顶堆）
	1.2优先队列实现
	
	const int maxn = 100;
	int heap[maxn], n = 10;
	
	1.4向下调整
	void downAdjust(int low, int high){
		int i = low, j = i * 2;
		while(j <= high){ //存在孩子结点
			if(j + 1 <= high && heap[j + 1] > heap[j]){//如果右孩子存在，且右孩子的值大于左孩子
				j = j + 1;
			}
			
			if(heap[j] > heap[i]){
				swap(heap[j], heap[i]);
				i = j;
				j = i * 2;
			}
			else{
				break;
			}
		}
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	