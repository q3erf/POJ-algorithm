#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
int a[100010];
int f[100010],g[100010];
// f[i]表示前i天（包括第i天）买卖一次股票的最大收益
// g[i]表示从第i天开始（包括第i天）后买卖一次股票的最大收益

int main(){
    int t,n;
    scanf("%d", &t);
    while (t--)
    {   
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        for(int i=1; i<=n;i++) scanf("%d", &a[i]);
        int mina = a[1];
        int maxa = a[n];
        
        for(int i=1; i<=n;i++){
            f[i] = max(f[i-1], a[i]-mina);
            mina = min(mina, a[i]);
        }

        for(int i=n-1; i>=1; i--){
            g[i] = max(g[i+1], maxa - a[i]);
            maxa = max(maxa, a[i]);
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, f[i]+g[i]);
        }
        printf("%d\n", ans);
    }
    
}