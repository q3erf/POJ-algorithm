#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 2010;

int pre[maxn], r[maxn];
//r值为0表示 与父节点性别相同， 1则表示与父节点性别相反

int find(int x){
    int root,now=x;
    if(x==pre[x]) return x;
    int fx = pre[x];
    pre[x] = find(fx);
    r[x] = (r[fx]+r[x])%2;

    return pre[x];
    
}

void Union(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(rx!=ry){
        pre[rx] = ry;
        r[rx] = (r[x]+1+r[y]) %2;
    }
}

int main(){
    //可以用带权并查集来解
    int t,m,n;
    int x,y;
    
    scanf("%d", &t);
    int Case = 0;
    while (Case<t)
    {   
        int flag = false;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <=n; i++)
        {
            pre[i] = i;
            r[i] = 0;
        }
        printf("Scenario #%d:\n", ++Case);
        while (m--)
        {
            scanf("%d %d", &x, &y);
            
            if(flag) continue;
            int rx = find(x);
            int ry = find(y);
            if(rx!=ry){
                Union(x, y);
            }
            else {
                if(r[x]==r[y]){
                printf("Suspicious bugs found!\n");
                flag = true;
                }
            }
        }
        
        if(!flag) printf("No suspicious bugs found!\n");
        if(Case!=t) printf("\n"); 
    }
    
}