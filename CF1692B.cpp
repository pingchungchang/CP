#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	if((n-mp.size())%2 == 0){
		cout<<mp.size()<<'\n';
	}
	else cout<<mp.size()-1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

