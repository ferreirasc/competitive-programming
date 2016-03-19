#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

vector<int> graph[123456];
int dependencias[123456];
vector<int> answer;

int main(void)
{
	int n,m,a,b;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		dependencias[b]++;
	}
	
	set<int> q;	

	for(int i=0;i<n;i++)
		if(!dependencias[i])q.insert(i);
	
	while(!q.empty())
	{
		int p = *(q.begin());
		q.erase(q.begin());		
		int tam = graph[p].size();
		for(int i=0;i<tam;i++)
		{
			int prox = graph[p][i];
			if(--dependencias[prox] == 0)
				q.insert(prox);
		}
		answer.push_back(p);
	}

	if(answer.size() == n)
	{
		for(int i=0;i<n;i++)
			printf("%d\n", answer[i]);
	}
	else printf("*\n");

	return 0;
}