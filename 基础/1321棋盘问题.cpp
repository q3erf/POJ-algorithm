#include<cstdio>
#include<cstring>
using namespace std;
char a[10][10];
//递归

bool visc[10];
int n;
int dothing(int r, int k){
    if(k==0) return 1;
    if(r>n) return 0;
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        
        if(a[r][i]=='#' && !visc[i]) {
                
                visc[i] = 1;
                ans += dothing(r+1, k-1);
                visc[i] = 0;
        }
        
    }
    ans += dothing(r+1, k);
    return ans;
}

int main(){
    int k;
    
    while(scanf("%d%d", &n, &k) && n!=-1){
        
        memset(visc, 0, sizeof(visc));
        
        for(int i=1; i<=n; i++){
            getchar();
            for(int j=1; j<=n;j++){
                scanf("%c", &a[i][j]);
            }
        }
        printf("%d\n", dothing(1,k));
    }
}