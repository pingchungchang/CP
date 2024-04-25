#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string arr[n];
	for(auto &i:arr)cin>>i;
	pii tar[] = {{0,1},{1,0},{n-1,n-2},{n-2,n-1}};
	vector<pii> ans;
	if(arr[0][1] == arr[1][0]){
		if(arr[n-1][n-2] == arr[1][0])ans.push_back({n,n-1});
		if(arr[n-2][n-1] == arr[1][0])ans.push_back({n-1,n});
	}
	else if(arr[n-1][n-2] == arr[n-2][n-1]){
		if(arr[0][1] == arr[n-1][n-2])ans.push_back({1,2});
		if(arr[1][0] == arr[n-2][n-1])ans.push_back({2,1});
	}
	else{
		if(arr[0][1] == '1')ans.push_back({1,2});
		else ans.push_back({2,1});
		if(arr[n-1][n-2] == '0')ans.push_back({n,n-1});
		else ans.push_back({n-1,n});
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
