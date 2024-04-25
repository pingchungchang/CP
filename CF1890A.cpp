#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	if(mp.size()>2){
		cout<<"NO\n";
		return;
	}
	if(abs(mp.begin()->sc-mp.rbegin()->sc)>1)cout<<"NO\n";
	else cout<<"YES\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
