#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> v(n,0);
	for(int i = 1;i<=n;i++)v[i-1] = i;
	if(abs(a-b)>1||a+b>n-2){
		cout<<"-1\n";
		return;
	}
	int l = n-a-b,r = n;
	bool flag = true;
	for(int i = n-a-b-1;i<n;i++){
		if(flag)v[i] = r--;
		else v[i] = l++;
		flag = flag^1;
	}
	if(a<b)for(auto &i:v)i = n-i+1;
	for(auto i:v)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

