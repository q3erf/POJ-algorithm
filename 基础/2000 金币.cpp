#include<cstdio>
#include<algorithm>

using namespace std;
int a[10010];
int n;

void get_a(){
    int cnt = 1;
    a[1] = 1;
    for(int i=2;i <=10000; i++){
        for(int j=1; j<=i; j++){
            a[cnt+1] =  a[cnt]+i;
            cnt++;
            if(cnt>10000) return;
        }
    }
}

int main(){
    get_a();
    while (scanf("%d", &n) && n!=0)
    {
        printf("%d %d\n", n,a[n]);
    }
    
}