#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	int ans = INT_MAX;
	pair<int,int> range;
	pair<int,int> p = make_pair(1e9,1e9);
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(i == 0)range = make_pair(a,b);
		if(a<range.first)p.first = c;
		if(b>range.second)p.second = c;
		if(a== range.first)p.first = min(c,p.first);
		if(b == range.second)p.second = min(c,p.second);
		if(range.first <= a&&range.second >= b)ans = ans;
		else ans = INT_MAX;
		ans = min(ans,p.first+p.second);
		if(a<=range.first&&b>=range.second){
			ans = min(ans,c);
		}
		range.first = min(range.first,a);
		range.second = max(range.second,b);
		cout<<ans<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
