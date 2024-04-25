#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

vector<int> calc(vector<int> &v,int l,int r){
	vector<int> re;
	for(int i = r+1;i<v.size();i++)re.push_back(v[i]);
	for(int i = r;i>=l;i--)re.push_back(v[i]);
	for(int i = 0;i<l;i++)re.push_back(v[i]);
	return re;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	vector<int> ans(n,0);
	if(v[0] != n||n == 1){
		int p = 0;
		for(;p<n&&v[p] != n;p++);
		for(int i = 0;i<p;i++){
			ans = max(ans,calc(v,i,p-1));
		}
		for(int i = 0;i<=p;i++)ans = max(ans,calc(v,i,p));
		ans = max(ans,calc(v,0,p));
	}
	else{
		int p = 0;
		for(;p<n&&v[p] != n-1;p++);
		for(int i = 0;i<p;i++)ans = max(ans,calc(v,i,p-1));
		ans = max(ans,calc(v,0,p));
		for(int i = 0;i<=p;i++)ans = max(ans,calc(v,i,p));
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
