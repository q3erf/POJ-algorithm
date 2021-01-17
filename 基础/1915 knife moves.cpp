#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int a[310][310];
bool vis[310][310];
int d[8][2] = {{2,1},{2,-1},{-2, 1},{-2,-1},{1,-2},{1,2},{-1,2},{-1,-2}};
int t,n,ex,ey,ans;

struct node
{
    int x,y,level;
};

queue<node>  q;
int bfs(){
    while (!q.empty())
    {
        node pre = q.front();
        q.pop();
        if(pre.x==ex && pre.y==ey){
            return pre.level;
        }
        int nx,ny;
        for(int i=0; i<8; i++){
            nx = pre.x+d[i][0];
            ny = pre.y+d[i][1];
            if(nx>=0 &&nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                vis[nx][ny] = true;
                node t;
                t.x = nx;
                t.y = ny;
                t.level = pre.level+1;
                q.push(t);
            }
        }

    }
    return 0;
    
    
}

int main(){
    scanf("%d", &t);
    while (t--)
    {   
        int sx,sy;
        
        scanf("%d", &n);
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        
        vis[sx][sy] = true;
        node tmp;
        tmp.x = sx;
        tmp.y = sy;
        tmp.level = 0;
        q.push(tmp);
        ans = bfs();
        printf("%d\n", ans);
    }
    
}