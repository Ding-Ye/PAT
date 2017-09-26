1.解决姓名与编号对应：1.1map 1.2hash
2.求与某个点相连的边的边权之和
3.进行图遍历

#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;

map<int, string> intToString; //编号->姓名
map<string, int> stringToInt;//姓名->编号
map<string, int> Gang; //head ->人数；

int G[maxn][maxn] = {0}, weight[maxn] = {0}; //邻接矩阵G， 点权
int n, k, numPerson = 0;								//边数n, 下限k， 总人数numPerson
bool vis[maxn] = {false};	//标记是否被访问


void DFS(int nowVisit, int& head, int& numMember, int& totalValue){ //numMember为成员编号
	numMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){//当前访问结点的点权大于头目的点权，则更新头目
		head = nowVisit;
	} 
	
	for(int i = 0; i < numPerson; i++){ //枚举所有人
		if(G[nowVisit][i] > 0){ //如果从nowVisit能到达i
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;  //删除这条边，防止回头
			if(vis[i] == false){
				DFS(i, head, numMember, totalValue);//递归---本质用了系统栈
			}
		}
	}
}

//遍历整个图，获取每个连通块的消息
void DFSTrave(){
	for(int i = 0; i < numPerson; i++){
		if(vis[i] == false){
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);  //遍历i所在的连通块
			if(numMember > 2 && totalValue > k){
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

//函数返回姓名str对应的编号
int change(string str){//change函数返回系姓名str对应的编号
	if(stringToInt.find(str) != stringToInt.end()){ //如果str已经出现过
		return stringToInt[str]; //返回编号
	}
	else{
		stringToInt[str] = numPerson;  //str的编号为numPerson
		intToString[numPerson] = str; //numPerson对应str
		
		return numPerson++;
	}
}

int main(){
	int w;
	string str1, str2;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin>> str1 >> str2 >>w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	
	DFSTrave(); //遍历整个图，获取Gang的消息

	cout<< Gang.size() <<endl;
	map<string, int> :: iterator it;
	for(int = Gang.begin(); it != Gang.end(); it++){
		cout<< it->first<<" "<< it->second<<endl;
	}
	
	return 0;
}


