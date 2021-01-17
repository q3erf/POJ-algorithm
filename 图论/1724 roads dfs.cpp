#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;

int k,n,r,ans;
bool vis[110];
int head[110];
//对于两个权值的重边 不能用邻接矩阵 而应该用邻接表
struct node
{
    int v,w,c,next;
}e[10010];

void dfs(int st, int cost, int len){
    if(cost > k || len>ans) return ;
    if(st == n){
        ans = min(len, ans);
        return;
    }
    for(int i=head[st]; i!=-1; i=e[i].next){
        node tmp = e[i];
        if(!vis[tmp.v]){
            vis[tmp.v] = 1;
            dfs(tmp.v, cost + tmp.c, len + tmp.w);
            vis[tmp.v] = 0;
        }
    }
}

int main(){
    int s,d,l,t;
    scanf("%d%d%d",&k, &n, &r);
    ans = inf;
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    for(int i=1; i<=r; i++){
        scanf("%d%d%d%d", &s, &d, &l, &t);
        if(s!=d){           
            e[i].v = d;
            e[i].w = l;
            e[i].c = t;
            e[i].next = head[s];
            head[s] = i;
        }
        
    }
    vis[1] = 1;
    dfs(1, 0, 0);
    if(ans==inf) printf("-1\n");
    else printf("%d\n", ans);
    
}