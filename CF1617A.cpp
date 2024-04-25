#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string a,b;
	cin>>a>>b;
	int cnt[26] = {};
	for(auto &i:a)cnt[i-'a']++;
	if(b != "abc"){
		sort(a.begin(),a.end());
		cout<<a<<'\n';
		return;
	}
	if(1LL*cnt[0]*cnt[1]*cnt[2] == 0){
		sort(a.begin(),a.end());
		cout<<a<<'\n';
		return;
	}
	while(cnt[0]--)cout<<'a';
	while(cnt[2]--)cout<<'c';
	while(cnt[1]--)cout<<'b';
	for(int i = 3;i<26;i++)while(cnt[i]--)cout<<(char)(i+'a');
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
