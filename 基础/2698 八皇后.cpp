#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int queenPos[10];
int ans[10][10];
int num=1;
void NQueen(int k);

int main()
{
memset(ans,0,sizeof(ans));
NQueen(0);
return 0;
}

void NQueen(int k)
{
    if(k==8)
    {
        for(int i=0; i<8; i++)
        {
        int j;
        j=queenPos[i];
        ans[i][j]=1;
        }
        cout << "No. " << num++ << endl;
        for(int i=0; i<8; i++)
        {
        for(int j=0; j<8; j++)
        {
        cout << ans[j][i] << " ";
        }
        cout << endl;
        }
        memset(ans,0,sizeof(ans));
        return ;
    }
    for(int i=0; i<8; ++i)
    {
        int j;
        for(j=0; j<k; ++j)
        {
        if(queenPos[j]==i || abs(queenPos[j]-i)==abs(k-j))
        break;
        }
        if(j==k)
        {
        queenPos[k]=i;
        NQueen(k+1);
        }
    }
}