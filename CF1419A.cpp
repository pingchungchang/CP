#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool flag = false;
	if(n&1){
		for(int i = 0;i<n;i+=2)if((s[i]-'0')&1)flag = true;
		cout<<(flag?"1\n":"2\n");
	}
	else{
		for(int i = 1;i<n;i+=2)if((s[i]-'0')%2 == 0)flag = true;
		cout<<(flag?"2\n":"1\n");
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
