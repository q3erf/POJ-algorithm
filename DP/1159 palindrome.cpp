#include<cstdio>
#include<algorithm>
using namespace std;
//dp[i][j]表示字符串a[i..j]变成回文串的最小改变个数
short int dp[5010][5010];
int main(){
    int n;
    char a[5010];
    
    scanf("%d",&n);
    getchar();
    scanf("%s", a);
    
    for(int k=1;k<n; k++){
        for(int i=0;i<n-k; i++){
            dp[i][i+k] = (a[i]==a[i+k] ? dp[i+1][i+k-1] : min(dp[i+1][i+k], dp[i][i+k-1])+1);
        }
    }
    printf("%d\n", dp[0][n-1]);
}