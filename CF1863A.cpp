#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,a,q;
	cin>>n>>a>>q;
	int sum = a,cnt = a;
	bool all = false;
	if(a == n)all = true;
	string s;
	cin>>s;
	for(auto &i:s){
		if(i == '+')cnt++,sum++;
		else cnt--;
		if(cnt == n)all = true;
	}
	if(all)cout<<"YES\n";
	else if(sum >= n)cout<<"MAYBE\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
