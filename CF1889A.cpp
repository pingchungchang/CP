#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int c = 0;
	for(auto &i:s)c += (i=='0'?1:-1);
	if(c){
		cout<<"-1\n";
		return;
	}
	vector<int> ans;
	for(int ii = 0;ii<300;ii++){
		n = s.size();
		for(int i = 0;i<n;i++){
			if(s[i] == s[n-1-i]){
				if(s[i] == '0'){
					ans.push_back(n-i-1);
					s = s.substr(0,n-i)+"01"+s.substr(n-i,i);
					break;
				}
				else{
					ans.push_back(i-1);
					s = s.substr(0,i)+"01"+s.substr(i,n-i);
					break;
				}
			}
		}
		n = s.size();
	}
	for(int i = 0;i<n;i++){
		if(s[i] == s[n-1-i]){
			cout<<"-1\n";
			return;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
