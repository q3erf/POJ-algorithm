#include<cstdio>
#include<algorithm>

using namespace std;

int f(int m, int n){
    if(m<n) return m;
    if(m==n) return m+1;
    int t = m/n;
    return f(m%n+t, n) + n*t;
}

int main(){
    int n,k;
    while (scanf("%d%d", &n, &k)!=EOF)
    {
        printf("%d\n", f(n, k));
    }
    
}