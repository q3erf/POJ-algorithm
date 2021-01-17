#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

struct node
{
    int x,y;
}a[50010];

bool cmpx(node p, node q){
    if(p.x==q.x) return p.y<q.y;
    else return p.x < q.x;
}



int main(){
    int n;
    int x,y,maxx=-inf, maxy=-inf;
    while (scanf("%d", &n) && n!=0)
    {   
        for(int i=1; i<=n; i++){
            scanf("%d %d",&x, &y);
            a[i].x = x;
            a[i].y = y;
            
        }
        sort(a+1, a+n+1,cmpx);
        int flag,ans=0;
        for(int i=1; i<n; i++){
            flag = 0;
            for(int j=i+1; j<=n; j++){
                if(a[j].y>=a[i].y) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans+=1;
        }
        printf("%d\n",ans+1);
    }
    
}