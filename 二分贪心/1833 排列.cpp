#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
//先找出顺序对a[j-1], a[j]
//再在a[j..]之中找到比啊a[j-1]大的最小元素
//对a[j-n]排序

using namespace std;
int a[1030];

int t,n,k;
int get_max_min(int indexj){
    int minm = inf;
    int ans_index;
    for(int i=indexj+1; i<=n; i++){
        if(a[i]>a[indexj]) {
            if(a[i]<minm) {
                minm = a[i];
                ans_index = i;
            }
        }
    }
    return ans_index;
}


int main(){
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d",&n, &k);
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        while (k--)
        {     
            int j;
            for(j=n;j>1;j--){
                if(a[j]>a[j-1]){
                    int indexj = get_max_min(j-1);
                    //将indexj所在值与j-1所在值互换
                    int tmp = a[j-1];
                    a[j-1] = a[indexj];
                    a[indexj] = tmp;
                    //对a[j]到a[n]排序
                    sort(a+j, a+n+1);
                    break;
                }
            }
            if(j==1){
                sort(a+1, a+n+1);
            }
        }
        for(int i=1; i<=n; i++){
            printf("%d",a[i]);
            if(i==n) printf("\n");
            else printf(" ");
        }

    }
    
}