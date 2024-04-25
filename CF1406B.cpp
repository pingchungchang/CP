#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll ans = -1e18;
	vector<int> pos,neg;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k>=0)pos.push_back(k);
		else neg.push_back(k);
	}
	sort(pos.begin(),pos.end());
	sort(neg.rbegin(),neg.rend());
	vector<ll> v;
	for(int i = 0;i<min((int)pos.size(),5);i++)v.push_back(pos[i]);
	for(int i = 0;i<min((int)neg.size(),5);i++)v.push_back(neg[i]);
	for(int i = 0;i<v.size();i++)for(int ii = i+1;ii<v.size();ii++)for(int iii = ii+1;iii<v.size();iii++)
		for(int iiii = iii+1;iiii<v.size();iiii++)for(int iiiii = iiii+1;iiiii<v.size();iiiii++)
			ans = max(ans,v[i]*v[ii]*v[iii]*v[iiii]*v[iiiii]);
	v.clear();
	sort(neg.begin(),neg.end());
	sort(pos.rbegin(),pos.rend());
	for(int i = 0;i<min((int)pos.size(),5);i++)v.push_back(pos[i]);
	for(int i = 0;i<min((int)neg.size(),5);i++)v.push_back(neg[i]);
	for(int i = 0;i<v.size();i++)for(int ii = i+1;ii<v.size();ii++)for(int iii = ii+1;iii<v.size();iii++)
		for(int iiii = iii+1;iiii<v.size();iiii++)for(int iiiii = iiii+1;iiiii<v.size();iiiii++)
			ans = max(ans,v[i]*v[ii]*v[iii]*v[iiii]*v[iiiii]);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
