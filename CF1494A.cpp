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
void solve(){
	string s;
	cin>>s;
	map<char,int> mp;
	bool flag = false;
	for(int i = -1;i<=1;i+= 2){
		for(int j = -1;j<=1;j+=2){
			for(int k = -1;k<=1;k+= 2){
				int cnt= 0;
				bool flag2 = true;
				mp['A'] = i;mp['B'] = j;mp['C'] = k;
				for(auto ii:s){
					cnt += mp[ii];
					if(cnt<0)flag2 = false;
				}
				if(cnt == 0&&flag2)flag = true;
			}
		}
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

