#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct node
{
    int u,v,w;
};

int pre[1010];

bool operator < (node x, node y){
    return x.w < y.w;
}

int find(int x){
    int rx = x;
    while (rx!=pre[rx])
    {
        rx = pre[rx];
    }
    return rx;
    
}

int main(){
    int n,m;
    priority_queue<node> q;
    scanf("%d%d", &n, &m);
    node tmp;
    for(int i=0 ;i<m; i++){
        
        scanf("%d%d%d", &tmp.u,&tmp.v, &tmp.w);
        q.push(tmp);
    }
    for(int i=0 ;i<=n; i++){
        pre[i] = i;
    }
    node tn;
    int ans = 0;
    while (!q.empty())
    {
        tn = q.top();
        q.pop();
        int rx = find(tn.u);
        int ry = find(tn.v);
        if(rx!=ry){
            ans+=tn.w;
            if(rx<ry) pre[ry] = rx;
            else pre[rx] = ry;
        }
        
    }
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(i==pre[i]) sum++;
    }
    if(sum==2) printf("-1\n");
    else printf("%d\n", ans);
}