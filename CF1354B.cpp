#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

bool check(int cnt[]){
	for(int i = 0;i<3;i++)if(!cnt[i])return false;
	return true;
}

void solve(){
	string s;
	cin>>s;
	int cnt[3] = {};
	int pt = 0;
	int ans = 1e9;
	for(int i = 0;i<s.size();i++){
		if(pt<=i){
			pt = i+1;
			memset(cnt,0,sizeof(cnt));
			cnt[s[i]-'1'] = 1;
		}
		while(pt<s.size()&&!check(cnt)){
			cnt[s[pt]-'1']++;
			pt++;
		}
		if(check(cnt))ans = min(ans,pt-i);
		cnt[s[i]-'1']--;
	}
	if(ans>s.size())cout<<0<<'\n';
	else cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
