#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,m,d;
	cin>>n>>m>>d;
	vector<int> v(m);
	int sum = n;
	for(int i = 0;i<m;++i){
		cin>>v[i];
		sum -= v[i];
	}
	if(d == 1&&sum != 0){
		cout<<"NO\n";
		return 0;
	}
	
	int dif = (sum+m)/(m+1);
	if(dif>=d){
		cout<<"NO\n";
		return 0;
	}
	int t = sum%(m+1);
	vector<pii> ans;
	
	for(int i = 0;i<m;i++){
		if(i == t&&t != 0)dif--;
		ans.push_back(make_pair(0,dif));
		ans.push_back(make_pair(i+1,v[i]));
	}
	if(m == t&&t != 0)dif--;
	ans.push_back(make_pair(0,dif));
	vector<int> returns;
	for(auto i:ans){
		for(int j = 0;j<i.sc;j++)returns.push_back(i.fs);
	}
	cout<<"Yes\n";
	for(auto it:returns)cout<<it<<' ';
	return 0;
}

