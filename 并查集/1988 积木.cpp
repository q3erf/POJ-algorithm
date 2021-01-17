#include<cstdio>
#define maxn 30010
using namespace std;
//
//r[i]表示i之下的元素个数
//s[i]表示i所在堆中元素个数
int pre[maxn],r[maxn],s[maxn];

int findpre(int x){
    if(pre[x]==x) return x;

    int px = pre[x];
    pre[x] = findpre(pre[x]);
    r[x] +=  r[px];
    return pre[x];
}

void Union(int x, int y){
    //将含x的堆叠到含y的堆上
    int rx = findpre(x);
    int ry = findpre(y);
    pre[rx] = ry;
    r[rx] += s[ry];
    s[ry] += s[rx];
}

int main(){
    int p,x,y;
    scanf("%d",&p);
    char c;
    for(int i=1;i<=maxn; i++){
        pre[i] = i;
        r[i] = 0;
        s[i] = 1;
    }
    while (p--)
    {   
        getchar();
        scanf("%c",&c);
        if(c=='M'){
            scanf("%d %d",&x, &y);
            Union(x,y);
        }
        else{
            scanf("%d",&x);
            findpre(x);
            printf("%d\n", r[x]);
        }
        

    }
    
}