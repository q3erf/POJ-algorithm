#include<cstdio>
#include<algorithm>

using namespace std;
int a[1510];
void get_a(){
    int p2=1,p3=1,p5=1;
    a[1] = 1;
    for(int i=2;i<=1500; i++){
        int v1 = a[p2] *2;
        int v2 = a[p3] *3;
        int v3 = a[p5] *5;
        a[i] = min(v1, min(v2, v3));
        // printf("%d\n",a[i]);
        if(a[i]==v1) p2++;
        if(a[i]==v2) p3++;
        if(a[i]==v3) p5++;
    }
}


int main(){
    get_a();
    int k;
    
    while (scanf("%d", &k) && k!=0)
    {
        printf("%d\n",a[k]);
    }
    
    
}