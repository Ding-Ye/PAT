#include <cstdio>
const int maxn = 30;
int n , V, maxValue = 0;
int w[maxn], c[maxn];

//��ͺ���һ��������
void DFS(int index, int sumW, int sumC){
	if(index == n){ //�Ѿ���ɶ�n����Ʒ��ѡ�񣨵ݹ�߽磩
			if(sumW <= V && sumC > maxValue){
				maxValue = sumC;
			}
			return ;
	}
	
	//�����
	DFS(index + 1, sumW, sumC); //��ѡ��index ����Ʒ
	DFS(index + 1, sumW + w[index], sumC + c[index]);//ѡ��index ����Ʒ
}

int main()
{
	scanf("%d %d", &n, &V);
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	
	DFS(0, 0, 0);//��ʼʱΪ��0����Ʒ����ǰ���������ܼ�ֵ��Ϊ0
	printf("%d\n", maxValue);
	return 0;
}