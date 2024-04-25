#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string s;
vector<pii> big,sm;

void solve(){
	sm.clear();
	big.clear();
	cin>>s;
	int cnt = 0;
	for(auto &i:s){
		if(i == 'B'){
			if(!big.empty())big.pop_back();
		}
		else if(i == 'b'){
			if(!sm.empty())sm.pop_back();
		}
		else if(i>='A'&&i<='Z')big.push_back(make_pair(++cnt,i));
		else sm.push_back(make_pair(++cnt,i));
	}
	for(auto &i:big)sm.push_back(i);
	sort(sm.begin(),sm.end());
	for(auto &i:sm)cout<<(char)i.sc;
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
