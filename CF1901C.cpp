#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

void DO(vector<ll>& v,ll k){
	for(auto &i:v)i = (i+k)/2;
	return;
}

void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(v.size() == 1){
		cout<<"0\n";
		return;
	}
	vector<ll> ans;
	ll a = v[0],b = v.back();
	while(a != b){
		if(a&1){
			a = (a+1)>>1;
			b = (b+1)>>1;
			ans.push_back(1);
		}
		else{
			a>>=1;
			b>>=1;
			ans.push_back(0);
		}
	}
	cout<<ans.size()<<'\n';
	if(ans.size()<=n)for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
