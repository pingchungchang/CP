#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<ll> ans;

void solve(){
	ans.clear();
	ll n,l,r;
	cin>>n>>l>>r;
	//i,i+1,i,i+2,i,i+3,....i,n
	ll sum = 0;
	for(ll i = 1;i<=n;i++){
		if(sum+(n-i)*2>=l){
			ll start = l-sum;
			for(ll j = start;j<=(n-i)*2&&ans.size()<r-l+1;j++){
				if(j&1)ans.push_back(i);
				else ans.push_back(i+j/2);
			}
			pll now = {i+1,1};
			while(now.fs < n&&ans.size() < r-l+1){
				if(now.sc&1)ans.push_back(now.fs);
				else ans.push_back(now.fs+now.sc/2);
				now.sc++;
				if(now.sc>(n-now.fs)*2)now = {now.fs+1,1};
			}
			break;
		}
		sum += (n-i)*2;
	}
	if(r == n*(n-1)+1)ans.push_back(1);
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
