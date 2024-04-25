#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(v.empty())v.push_back(k);
		else if(v.back()%2==k%2)ans++;
		else v.push_back(k);
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
