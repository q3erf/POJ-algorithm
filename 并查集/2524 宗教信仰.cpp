#include<cstdio>
#include<algorithm>

using namespace std;

int pre[50010];

int find(int x){
    int rx = x;
    while (rx!=pre[rx])
    {
        rx = pre[rx];
    }
    return rx;

}

void Union(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(rx!=ry){
        if(rx<ry) pre[ry] = rx;
        else pre[rx] = ry;
    }
}

int main(){
    int n,m;
    int Case = 0;
    int x,y;
    while (scanf("%d%d", &n, &m) && n!=0)
    {   
        int ans=0;
        for(int i=1; i<=n ;i++){
            pre[i] = i;
        }
        for(int i=0; i<m; i++){
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        for(int i=1; i<=n; i++){
            if(pre[i]==i) ans++;
        }
        printf("Case %d: %d\n", ++Case, ans);
    }
    
}