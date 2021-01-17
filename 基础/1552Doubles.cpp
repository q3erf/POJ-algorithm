#include<cstdio>
#include<algorithm>
using namespace std;
int a[20];
bool cmp(int x, int y){
    return x<y;
}

int get_ans(int n){
    sort(a, a+n, cmp);
    int ans = 0;
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(a[j]==a[i]*2) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main(){
    
    int x;
    int n=0;
    while(scanf("%d",&x) && x!=-1){
        if(x==0){
            printf("%d\n", get_ans(n));
            n=0;
        }
        else{
            a[n++] = x;
        }
    }
}