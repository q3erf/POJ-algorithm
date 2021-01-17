#include<cstdio>
#include<algorithm>
using namespace std;

int n;
// dp[i][0] 表示前i个数以0为结尾的排列数
// dp[i][1] 表示前i个数以1为结尾的排列数
int dp[50][2];

int main(){
    int t;
    scanf("%d", &t);
    int Case=0;
    dp[1][0] = dp[1][1]=1;

    for(int i=2; i<=45;i++){
        dp[i][0] = dp[i-1][1]+dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }

    while (Case < t)
    {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n", ++Case, dp[n][0]+dp[n][1]);
        if(t-Case!=0) printf("\n");
    }
    
}