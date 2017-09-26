1.邻接矩阵版
int n, G[MAXV][MAXV];
bool inq[MAXV] = {false};

void BFS(int u){  //遍历u所在的连通块
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; v++){
			if(inq[v] == false && G[u][v] != INF){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BFSTrave(){ //对整个图进行遍历
	for(int u = 0; u < n; u++){
		if(inq[u] == false){
			BFS(q);
		}
	}
}

2.邻接表版
vector<int> Adj[MAXV];
int n;
bool inq[MAXV] = {false};

void BFS(int u){
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i];
			if(inq[v] == false){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BFSTrave(){
	for(int u = 0; i < n; i++){
		if(inq[u] == false){
			BFS(q);
		}
	}
}























