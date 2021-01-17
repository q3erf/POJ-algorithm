#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 1010
using namespace std;

int tmp[1010];
int t,n,m;
int a[1010][1010];
int dp[1010];

int main(){
    scanf("%d", &t);
    char c[10];
    while (t--)
    {
        scanf("%d%d", &m, &n);
        
        for(int i=1; i<=m; i++){
            
            for(int j=1; j<=n; j++){
                scanf("%s", c);
                if(c[0]=='R') a[i][j] = -inf;
                else if(c[0]=='F')a[i][j] = 1;
                
            }
        }
        int res=0;
        for(int i=1; i<=m;i++){
            memset(tmp, 0, sizeof(tmp));
            memset(dp, 0, sizeof(dp));
            for(int j=i;j<=m ;j++){
                for(int k=1;k<=n;k++){
                    tmp[k]+=a[j][k];
                    dp[k] = max(dp[k-1]+tmp[k], tmp[k]);
                    res = max(dp[k], res);
                }
                
            }
        }
        printf("%d\n", res*3);
    }
    
}