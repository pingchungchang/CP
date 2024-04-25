#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> lines(n);
	for(int i = 0;i<n;i++)cin>>lines[i];
	sort(lines.begin(),lines.end());
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		bool flag = false;
		auto it = lower_bound(lines.begin(),lines.end(),b);
		if(it != lines.end()&&(b-*it)*(b-*it)<4ll*a*c){
			cout<<"YES\n"<<*it<<'\n';
			continue;
		}
		if(it != lines.begin()&&(b-*(--it))*(b-*it)<4ll*a*c){
			cout<<"YES\n"<<*it<<'\n';
			continue;
		}
		cout<<"NO\n";
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
