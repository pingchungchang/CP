#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll a,b,x;
	cin>>a>>b>>x;
	ll tmp = 1;
	int ans = 0;
	vector<int> v;
	for(;tmp<=x&&x%tmp==0;tmp*=a){
		ll tt = tmp;
		for(;tt<=x&&x%tt==0;tt*=b){
			v.push_back(x/tt);
		}
	}
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v.size()<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
