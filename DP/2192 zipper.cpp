#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//暴力枚举会TLE
int main(){
    int n;
    char a[210], b[210], c[410];
    int dp[210][210];
    //dp[i][j]表示a中前i个字符和b中前j个字符能否满足c中前i+j个字符
    scanf("%d", &n);
    for(int t=1; t<=n; t++){
        a[0] = 's';
        b[0] = 's';
        c[0] = 's';
        scanf("%s %s %s", a+1, b+1, c+1);
        int lena = strlen(a)-1;
        int lenb = strlen(b)-1;
        // printf("lena is %d, lenb is %d\n", lena, lenb);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for(int i=1; i<=lena; i++){
            if(a[i]==c[i]) dp[i][0] = 1;
        }
        for(int j=1; j<=lenb; j++){
            if(b[j]==c[j]) dp[0][j] = 1;
        }
        for(int i=1; i<=lena; i++){
            for(int j=1; j<=lenb; j++){
                if(dp[i-1][j]==1 && a[i]==c[i+j])
                    dp[i][j]=1;
                if(dp[i][j-1]==1 && b[j]==c[i+j])
                    dp[i][j]=1;
                
            }
            
        } 
        
        if(dp[lena][lenb] == 1) printf("Data set %d: yes\n", t);
        else printf("Data set %d: no\n", t);

        }
}