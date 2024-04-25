#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	string s;
	cin>>s;
	vector<int> v;
	int diff = 0;
	int n = s.size();
	for(int i = 0;i<n;i++){
		if(s[i] == '?')v.push_back(i);
		else if(s[i] == ')')diff--;
		else diff++;
	}
	if(v.size()<2){
		cout<<"YES\n";
		return;
	}
	int cnt = v.size();
	cnt -= diff;
	cnt /=2;
	if(cnt == 0||cnt > v.size()-1){
		cout<<"YES\n";
		return;
	}
	for(int i = 0;i<v.size();i++){
		if(i<cnt)s[v[i]] = '(';
		else s[v[i]] = ')';
	}
	swap(s[v[cnt-1]],s[v[cnt]]);
//	cout<<s<<'\n';
	diff = 0;
	for(auto i:s){
		if(i == '(')diff++;
		else diff--;
		if(diff<0){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

