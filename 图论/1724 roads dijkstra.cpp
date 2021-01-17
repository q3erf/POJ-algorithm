#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
//带权最短路径长度 用dijkstra算法

int a[110][110];
int b[110][110];
int d[110][10010];
int k,n,r;

struct node
{
    int v, w,c;
}tnode;

bool operator <(node a, node b){
    if(a.w = b.w)  return a.v > b.v;
    return a.w > b.w;
}

int dijkstra(int sc, int ta){
    //d[i][j]表示源点到顶点i花费为j时的最短路径
    
    memset(d, 127, sizeof(d));
    int inf = d[0][0];
    d[sc][0] = 0;
    
    priority_queue<node> q;
    tnode.v = sc;
    tnode.w = 0;
    tnode.c = 0;
    q.push(tnode);
    
    while (!q.empty())
    {
        node tmp = q.top();
        
        q.pop();
        if(tmp.v == ta){
            return tmp.w;
        }
        for(int i=1; i<=n; i++){
            if(a[tmp.v][i] != 0){           
                int c = tmp.c+b[tmp.v][i];
                if(c > k) continue;
                if( d[i][c] > tmp.w + a[tmp.v][i]){
                    d[i][c] = tmp.w + a[tmp.v][i];
                    
                    tnode.v = i;
                    tnode.w = d[i][c];
                    tnode.c = c;
                    q.push(tnode);
                }
            }
        }
        
    }
    return -1;
}

int main(){
    int s,d,l,t;
    scanf("%d%d%d",&k, &n, &r);
    memset(a, 127, sizeof(a));
    memset(b, 127, sizeof(b));
    for(int i=1; i<=r; i++){
        scanf("%d%d%d%d", &s, &d, &l, &t);
        a[s][d] = a[d][s] = min(l, a[s][d]);
        b[s][d] = b[d][s] = min(t, b[s][d]);
    }
    
    printf("%d\n", dijkstra(1, n));
}