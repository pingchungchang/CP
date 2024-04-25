#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string s;
void solve(){
	map<int,int> mp;
	for(auto i:s){
		if(mp.count((int)i) == 0)mp[(int)i] = 1;
		else mp[(int)i]++;
	}
	vector<pii> v;
	for(auto it:mp){
		v.push_back(make_pair(it.sc,-it.fs));
	}
	sort(v.begin(),v.end());
	for(auto i:v){
		cout<<-i.sc<<' '<<i.fs<<'\n';
	}
	cout<<'\n';
	return;
}
int main(){
//	cout<<(int)'.';
	while(getline(cin,s))solve();
}

