struct Node{
	int v;
	int layer;
};

vector<Node> Adj[N];
void BFS(int s){
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		int u = topNode.V;
		for(int i = 0; i < Adj[u].size(); i++){
			Node next = Adj[u][j];
			next.layer = topNode.layer + 1;
			
			if(inq[next.v] == false){
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}