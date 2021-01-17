#include<cstdio>
using namespace std;

struct node
{   
    //gang 表示当前点与其根节点的关系 0表示同一个帮派 1表示不同帮派
    int paret,gang;
}pre[100010];

int find(int x){
    if(x==pre[x].paret) return x;
    int t = pre[x].paret;
    pre[x].paret = find(t);
    pre[x].gang = (pre[x].gang+pre[t].gang)%2;
    //更新x与根节点的关系，由于上述递归查询使得x的父节点与根节点的关系已知
    //即x与根节点的关系直接讲父亲与根节点的关系加上来即可

    return pre[x].paret;
}

void Union(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(rx!=ry){
        pre[ry].paret = rx;
        pre[ry].gang = (pre[x].gang+1+pre[y].gang)%2;//关系传递直接求和
    }
}

int main(){
    int t,n,m,x,y;
    char c;
    scanf("%d",&t);
    while (t--)
    {   
        
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n;i++){
            pre[i].paret = i;
            //要初始化0，并不是默认0 不然会错 
            pre[i].gang = 0;
        }
        
        for(int i=0;i<m;i++){
            getchar();
            scanf("%c %d %d", &c, &x, &y);
            
            if(c=='D'){
                Union(x,y);
            }else{
                int rx = find(x);
                int ry = find(y);
                
                if(rx!=ry) {printf("Not sure yet.\n");}
                else{
                    
                    if(pre[x].gang==pre[y].gang) {
                        printf("In the same gang.\n");
                        }
                    else{
                        printf("In different gangs.\n");
                        }
                }

            }
        }
    }
    
}