#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	map<char,int> mp;
	for(auto &i:s){
		mp[i]++;
	}
	int lr = min(mp['L'],mp['R']);
	int ud = min(mp['U'],mp['D']);
	string ans;
	for(int i = 0;i<lr;i++)ans += 'R';
	for(int i = 0;i<ud;i++)ans += 'D';
	for(int i = 0;i<lr;i++)ans += 'L';
	for(int i = 0;i<ud;i++)ans += 'U';
	if(lr == 0){
		cout<<min(ud,1)*2<<'\n';
		if(min(ud,1))cout<<"UD\n";
		return;
	}
	if(!ud){
		cout<<min(lr,1)*2<<'\n';
		if(min(lr,1))cout<<"LR\n";
		return;
	}
	cout<<ans.size()<<'\n';
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
