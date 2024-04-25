#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> ans[n+1];
	int C = 1;
	for(int i = 1;i<=n;i++){
		if(i&1)for(int j = n;j>=1;j--)ans[j].push_back(C++);
		else for(int j = 1;j<=n;j++)ans[j].push_back(C++);
	}
	for(int i = 1;i<=n;i++){
		for(auto &j:ans[i])cout<<j<<' ';cout<<'\n';
	}
	return 0;
}
