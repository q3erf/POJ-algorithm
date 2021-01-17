#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int a[310];
int dp[310][40];
//sum[i][j]表示从i到j只建造1个邮局的minsum
int sum[310][310];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; i++){
        sum[i][i] = 0;
        for(int j=i+1; j<=n;j++){
            sum[i][j] = sum[i][j-1]+a[j]-a[(i+j)/2];
        }
        dp[i][1] = sum[1][i];
    }
   
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j] = inf;
            for(int k=i-1;k>0;k--){
                dp[i][j] = min(dp[k][j-1]+sum[k+1][i], dp[i][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}