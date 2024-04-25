#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int cnt[26] = {};
	string s;
	int n;
	cin>>n>>s;
	if(n&1){
		cout<<-1<<'\n';
		return;
	}
	for(auto &i:s)cnt[i-'a']++;
	if(*max_element(cnt,cnt+26)>n/2){
		cout<<-1<<'\n';
		return;
	}
	for(auto &i:cnt)i = 0;
	for(int i = 0;i<n/2;i++){
		if(s[i] == s[n-1-i])cnt[s[i]-'a']++;
	}
	int total = 0;
	for(auto &i:cnt)total += i;
	cout<<max((total+1)/2,*max_element(cnt,cnt+26))<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
