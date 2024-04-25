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
	for(int i = 0;i+2<n;i++){
		if(s.substr(i,3) == "..."){
			cout<<"2\n";
			return;
		}
	}
	int ans = 0;
	for(auto &i:s)ans += (i == '.');
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
