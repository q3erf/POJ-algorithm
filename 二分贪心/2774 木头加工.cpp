#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
int n,k;
int a[100010];
bool cmp(int x, int y){
    return x>y;
}

bool judge(int m){
    int cnt=0;
    for(int i=0; i<n; i++){
        cnt+=(a[i]/m );
        if(cnt>=k) return true;
    }
    
    return false;
}

int main(){
    
    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        
    }
    
    sort(a, a+n, cmp);
    int l=1, r=10000;
    while (l<=r)
    {   
        int sum=0;
        int mid = (l+r)/2;
        for(int i=0; i<n; i++){
            sum+=(a[i]/mid);
        }
        if(sum>=k) l=mid+1;
        else r= mid-1;
    }
    
    printf("%d", r);
    // else printf("%d\n", r-1);
    
}