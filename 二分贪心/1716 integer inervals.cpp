#include<cstdio>
#include<algorithm>

using namespace std;

struct node
{
    int l,r;
    
}a[10010];

bool cmp(node p, node q){
    return p.r<q.r;
}

int main(){
    int n;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &a[i].l, &a[i].r);
        
    }
    sort(a, a+n, cmp);
    int ans=2;
    int x = a[0].r-1;
    int y = a[0].r;
    for(int i=1; i<n; i++){
        if(a[i].l<=x) continue;
        else if(a[i].l>x && a[i].l<=y){
            ans+=1;
            x=y;
            y = a[i].r;
        }
        else if(a[i].l>y){
            ans+=2;
            x = a[i].r-1;
            y = a[i].r;
        }
    }
    printf("%d\n", ans);
}