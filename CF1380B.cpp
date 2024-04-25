#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int cnt[3] = {};
	for(auto &i:s){
		if(i == 'R')cnt[0]++;
		else if(i == 'P')cnt[1]++;
		else cnt[2]++;
	}
	int b = *max_element(cnt,cnt+3);
	if(b == cnt[0])cout<<string(s.size(),'P');
	else if(b == cnt[1])cout<<string(s.size(),'S');
	else cout<<string(s.size(),'R');
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
