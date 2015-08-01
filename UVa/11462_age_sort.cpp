#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> elements;

int main(void)
{
	int n;
	while(1)
	{
		elements.clear();
		scanf("%d", &n);
		if(n==0)return 0;
		for(int i=0;i<n;i++)
		{
			int aux;
			scanf("%d", &aux);
			elements.push_back(aux);
		}

		sort(elements.begin(), elements.end());
	
		for(int i=0;i<n;i++)
		{
			printf("%d", elements[i]);
			if(i<(n-1))printf(" ");
		}
		printf("\n");
	}
	return 0;
}
