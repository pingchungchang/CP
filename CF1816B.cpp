#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int ans[n][2];
	int r = 0,c = 0;
	ans[0][0] = n*2;
	int big = n*2-1;
	int small = 1;
	if(n&1)ans[n-1][1] = small++;
	else ans[n-1][1] = big--;
	for(int i = 1;i<n;i++){
		if(i&1){
			ans[i-1][1] = small++;
			ans[i][0] = small++;
		}
		else{
			ans[i][0] = big--;
			ans[i-1][1] = big--;
		}
	}
	for(int i =0;i<2;i++){
		for(int j = 0;j<n;j++)cout<<ans[j][i]<<' ';cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}

