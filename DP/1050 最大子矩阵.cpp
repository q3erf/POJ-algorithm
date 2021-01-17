#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int tmp[510];
int a[510][510];
int dp[510];
int maxsubsum(){
    dp[0] = 0;
    int res=-0x3f3f3f3f;
    
    for(int i=1; i<=n; i++){
        
        dp[i] = max(dp[i-1]+tmp[i], tmp[i]);
        
        res= max(res, dp[i]);
    }
    
    return res;

}

int main(){
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++){
        memset(tmp, 0, sizeof(tmp));
        for(int j=i;j<=n;j++){
            for(int k=1;k<=n;k++){
                tmp[k]+=a[j][k];
            }
            res = max(res, maxsubsum());
        }
    }
    printf("%d\n", res);
}