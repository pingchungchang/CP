#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	string s;
	cin>>s;
	bool flag = false;
	pair<char,char> p = {s[0],s.back()};
	if(p.fs>p.sc){
		flag = true;
		swap(p.fs,p.sc);
	}
	vector<pii> v(s.size());
	for(int i = 0;i<s.size();i++){
		v[i] = {s[i],i};
	}
	sort(_all(v));
	vector<int> ans;
	int n = s.size();
	for(int i = 0;i<n;i++){
		if(v[i].sc == 0||v[i].sc == n-1)continue; 
		if(p.fs<=v[i].fs&&p.sc>=v[i].fs)ans.push_back(v[i].sc);
	}
	if(flag)reverse(_all(ans));
	cout<<abs(p.sc-p.fs)<<' '<<ans.size()+2<<'\n';
	cout<<1<<' ';for(auto &i:ans)cout<<i+1<<' ';cout<<n<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

