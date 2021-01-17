#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int ab[1010];
//dp[i][j]表示前i个盒子中gap为j的最小翻转次数
//j要加offset = 5*1000 
int dp[1010][12010];
int main(){
    int n,sum=0,x,y;
    
    scanf("%d", &n);
    memset(dp, 127, sizeof(dp));
    int inf = dp[0][1];
    for(int i=1; i<=n; i++){
        scanf("%d%d",&x, &y);
        ab[i] = x-y;
        dp[i][sum+(ab[i])+5000] = 0;
        dp[i][sum-(ab[i])+5000] = 1;
        sum +=(ab[i]);
    }

    for(int i=2; i<=n; i++){
        for(int j=-5000; j<=5000;j++){
            dp[i][j+5000] = min(dp[i][j+5000], min(dp[i-1][j-(ab[i])+5000], dp[i-1][j+(ab[i])+5000]+1));
        }
    }
    int ans = 0;
    //ans 为最小翻转次数
    for(int i = 0,mid=5000; i<=5000; i++){
        if(dp[n][mid+i]!=inf ){
            ans = dp[n][mid+i];
            break;
        }
        if(dp[n][mid-i]!=inf){
            ans = dp[n][mid-i];
            break;
        }
    }
    printf("%d\n", ans);
}