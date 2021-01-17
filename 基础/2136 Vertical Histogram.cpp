#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

char out[100][30];
int main(){
	
	for(int i=0; i<5; i++){
		for(int j=0; j<100; j++){
			out[i][j] = ' ';
		}
	}
	int cnt[30] = {0};
	string s;
	for(int p=1; p<=4; p++){
		getline(cin, s);
		
		for(int i=0; i<s.length();i++){
			if(s[i]>='A' && s[i]<='Z')
			cnt[s[i]-int('A')]++;
		}
	}
	int maxn = -1;
	for(int i=0; i<26; i++){
		maxn = max(cnt[i], maxn);
	}
	for(int i=0; i<26; i++){
		out[0][i] = 'A'+i;
		for(int j=1; j<=cnt[i]; j++){
			out[j][i] = '*';
		}
	}
	for(int i=maxn; i>=0; i--){
		for(int j=0; j<26; j++){
			printf("%c", out[i][j]);
			if(j<25) printf(" ");
		}
		printf("\n");
	}
}