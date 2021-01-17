#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[10][10];

int get_ans(int x1, int y1, int x2, int y2){
    int ans1=0, ans2, ans3;
    char ans4[4];
    //queen
    ans2 = (abs(x1-x2)==abs(y1-y2)|| x1==x2|| y1==y2) ? 1 : 2;

    //ju 
    ans3 = (x1==x2|| y1==y2)?1:2;

    //xiang    
    if(abs(x1-x2)==abs(y1-y2)){
        strcpy(ans4, "1");
    }
    else{
        strcpy(ans4, "Inf");
    }

    //king 先斜着走到同一行或者同一列
    
    int mint = min(abs(x1-x2), abs(x1-x2));
    ans1+=mint;
    x2 += x1-x2>0?mint:-mint;
    y2 += y1-y2>0?mint:-mint;
    ans1+=max(abs(x1-x2), abs(y1-y2));
        
    printf("%d %d %d %s\n", ans1, ans2, ans3, ans4);
}

int main(){
    int t;
    scanf("%d", &t);
    char a[2],b[2];

    while (t--)
    {   
        
        scanf("%s%s", a, b);
        int x1 = a[0] - int('a')+1;
        int x2 = b[0] - int('a')+1;
        int y1 = a[1] - int('0');
        int y2 = b[1] - int('0');
        get_ans(x1, y1, x2, y2);
        
    }
    
}