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
	string s;
	cin>>s;
	int arr[n];
	vector<int> pos[m+1];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		pos[arr[i]].push_back(i);
	}
	string ans(s.size(),'#');
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<pos[i].size();j++){
			ans[pos[i][j]] = s[pos[i][j-1]];
		}
		if(!pos[i].empty())ans[pos[i][0]] = s[pos[i].back()];
	}
	cout<<ans;
}
