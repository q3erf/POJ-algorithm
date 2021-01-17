#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf -0x3f3f3f3f
using namespace std;
int a[1010];
int main(){
    int n;
    while (scanf("%d", &n) && n!=0)
    {
        
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int ans = inf;
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==j) continue;
                int sum = a[i]-a[j];
                for(int l=0, r=j-1; l<r;){
                    if(sum==a[l]+a[r] ){
                        if(l!=i && r!=i){

                        ans = a[i];
                        break;
                        }
                    }
                    if(sum>a[l]+a[r]) l++;
                    else r--;
                }
                if(ans!=inf) break;
            }
            if(ans!=inf) break;
        }
        if(ans!=inf) printf("%d\n",ans);
        else printf("no solution\n");
    }
}