#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;


int R,n;
//每列的格子面积
int area[1000010] = {0};

int main(){
    int l, t, w, h;
    scanf("%d%d", &R, &n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &l, &t, &w, &h);
        for(int i=l; i<l+w; i++){
            area[i]+=h;
        }
    }
    l=0;
    int r=R;
    long long ls,rs;
    while (l<r)
    {   
        int mid = (l+r)/2;
        //ls和rs分别为左右的面积
        ls = 0;
        rs = 0;
        for(int i=0;i<mid; i++){
            ls+=area[i];
        }
        for(int i=mid; i<R; i++){
            rs+=area[i];
        }

        if(r-l==1){
            if(ls>=rs){
                if(ls+area[l]>= rs-area[l] && area[l]<=0){
                    l++;
                }
                else break;
            }
            else{
                l++;
            }
        }
        else{
            if(ls<=rs) l=mid;
            else r=mid;
        }

    }
    while (l+1<=R && area[l+1]==0)
    {
        l++;
    }
    printf("%d\n", l);
}