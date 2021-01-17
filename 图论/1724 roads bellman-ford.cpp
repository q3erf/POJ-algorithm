#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
//带权最短路径长度 用bellman-ford

int a[110][110];
int b[110][110];
int k,n,r;

struct edge
{
    int u,v,w,c;
}Edge[10010];


int bellman_ford(int s, int t){
    int d[110];
    memset(d, 127, sizeof(d));
    int inf = d[0];
    d[s] = 0;

    int cost[110];
    memset(cost, 127, sizeof(cost));
    cost[s] = 0;

    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=r;j++){
            if(d[Edge[j].v] > d[Edge[j].u] + Edge[j].w && cost[Edge[j].u]+Edge[j].c <= k){
                d[Edge[j].v] = d[Edge[j].u] + Edge[j].w;
                cost[Edge[j].v] = cost[Edge[j].u]+Edge[j].c;
            }
        }
    }
    return d[t]==inf ? -1 : d[t]; 
}

int main(){
    int s,d,l,t;
    scanf("%d%d%d",&k, &n, &r);
    for(int i=1; i<=r; i++){
        scanf("%d%d%d%d", &s, &d, &l, &t);
        
        Edge[i].u = s;
        Edge[i].v = d;
        Edge[i].w = l;
        Edge[i].c = t;
    }
    printf("%d\n", bellman_ford(1, n));
}