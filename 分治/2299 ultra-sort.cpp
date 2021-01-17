#include<cstdio>
#include<algorithm>
using namespace std;
//归并排序变形
int a[500010];
int tmp[500010];
long long ans;

void mergesort(int l, int mid, int r){
    int i=l, j=mid+1;
    for(int k=l; k<=r; k++){
        tmp[k] = a[k];
    }
    for(int k=l; k<=r; k++){
        if(i>mid) a[k] = tmp[j++];
        else if(j>r) a[k] = tmp[i++];
        else if(tmp[i]<tmp[j]) a[k] = tmp[i++];
        else if(tmp[i]>tmp[j]){
            
            a[k] = tmp[j++];
            ans += (mid-i+1);
            
        }
    }
    
}

void merge(int l, int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    merge(l, mid);
    merge(mid+1, r);
    mergesort(l, mid, r);

}

int main(){
    int n;
    while(scanf("%d",&n) && n!=0){
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        merge(1, n);
        printf("%lld\n", ans);
    }
    
}