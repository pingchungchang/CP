#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int ca = 0;
const int mxn = 1e6+10;
ll pref[mxn][26];
void solve(){
	string s;
	cin>>s;
	ll n = s.size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<26;j++){
			pref[i+1][j]  =pref[i][j];
		}
		pref[i+1][s[i]-'a']++;
	}
	int q;
	cin>>q;
	int ans = 0;
	while(q--){
//		cout<<q<<endl;
		int s,e;
		cin>>s>>e;
		if((e-s+1)%2 == 0){
			continue;
		}
		int a[26] = {},b[26] = {};
		bool flag = true;
		int mid = (s+e)/2;
		for(int i = 0;i<26;i++){
			a[i] = pref[mid][i]-pref[s-1][i];
			b[i] = pref[e][i]-pref[mid][i];
		}
		int dif = 0;
//		for(int i = 0;i<26;i++)cout<<a[i]<<' ';cout<<'\n';for(auto &j:b)cout<<j<<' ';cout<<"\n\n";
		for(int i = 0;i<26;i++){
			if(a[i] == b[i]+1)dif++;
			else if(a[i] != b[i])flag = false;
		}
		if(flag&&dif == 1){
			ans++;
//			cout<<flag<<',';
			continue;
		}
		flag = true;
		mid--;
		for(int i = 0;i<26;i++){
			a[i] = pref[mid][i]-pref[s-1][i];
			b[i] = pref[e][i]-pref[mid][i];
		}
		dif = 0;
		for(int i = 0;i<26;i++){
			if(a[i] == b[i]-1)dif++;
			else if(a[i] != b[i])flag = false;
		}
		if(flag&&dif == 1){
			ans++;
//			cout<<1<<',';
		}
//		else cout<<0<<',';
	}
	cout<<"Case #"<<++ca<<": "<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

