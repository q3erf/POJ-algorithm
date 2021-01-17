#include<cstdio>

using namespace std;
const int maxn = 50010;

int parent[maxn], r[maxn];
// r表示当前结点与父节点的关系，0表示同类，1表示被父亲吃，2表示吃父亲
int find(int x){
    if (x==parent[x]) return x;
    int t=parent[x];
    parent[x] = find(parent[x]);
    r[x] = (r[x]+r[t])%3;
    return parent[x];
    
}

void Union(int x, int y, int d){
    int rx = find(x);
    int ry = find(y);
    
    parent[ry] = rx;
    r[ry] = (r[x]-r[y]+3+(d-1))%3;
    
    
}

int main(){
    //带偏移量的并查集，偏移量指的是与父节点的关系
    int n,k,result=0;
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        r[i] = 0;
    }
    int d, x, y;
    while (k--)
    {
        
        scanf("%d %d %d", &d, &x, &y);
        if(x>n || y>n|| (x==y && d==2)) {
            result++;
            
        }
        else if(find(x)==find(y)){
            if(d==1){
                if(r[x]!=r[y]) result++;
            }
            if(d==2){
                if ((r[x]+1)%3!=r[y]) result++;
            }
        }
        else{
            Union(x, y, d);
        }
        
    }
    printf("%d\n", result);
}