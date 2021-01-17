#include<cstdio>
#include<algorithm>

using namespace std;

int a[1010];
int dp[1010];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 1;
        for(int j=i-1;j>=1; j--){
            if(a[j]<a[i]) dp[i] = max(dp[i],1+dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}