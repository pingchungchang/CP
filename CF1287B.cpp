#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	map<string,ll> mp;
	vector<string> v;
	for(int i = 0;i<n;i++){
		string tmp;
		cin>>tmp;
		v.push_back(tmp);
		mp[tmp]++;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	ll ans = 0;
	for(int i = 0;i<v.size();i++){
		for(int j = i+1;j<v.size();j++){
			string &ta = v[i],&tb = v[j];
			string tmp;
			for(int ii = 0;ii<k;ii++){
				if(ta[ii] == tb[ii])tmp += ta[ii];
				else{
					if(ta[ii] != 'S'&&tb[ii] != 'S')tmp += 'S';
					else if(ta[ii] != 'E'&&tb[ii] != 'E')tmp += 'E';
					else tmp += 'T';
				}
			}
			if(mp.find(tmp) != mp.end())ans += mp[ta]*mp[tb]*mp[tmp];
		}
	}
	ans/=3;
	for(auto &i:mp)ans += i.sc*(i.sc-1)*(i.sc-2)/6;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
