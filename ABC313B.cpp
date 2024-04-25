#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool lose[n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		lose[b] = true;
	}
	vector<int> v;
	for(int i = 1;i<=n;i++)if(!lose[i])v.push_back(i);
	if(v.size() != 1)cout<<-1;
	else cout<<v[0];
}
