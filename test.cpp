#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1009;
int x[N], y[N], fa[N];
bool p[N];
vector<int> v[N];

int find(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    int n, d;
    char s[2];
    scanf("%d%d", &n, &d);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        fa[i] = i;
    }
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) <= d*d)
            {
                v[j].push_back(i);
                v[i].push_back(j);
            }
        }
    while(~scanf("%s", s))
    {
        int a, b;
        if(s[0] == 'O')
        {
            scanf("%d", &a);
            p[a] = true;
            for(int i=0; i<v[a].size(); i++)
                if(p[v[a][i]])
                {
                    b = find(v[a][i]);
                    fa[b] = a;
                }
        }
        else
        {
            scanf("%d%d", &a, &b);
            int ta = find(a);
            int tb = find(b);
            if(ta == tb)
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}