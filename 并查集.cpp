1.定义
	1.1并查集是一种维护集合的数据结构。
	1.2合并二个集合，查找二个元素是否在一个集合
	1.3以父系关系来表示元素所属的集合
	1.4用数组实现

2.基本操作
	2.1初始化
	for(int i = 1; i <= N; i++){
		father[i] = i;
	}
	2.2查找//找到跟结点
		2.2.1递推
		int findFather(int x){
			while(x != father[x]){
				x = father[x];	//得到自己的父亲结点
			}
			return x;
		}
	    2.2.2递归
		int findFather(int x){
			if(x == father[x])
				return x;
			
			else
				return findFather(father[x]);
		}

3.合并
	void Union(int a, int b){
		int faA = findFather(a);
		int faB = findFather(b);
		if(faA != faB){
			father[faA] = faB;
		}
	}
	
4.路径压缩//不就是组织架构扁平化
	4.1把当前查询结点的路径上所有结点的父亲都指向跟结点
	int findFather(int x){
		int a = x;
		while(x != father[x]){//寻找根结点
			x = father[x];
		}
		
		while(a != father[a]){
			int z = a;  //先保存a的值
			a = father[a];//回溯父亲结点
			father[z] = x;//将原先的结点a的父亲改为根结点
		}
		return x;
	}
	4.2递归写法
	int findFather(int v){
		if(v == father[v])//递归边界
			return v;
		
		else{
			int F = findFather(father[v]); //递归寻找father[v]的根节点F
			father[v] = F;
			return F;
		}
	}
	
	
