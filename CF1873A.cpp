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
	for(int i = 0;i<3;i++){
		for(int j = i;j<3;j++){
			swap(s[i],s[j]);
			if(s == "abc"){
				cout<<"YES\n";
				return;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
