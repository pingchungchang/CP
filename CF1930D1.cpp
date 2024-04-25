#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


inline ll f(string s){
	int re = 0,r = -1;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '0')continue;
		if(r<i)r = i+2,re++;
	}
	return re;
}

void solve(){
	int n;
	string s;
	cin>>n>>s;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		string tmp;
		for(int j = i;j<n;j++){
			tmp += s[j];
			ans += f(tmp);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
