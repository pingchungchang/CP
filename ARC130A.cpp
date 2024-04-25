#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	ll ans = 0;
	vector<pii> v;
	for(auto &i:s){
		if(v.empty()||v.back().fs != i)v.push_back({i,1});
		else v.back().sc++;
	}
	for(auto &i:v)ans += 1ll*i.sc*(i.sc-1)/2;
	cout<<ans;
}
