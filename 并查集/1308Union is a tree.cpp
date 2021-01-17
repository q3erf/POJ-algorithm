#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
//只能由根节点去Union
int pre[10000010];

int main(){
    int x,y;
    int Case = 1;
    int edgenum = 0;
    int nodenum = 0;
    int node[maxn] = {0};
    while (scanf("%d %d",&x,&y) && x!=-1 && y!=-1)
    {   
        if(x==0 && y==0){
            printf("Case %d is a tree.\n", Case++);
            
        }
        else{
            node[x] = 1;
            node[y] = 1;
            edgenum++;
            while (scanf("%d %d",&x,&y) && x!=0 && y!=0)
            {
                node[x] = 1;
                node[y] = 1;
                edgenum++;
            }
            for(int i=1; i<maxn; i++){
                if(node[i]) nodenum++;
            }
            if(nodenum-edgenum==1) printf("Case %d is a tree.\n", Case++);
            else{
                printf("Case %d is not a tree.\n", Case++);
            }
            edgenum = 0;
            nodenum = 0;
            memset(node, 0, sizeof(node));
        }
        
    }
    
}