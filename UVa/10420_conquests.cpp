#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

map<string, int> l;
map<string, int>::iterator it;
vector<pair<string,int> >::iterator it2;
char entrada[300];

template <typename T1, typename T2>
struct less_first {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.first < b.first;
    }
};

int main(void)
{
	int N;
	string linha, pais;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("\n%[^\n]s", entrada);
		for(int j=0;j<strlen(entrada);j++)
		{
			if(entrada[j]!=' ')
			{
				pais = pais + entrada[j];
			}
			else break;
		}

		pais = pais + '\0';

		it = l.find(pais);
		if(it == l.end())
		{
			l[pais] = 1;
		}
		else
		{
			l[pais]++;
		}

		pais.clear();
		memset(entrada,'\0',sizeof(entrada));
	}

	vector<pair<string, int> > mapcopy(l.begin(), l.end());
	sort(mapcopy.begin(), mapcopy.end(), less_first<string, int>());
	for(it2=mapcopy.begin();it2!=mapcopy.end();++it2)
	{
		printf("%s %d\n", it2->first.c_str(), it2->second);
	}
	return 0;
}
