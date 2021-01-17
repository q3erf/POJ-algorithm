#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[30][30];
bool vis[30][30];
int dis[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};
int ans;
int m,n;
//n是行 m是列
void dfs(int x, int y){
    if(vis[x][y]) return;
    else {
        ans+=1;
        vis[x][y] = 1;
    }

    for(int i=0; i<4;i++){
        int nx = x+dis[i][0];
        int ny = y+dis[i][1];
        if(nx>=1&& nx<=n && ny>=1 && ny<=m && !vis[nx][ny] && a[nx][ny]=='.'){
            dfs(nx, ny);
        }
    }
}


int main(){
    
    
    while (scanf("%d%d", &m, &n) && m!=0)
    {   
        memset(vis, 0, sizeof(vis));
        ans = 0;
        int stx,sty;
        for(int i=1; i<=n; i++){
            getchar();
            for(int j=1; j<=m; j++){
                scanf("%c", &a[i][j]);
                if(a[i][j]=='@'){
                    stx = i;
                    sty = j;
                }
            }
        }
        dfs(stx, sty);
        printf("%d\n",ans);


    }
    
}