#include<cstdio>
#include<algorithm>

using namespace std;
int n,c;
int a[100010];
//第1个棚一定会选
bool judge(int m){
    
        int st=0;
        int cnt = c-1;
        for(int i=1; i<n && cnt!=0;i++){
            if(a[i]-a[st]>=m) {
                cnt--;
                st = i;
            }
        }
        if(cnt==0) return true;
    
    return false;
}

int main(){
    
    scanf("%d %d", &n, &c);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int l=0, r=a[n-1]-a[0];
    while (l<r)
    {   
        int mid =(l+r)/2;
        if(r-l==1) break;
        //判断distance 为mid时是否满足条件
        if(judge(mid)) l=mid;
        else r=mid-1;
    }
    if(judge(r)) printf("%d\n", r);
    else printf("%d\n", l);
}