#include <bits/stdc++.h>
using namespace std;


vector<int> ans[2];
const int mxn = 1e7+10;
int lpf[mxn];
void solve(){
	int k;
	cin>>k;
	ans[0].push_back(lpf[k]);
	while(k!=1&&lpf[k] == ans[0].back())k/=lpf[k];
	ans[1].push_back(k);
	if(k == 1)ans[0].back() = ans[1].back() = -1;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(lpf,lpf+mxn,mxn);
	lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(lpf[i] == mxn){
			for(int j = i;j<mxn;j+=i)lpf[j] = min(lpf[j],i);
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
	for(auto &i:ans){
		for(auto &j:i)cout<<j<<' ';
		cout<<'\n';
	}
}
