#include<cstdio>
#include<algorithm>

using namespace std;

int c[110],w[110];
int dp[1010];
int main(){
    int v,n;
    scanf("%d%d", &v, &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d%d", &c[i], &w[i]);
    }
    for(int i=1; i<=n; i++){
        for(int j=v; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]]+w[i]);
        }
    }
    printf("%d\n", dp[v]);
}