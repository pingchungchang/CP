#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline bool isp(string s){
	for(int i = 0;i<s.size();i++)if(s[i] != s[s.size()-1-i])return false;
	return true;
}

void solve(){
	int n,m;
	cin>>n>>m;
	map<string,int> mp;
	string ans;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		if(mp[s] != 0){
			ans+=s;
			mp[s]--;
		}
		else{
			reverse(s.begin(),s.end());
			mp[s]++;
		}
	}
	string center;
	for(auto &i:mp){
		if(isp(i.fs))center = i.fs;
	}
	string rs = ans;reverse(rs.begin(),rs.end());
	cout<<ans.size()*2+center.size()<<'\n';
	cout<<ans+center+rs<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
