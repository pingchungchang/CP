#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	set<int> row,col;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>v[i][j];
			if(v[i][j]){
				row.insert(i);
				col.insert(j);
			}
		}
	}
	int c = min(n-row.size(),m-col.size());
	if(c&1)cout<<"Ashish\n";
	else cout<<"Vivek\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
