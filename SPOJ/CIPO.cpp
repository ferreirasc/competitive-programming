#include <stdio.h>
 
int alt[1001],rep[1001];
int aresta[2000000][3];
int w[]={1235,8977,10923};
 
int representante(int v){
        if(v!=rep[v])
                rep[v]=representante(rep[v]);
        return rep[v];
}
 
void fusao( int v1, int v2) {
        int r1=rep[v1],r2=rep[v2];
        if(alt[r1]>alt[r2])
                rep[r2]=r1;
        else{
                rep[r1]=r2;
                if(alt[r1]==alt[r2])
                        alt[r2]++;
        }
}
 
int main(){
        int t=1;
        int n,m;
        while(scanf("%d %d",&n,&m)==2){
                int l[]={-1,-1,-1},ult=0;
                int i,j;
                int custo=0,arestas=0;
                for(i=1;i<=n;i++){
                        alt[i]=0;
                        rep[i]=i;
                }
                while(m--){
                        int peso;
                        scanf("%d %d %d",aresta[ult],aresta[ult]+1,&peso);
                        switch(peso){
                                case 1235:
                                        i=0;
                                        break;
                                case 8977:
                                        i=1;
                                        break;
                                case 10923:
                                        i=2;
                                        break;
                        }
                        aresta[ult][2]=l[i];
                        l[i]=ult;
                        ult++;
                }
                i=0;j=l[0];
                while(arestas!=n-1 && i!=3){
                        if(j==-1)
                                j=l[++i];
                        else{
                                if(representante(aresta[j][0])!=representante(aresta[j][1])){
                                        fusao(aresta[j][0],aresta[j][1]);
                                        arestas++;
                                        custo+=w[i];
                                }
                                j=aresta[j][2];
                        }
                }
                printf("Instancia %d\n%d\n\n",t++,custo);
        }
        return 0;
}