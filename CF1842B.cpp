#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline bool check(int a,int tar){
	for(int i = 0;i<30;i++){
		if((tar&(1<<i)) == 0&&(a&(1<<i)) != 0)return false;
	}
	return true;
}

void solve(){
	int n,tar;
	cin>>n>>tar;
	vector<int> v[3];
	for(int i  = 0;i<3;i++){
		for(int j = 0;j<n;j++){
			int k;
			cin>>k;
			v[i].push_back(k);
		}
		reverse(v[i].begin(),v[i].end());
	}
	int now = 0;
	for(int i = 0;i<3;i++){
		while(!v[i].empty()&&check(v[i].back(),tar)){
			now |= v[i].back();
			v[i].pop_back();
		}
	}
	if(now == tar)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
