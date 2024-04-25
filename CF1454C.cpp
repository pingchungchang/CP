#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v[n+1];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	int ans = n-1;
	for(auto &i:v){
		if(i.empty())continue;
		i.push_back(n+1);
		int pre = 0;
		int tmp = 0;
		for(auto &j:i){
			if(j != pre+1){
				tmp++;
			}
			pre = j;
		}
		ans = min(ans,tmp);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
