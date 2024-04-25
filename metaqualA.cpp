#include <bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
	io
	int t;
	cin>>t;
	for(int kk = 1;kk<=t;kk++){
		cout<<"Case #"<<kk<<": ";
		int n,k;
		cin>>n>>k;
		int cnt[110] = {};
		for(int i = 0;i<n;i++){
			int tmp;
			cin>>tmp;
			cnt[tmp]++;
		}
		bool flag = true;
		for(auto &i:cnt){
			if(i>2){
				flag = false;
			}
		}
		if(n>k*2)flag = false;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

