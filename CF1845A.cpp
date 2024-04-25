#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	vector<int> ans;
	if(x != 1){
		while(n--)ans.push_back(1);
	}
	else if(k==1&&x == 1){
		cout<<"NO\n";
		return;
	}
	else if(k == 2){
		if(n&1){
			cout<<"NO\n";
			return;
		}
		else{
			while(n)n-=2,ans.push_back(2);
		}
	}
	else if(n == 1){
		cout<<"NO\n";
		return;
	}
	else if(n%2 == 0){
		while(n)n-=2,ans.push_back(2);
	}
	else{
		while(n != 3)n-=2,ans.push_back(2);
		ans.push_back(3);
	}
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
