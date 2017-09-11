void BFS(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		取出队首元素top；
		访问队首元素top；
		将队首元素出队；
		将top的下一层结点中未曾入队的结点全部入队，并设置为已入队
	}
}

void BFS(int x, int y){
	queue<node> Q;
	Node.x = x, Node.y = y;
	Q.push(Node);
	inq[x][y] = true;
	while(!Q.empty()){
		node top = Q.front();//取出队首元素top；
		Q.pop();//队首元素出队
		for(int i = 0; i < 4; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if(judge(newX, newY)){
				Node.x = newX;
				Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		}
	}
}