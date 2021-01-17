#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
//给定一个拓扑排序建立图 用dijkstra+优先队列求多源最短路径
int a[30][30];

struct node
{
    int num, weight;
}tnode;

bool operator < (node a, node b){
    if(a.weight == b.weight) return a.num > b.num;
    return a.weight>b.weight;
} 

int djsta(int s, int t){
    int d[30];
    priority_queue<node> q;
    memset(d, 127, sizeof(d));  
    d[s] = 0;
    tnode.num = s;
    tnode.weight = 0;
    q.push(tnode);
    while (!q.empty())
    {
        for(int v=1; v<=20; v++){
            if(a[q.top().num][v]!=0 && d[v]>d[q.top().num]+a[q.top().num][v]){
                d[v] = d[q.top().num]+a[q.top().num][v];
                tnode.num = v;
                tnode.weight = d[v];
                q.push(tnode);
            }
        }
        q.pop();
    }
    return d[t];
}

int main(){
    int Case = 1;
    int n=0,x,y;
    do
    {   
        memset(a, 0, sizeof(a));
        for(int i=1; i<=19; i++){
            if(!(i==1 && n!=0)){scanf("%d", &n);}
            while (n--)
            {
                scanf("%d", &x);
                a[i][x] = 1;
                a[x][i] = 1;
            }
        }
        
        scanf("%d", &n);
        printf("Test Set #%d\n", Case++);
        for(int i=1; i<=n; i++){
            scanf("%d %d", &x, &y);
            printf("%d to %d: %d\n", x, y, djsta(x, y));
        }
        printf("\n");
    }while (scanf("%d", &n)!=EOF);
    
    
}