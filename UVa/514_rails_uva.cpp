#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

stack<int> A, station;
vector<int> carros;
int N;

bool process()
{
	for(int i=0;i<N;i++)
	{
		if(!station.empty() && station.top() == carros[i])
		{
			station.pop();
		}
		else
		{
			while(!A.empty())
			{
				if(A.top() == carros[i])
				{
					A.pop();
					break;
				}
				else
				{
					int aux = A.top();
					station.push(aux);
					A.pop();
				}
			}
		}
	}
	if(A.empty() && station.empty())return true;
	else return false;
}

int main(void)
{
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)return 0;
		while(1)
		{
			int aux;
			scanf("%d", &aux);
			if(aux == 0)break;
			carros.push_back(aux);
			for(int i=0;i<(N-1);i++)
			{
				scanf("%d", &aux);
				carros.push_back(aux);
			}

			for(int i=N-1;i>=0;i--)A.push(i+1);
			
			if(process()==true)printf("Yes\n");
			else printf("No\n");
			carros.clear();
			while(!A.empty())A.pop();
			while(!station.empty())station.pop();
		}
		carros.clear();
		while(!A.empty())A.pop();
		while(!station.empty())station.pop();
		printf("\n");
	}
	return 0;
}
