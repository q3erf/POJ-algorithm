#include<cstdio>

#include<algorithm>

using namespace std;

struct node
{
    int x,y;
}a[1010], tmp;

bool cmpx(node p, node q){
    if(p.x==q.x) return p.y<q.y;
    return p.x<q.x;
}


int main(){
    int n;
    while (scanf("%d", &n) && n!=0)
    {   
        int ans=0;
        for(int i=1; i<=n; i++){
            scanf("%d %d", &a[i].x, &a[i].y);
            
        }
        sort(a+1, a+1+n, cmpx);
        
        for(int i=1; i<=n;i++){
            
            for(int j=i+1; j<=n;j++){
                tmp.x=a[i].x-a[j].y+a[i].y;
                tmp.y=a[i].y+a[j].x-a[i].x;
                if(!binary_search(a+1,a+1+n,tmp,cmpx))continue;
                
                tmp.x=a[j].x-a[j].y+a[i].y;
                tmp.y=a[j].y+a[j].x-a[i].x;
                if(!binary_search(a+1,a+1+n,tmp,cmpx))continue;
                
                ans++;
            }
            
            
        }
        printf("%d\n", ans/2);
    }
    
}