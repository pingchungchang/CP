#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int p1 = -1, p2 = v.size();
	ll s1 = 0;
	ll s2 = 0;
	while(p1+1 != p2){
		if(s1>=s2){
			p2--;
			s2 += v[p2];
		}
		else if(p1+1<=v.size()-p2){
			p1++;
			s1 += v[p1];
		}
		if(p1+1>v.size()-p2&&s1<s2){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

