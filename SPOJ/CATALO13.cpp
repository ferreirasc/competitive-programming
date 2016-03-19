#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define MAXN (112345)
#define MAXS (1123456)

int N;
char filePath[MAXS];
int arquivosSubpastas[MAXN];
vector<int> adj[MAXN];
int tamanhoPastas[MAXN];
//no caso da busca já ter passado por este índice e não precisar passar de novo
bool alreadySearched[MAXN];
int tamanhoInicial;
int melhorSolucao;


map<string, int> dicionario;


int findTranslation(string str) {
	if (dicionario.count(str) == 0) {
		tamanhoPastas[dicionario.size()] = str.size() + 1;
		int position = dicionario.size();
		dicionario[str] = position;
	}
	return dicionario[str];
}

vector<int> separateString(string path) {
	int stringBegin = 0;
	int idxPrevious = -1;
	vector<int> ret(1);
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == '/') {
			string mounted = path.substr(stringBegin, i - stringBegin);
			int idxMapa = findTranslation(mounted);
			ret.push_back(idxMapa);
			stringBegin = i + 1;
		}
	}
	return ret;
}

void acharArquivosRecursivamente(int idx) {
	for (int i = 0; i < adj[idx].size(); i++) {
		int u = adj[idx][i];
		if (alreadySearched[u]) {
			continue;
		}
		acharArquivosRecursivamente(u);
		alreadySearched[u] = 1;
		arquivosSubpastas[idx] += arquivosSubpastas[u];
	}
}

void buscaMelhorSolucao(int idx, int solucaoIdx) {
	for (int i = 0; i < adj[idx].size(); i++) {
		int u = adj[idx][i];
		if (alreadySearched[u]) {
			continue;
		}
		int novaSolucao = solucaoIdx - tamanhoPastas[u] * arquivosSubpastas[u] +
			3 * (N - arquivosSubpastas[u]);
		if (melhorSolucao > novaSolucao) {
			melhorSolucao = novaSolucao;
		}
		buscaMelhorSolucao(u, novaSolucao);
		alreadySearched[u] = 1;
	}
}

int main() {
	dicionario[""] = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", filePath);
		tamanhoInicial += strlen(filePath);
		vector<int> caminho = separateString(string(filePath));
		arquivosSubpastas[caminho[caminho.size() - 1]]++;
		for (int j = 0; j + 1 < caminho.size(); j++) {
			int u = caminho[j];
			int v = caminho[j + 1];
			adj[u].push_back(v);
		}
	}
	acharArquivosRecursivamente(0);
	melhorSolucao = tamanhoInicial;
	memset(alreadySearched, 0, sizeof alreadySearched);
	buscaMelhorSolucao(0, tamanhoInicial);
	printf("%d\n", melhorSolucao);
	return 0;
}