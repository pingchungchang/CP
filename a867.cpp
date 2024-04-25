#include <bits/stdc++.h>
using namespace std;

char v[17][32];
int main(){
	memset(v,'.',sizeof(v));
	for(int i = 1;i<=15;i++){
		for(int j = 1;j<=30;j++){
			cin>>v[i][j];
		}
	}
	int ans[17][32] = {};
	for(int i = 1;i<=15;i++){
		for(int j = 1;j<=30;j++){
			if(v[i][j] == '*'){
				ans[i][j] = -1;
				continue;
			}
			for(int k = 1;k>=-1;k--){
				for(int l = 1;l>=-1;l--){
					if(k == 0&&l == 0)continue;
					if(v[k+i][l+j] == '*')ans[i][j]++;
				}
			}
		}
	}
	for(int i = 1;i<=15;i++){
		for(int j = 1;j<=30;j++){
			if(ans[i][j] == 0)cout<<'.';
			else if(ans[i][j] == -1)cout<<'*';
			else cout<<ans[i][j];
		}
		cout<<'\n';
	}
}
