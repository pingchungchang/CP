#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,l;
	cin>>n>>l;
	int cnt[l] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<l;j++){
			if((1<<j)&k)cnt[j]++;
			else cnt[j]--;
		}
	}
	int ans = 0;
	for(int i = 0;i<l;i++){
		if(cnt[i]>0)ans ^= (1<<i);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
