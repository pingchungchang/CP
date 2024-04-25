#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int pref[mxn];
int dep[mxn];

void solve(){
	int k;
	string s;
	cin>>k>>s;
	reverse(s.begin(),s.end());
	for(auto &i:s)if(i == '(')i = ')';else i = '(';
	int n = s.size();
	//cout<<s<<'\n';
	s = "#"+s;
	while(k--){
		fill(dep,dep+n+1,0);
		fill(pref,pref+n+1,0);
		for(int i = 1;i<=n;i++){
			pref[i] = pref[i-1];
			dep[i] = dep[i-1];
			if(s[i] == '(')dep[i]++;
			else dep[i]--,pref[i]++;
		}
		int pre = 1;
		pii ans = {1,1};
		for(int i = 2;i<=n;i++){
			if(s[i] == '('){
				if(dep[i] == 1)pre = i;
			}
			else{
				if(pref[i]-pref[pre]-1>pref[ans.sc]-pref[ans.fs]-1)ans = {pre,i};
			}
		}
		string t;
		for(int i = 0;i<=ans.fs;i++)t += s[i];
		t += ')';
		for(int i = ans.fs+1;i<ans.sc;i++)t += s[i];
		for(int i = ans.sc+1;i<=n;i++)t += s[i];
		s = t;
		//cout<<t.substr(1,t.size()-1)<<':'<<ans.fs<<' '<<ans.sc<<'\n';
	}
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		dep[i] = dep[i-1];
		if(s[i] == '(')dep[i]++;
		else dep[i]--,pref[i]++;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(s[i] == ')')ans += dep[i];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}

/*
( ( ( ( ) ) ) ( ( ) ( ) ) ( ) ( ( ) ) )
1 2 3 4 3 2 1 2 3 2 3 2 1 2 1 2 3 2 1 0

x ( ) ( ) ( ( ) ) ( ) ( ) ( ) ( ) ( ( ) )
0 1 0 1 0 1 2 1 0 1 0 1 0 1 0 1 0 1 2 1 0


( ( ( ) ) ( ) ( ) )


x ( ( ( ) ) ( ) ( ) )
0 1 2 3 2 1 2 1 2 1 0

x ( ) ( ( ) ) ( ) ( )
0 1 0 1 2 1 0 1 0 1 0
*/
