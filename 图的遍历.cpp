1.DFS的具体实现
	连通向量：无向图中的概念--- 二个点相连 如果图中任意二个点相连就称该图为连通图
	强连通向量：有向图中的概念---二个顶点可以通过一条有向路径到达另一个顶点 如果图中任意二个点都是强连通，则该图就称为强连通图
	
DFS的伪代码
	DFS(u){//访问顶点u；
		vis[u] = true;
			for(从u出发能到达的所有顶点V)
				if vis[v] == false;
					DFS(v);
	}
	
	DFSTrave(G){//遍历图
		for(G的所有顶点u)
			if(vis[u] == false)
				DFS(u);
	}
	
1.邻接矩阵版
	constint MAXV = 1000;
	constint INF = 100000000;
	
	int n, G[MAXV][MAXV];//二维数组形成的矩阵
	bool vis[MAXV] = {false};
	
	void DFS(int u, int depth){//u为当前访问的顶点标号， depth为深度
		vis[u] = true;
		
		//下面对所有从u出发能到达的分支顶点进行枚举
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				DFS(v, depth + 1);
			}
		}
	}
	
	void DFSTrave(){
		for(int u = 0; u < n; u++){
			if(vis[u] == false){
				DFS(U, 1);
			}
		}
	}
	
2.邻接表版
	vector<int> Adj[MAXV];
	int n;
	bool vis[MAXV] = {false};
	
	void DFS(int u,  int depth){
		vis[u] = true;
		
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][j];
			if(vis[v] == false){
				DFS(v, depth + 1);
			}
		}
	}
	
	void DFSTrave(){
		for(int u = 0; u < n; u++){
			if(vis[u] == false){
				DFS(u, 1);
			}
		}
	}
	
	