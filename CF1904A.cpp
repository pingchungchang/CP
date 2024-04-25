#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int a,b;
	cin>>a>>b;
	pii dir[] = {{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}};
	set<pii> sa,sb;
	pii pa,pb;
	cin>>pa.fs>>pa.sc>>pb.fs>>pb.sc;
	for(auto &i:dir)sa.insert({pa.fs+i.fs,pa.sc+i.sc});
	for(auto &i:dir)sb.insert({pb.fs+i.fs,pb.sc+i.sc});
	int ans = 0;
	for(auto &i:sb)if(sa.find(i) != sa.end())ans++;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
