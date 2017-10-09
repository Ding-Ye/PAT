1.Dijkstra算法
	解决单源最短路问题，给定图G(V,E)和起点s，求从起点s到达其它顶点的最短距离
	
Dijkstra(G, d[], s){//G为图， 数组d为原点到达各点的最短路径长度， s为起点
	初始化；
	for(循环n次){
		u = 使d[u]最小的还未被访问的顶点的标号
		记u已被访问；
		for(从u出发能到达的所有顶点v){
			if(v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优){
				优化d[v];
			}
		}
	}
}

1.邻接矩阵版
constint MAXV = 1000;
constint INF = 100000000;
int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false}; //标记数组

void Dijkstra(int s){ //s为起点
	fill(d, d + MAXV, INF); //fill函数将整个d数组赋为INF
	d[s] = 0; //起点s到达自身的距离为0；
	for(int i = 0; i < n; i++){ 
		int u = -1, MIN = INF;  //u使d[u]最小，MIN存放该最小的d[u]
		for(int j = 0; j < n; j++){ //找到未访问的顶点中d[]最小的
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u],说明剩下的顶点和起点 s不连通
		if(u == -1)
			return;
		
		vis[u] = true;
		for(int v = 0; v < n; v++){ //如果v未访问 &&ｕ能到达ｖ && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

2.邻接表版
struct Node{
	int v;
	int dis;
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1)
			return;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].v;
			if(vis[v] == false && d[u] +  Adj[u][j].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
}





































