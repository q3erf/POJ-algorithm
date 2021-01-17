#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int a[1010], b[1010];

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n;
    while (scanf("%d", &n) &&n!=0)
    {   
        
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d", &b[i]);
        }
        sort(a, a+n, cmp);
        sort(b, b+n, cmp);
        int ans=0, num=0;
        int ia=0,ib=0,ja=n-1,jb=n-1;
        while (num<n)
        {
            if(a[ia]>b[ib]){
                //如果a的最快马能赢b
                ans+=200;
                ia++;
                ib++;
            }
            else if(a[ja]>b[jb]){
                //如果a的最慢马能赢b的最慢马
                ans+=200;
                ja--;
                jb--;
            }else{
                //都不能赢 那么就用最慢的消耗最快的
                if(a[ja]!=b[ib]) ans-=200;
                ja--;
                ib++;
            }
            num++;
        }
        printf("%d\n",ans);
    }
    
}