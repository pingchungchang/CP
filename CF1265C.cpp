#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	deque<pii> v;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(v.empty()||v.back().fs != k)v.push_back({k,1});
		else v.back().sc++;
	}
	int g = v.front().sc;
	v.pop_front();
	int s = 0;
	while(!v.empty()&&s<=g){
		s += v.front().sc;
		v.pop_front();
	}
	int b = 0;
	while(!v.empty()&&(g+s+b+v.front().sc)*2<=n){
		b += v.front().sc;
		v.pop_front();
	}
	if(g>=b||g>=s||!g||!b||!s)cout<<"0 0 0\n";
	else cout<<g<<' '<<s<<' '<<b<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
