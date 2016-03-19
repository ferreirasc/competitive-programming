#include <stdio.h>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


typedef struct{
		int v1;
		int v2;
		int p;
}aresta;

vector<int> sz(10000,0);
vector<int> id(10000,0);

vector<aresta> insereAresta (vector<aresta> v, int vi, int vo, int p){
	aresta a;
	a.v1 = min(vi,vo);
	a.v2 = max(vi,vo);
	a.p = p;
	v.push_back(a);
	return v;
}

bool sortAresta(aresta v1, aresta v2){ return (v1.p < v2.p);}

bool wquFind(int p, int q){
	int i,j;
	for (i = p; i != id[i]; i = id[i]);
	for (j = q; j != id[j]; j = id[j]);
	if (i == j) return 1; //aresta gera laço
	if (sz[i] < sz[j]) { 
	  id[i] = j; sz[j] += sz[i]; 
	}
	else { 
	  id[j] = i; sz[i] += sz[j];
	}
	return 0;
}

int main (){
	int teste = 1;
	int N,M;
	while (scanf("%d %d",&M, &N) != EOF && N != 0){
		for (int i=0; i<=M; i++) id[i] = i;
		vector<aresta> ar;
		for (int i=0; i<N; i++){
			int vi, vo, p;
			scanf ("%d %d %d",&vi, &vo, &p);
			ar = insereAresta(ar,vi,vo,p);
		}
		sort(ar.begin(), ar.end(), sortAresta);
		vector<aresta> arvGM;
		sz.insert(sz.begin(),M+1,1);
		for (int j=0; j<ar.size(); j++){
			if (wquFind(ar[j].v1, ar[j].v2) == 0) arvGM.push_back(ar[j]);
		}
		printf ("Teste %d\n", teste); teste++;
		for (int i =0; i<arvGM.size(); i++) printf ("%d %d\n",arvGM[i].v1,arvGM[i].v2);
		printf ("\n");
	}

	return 0;
}