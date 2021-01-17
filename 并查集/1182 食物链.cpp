#include<cstdio>
#include<algorithm>

using namespace std;

int n,k;
int pre[50010], r[50010];
//r[i]表示i与父节点的关系， 0表示是同类 1表示被父亲吃 2表示吃父亲
int find(int x){
    if(x==pre[x]) return x;
    int fx = pre[x];
    pre[x] = find(fx);
    r[x] = (r[x]+r[fx])%3;
    return pre[x];
}

int Union(int x, int y, int d){
    int rx = find(x);
    int ry = find(y);
    
    pre[ry] = rx;
    r[ry] = (r[x]-r[y]+3+(d-1))%3;
    
}

int main(){
    scanf("%d%d", &n, &k);
    int d,x,y;
    int ans = 0;
    for(int i=1; i<=n; i++){
        pre[i] = i;
        r[i] = 0;
    }

    while (k--)
    {
        scanf("%d%d%d", &d, &x,&y);
        if(x>n || y>n || x==y && d==2){
            ans+=1;
            continue;
        }
        int rx = find(x);
        int ry = find(y);
        if(rx==ry){
            if(d==1){
                if(r[x]!=r[y]) ans++;
            }

            else if(d==2){
                if((r[x]+1)%3!=r[y]) ans++;
            }
        }
        else{
            Union(x, y, d);
        }

   }
    printf("%d\n", ans);
    
}