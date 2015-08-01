#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

map<string,int> ing;
map<string,int> bolos;
vector<pair<string,int> >::iterator it;

template <typename t1, typename t2>
struct less_second
{
	typedef pair<t1,t2> type;
	bool operator ()(type const& a, type const& b) const
	{
		return a.second < b.second;
	}
};

int main(void)
{
	int t;
	string binder;
	scanf("%d", &t);
		
	while(t--)
	{
		getchar();
		getline(cin, binder);
		for(int i=0,p=binder.size();i<p;i++)
		{
			binder[i] = toupper(binder[i]);
		}
		cout << binder << endl;
		int m,n,b;
		scanf("%d %d %d", &m, &n, &b);
		
		for(int i=0;i<m;i++)
		{
			string ingrediente;
			int price;
			cin >> ingrediente >> price;
			ing[ingrediente] = price;
		}
		
		for(int i=0;i<n;i++)
		{
			string bolo;
			getchar();
			getline(cin, bolo);
			int k;
			scanf("%d", &k);
			double preco = 0;
			for(int j=0;j<k;j++)
			{
				string ing2;
				int valor;
				cin >> ing2 >> valor;
				if(ing.find(ing2) != ing.end())
				{
					preco+=(ing[ing2]*valor);
				}
			}
			if(preco<=b)
			{
				bolos[bolo] = preco;
			}
		}
		
		if(bolos.empty())
		{
			cout << "Too expensive!" << endl << endl;
		}
		else
		{
			vector<pair<string,int> > mapcopy(bolos.begin(),bolos.end());
			sort(mapcopy.begin(),mapcopy.end(),less_second<string, int>());
			for(it=mapcopy.begin();it!=mapcopy.end();it++)
			{
				cout << it->first << endl;
			}
			cout << endl;
		}
		bolos.clear();
		ing.clear();
	}
	
	return 0;
}
