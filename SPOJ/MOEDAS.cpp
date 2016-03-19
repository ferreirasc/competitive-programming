#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int pval[50002];
int val, nmoedas;
int vmoedas[102];

int main(){
   
   while ((cin >> val) && val){

      cin >> nmoedas;
      memset(pval,0,sizeof(pval));

      for (int i = 0; i < nmoedas; i++){
         cin >> vmoedas[i];
         pval[vmoedas[i]] = 1;
      }

      for (int i = 1; i <= val; i++){
         if (pval[i])
            for (int a = 0; a < nmoedas; a++){
               if (i + vmoedas[a] > val) break;
               if (pval[i + vmoedas[a]] == 0) pval[i + vmoedas[a]] = pval[i] + 1;
               else pval[i + vmoedas[a]] = min(pval[i + vmoedas[a]],pval[i] + 1);
         }
      }

      if (pval[val]) cout << pval[val];
      else cout << "Impossivel";
      cout << "\n";

      //fill(&pval[0],&pval[val+1],0);
    // fill(&vmoedas[0],&vmoedas[nmoedas],0);
   }

   return 0;
}

