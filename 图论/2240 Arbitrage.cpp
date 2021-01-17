#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#include<cstring>
using namespace std;
//bellman-ford判断是否存在负环

struct node
{
    int u,v;
    double w;
}edge[1000];

int n,t;
bool bellman_ford(int s){
    double d[40];
    memset(d, 0, sizeof(d));
    d[s] = 1;
    node tmp;
    for(int i=1; i<n; i++){
        for(int j=1; j<=t; j++){
            tmp = edge[j];
            d[tmp.v] = max(d[tmp.v], d[tmp.u]*tmp.w) ;
        }
    }
    for(int i=1; i<=t; i++){
        tmp = edge[i];
        if(d[tmp.v] < d[tmp.u] * tmp.w) return true;
    }
    return false;
}


int main(){
    
    map<string, int> m;
    int Case=0;
    while (scanf("%d", &n) && n!=0)
    {   
        m.clear();
        string str1, str2;
        for(int i=1; i<=n; i++){
            cin>>str1;
            m[str1] = i;
            
        }
        scanf("%d", &t);
        double x;
        for(int i=1;i<=t; i++){
            
            cin>>str1>>x>>str2;
            edge[i].u = m[str1];
            edge[i].v = m[str2];
            edge[i].w = x;
        }
        int ans = bellman_ford(1);
        if(ans) printf("Case %d: Yes\n", ++Case);
        else printf("Case %d: No\n", ++Case);
    }
    
}