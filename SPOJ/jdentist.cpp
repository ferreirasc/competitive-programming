#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;

    scanf("%d",&N);
    vector<pair<int,int> > v;
    for(int i = 0; i < N; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(b,a));
    } 

    sort(v.begin(),v.end());


    int r = 1;
    int j = 0;
    for(int i = 1; i < N; i++)
        if (v[i].second >= v[j].first)
        {
            r++;
            j = i;
        }
    printf("%d\n",r);

    return(0);
}

