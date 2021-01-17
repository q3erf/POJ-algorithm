#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct node
{
    int x,y,state;
}a[1010];
int pre[1010];

vector<int> vi[1010];
int find(int x){
    int root,now=x, tmp;
    while (now!=pre[now])
    {
        now = pre[now];
    }
    root = now;
    now = x;
    while (now!=pre[now])
    {
        tmp = pre[now];
        pre[now] = root;
        now = tmp;
    }
    return root;
}

void Union(int x, int y){
    
    int rx = find(x);
    int ry = find(y);
    if(rx!=ry){
        pre[rx] = ry;
    }
}

double distan(node p, node q){
    return sqrt((double)(p.x-q.x)*(p.x-q.x) +(p.y-q.y)*(p.y-q.y));
}

int main(){
    int n,d;
    scanf("%d%d", &n, &d);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].state = 0;
        pre[i] = i;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(distan(a[i], a[j]) <= (double)d ){
                vi[i].push_back(j);
                vi[j].push_back(i);
            }
            
        }
    }
    char c;
    int x,y;
    
    while (scanf("%c", &c)!=EOF)
    {
        if(c == 'O'){
            scanf("%d", &x);
            a[x].state = 1;
            for(int i=0; i<vi[x].size(); i++){
                if(a[vi[x][i]].state){
                    Union(x,vi[x][i]);
                }
            }
        }
        else if(c=='S'){
            scanf("%d%d", &x, &y);
            
            int rx = find(x);
            int ry = find(y);
            
            if(rx!=ry) printf("FAIL\n");
            else printf("SUCCESS\n");
        }
        
    }
    
}