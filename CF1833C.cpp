#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto &i:arr)cin>>i;
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	int cnt[2] = {};
	for(auto &i:arr){
		if((i&1)==(arr[0]&1)){
			cnt[i&1]++;
			continue;
		}
		if(!cnt[1]){
			cout<<"NO\n";
			return;
		}
		cnt[i&1]++;
	}
	//cout<<cnt[0]<<cnt[1]<<'\n';
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
