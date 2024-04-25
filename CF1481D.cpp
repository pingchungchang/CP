#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1010;
int paths[mxn][mxn];

void solve(int ii){
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			char c;
			cin>>c;
			if(c == '*')paths[i][j] = -1;
			else paths[i][j] = c-'a';
		}
	}
	if(m&1){
		cout<<"YES\n";
		for(int i= 0;i<m+1;i++){
			if(i&1)cout<<1<<' ';
			else cout<<"2 ";
		}
		cout<<'\n';
		return;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(paths[i][j] == paths[j][i]){
				cout<<"YES\n";
				for(int k = 0;k<m+1;k++){
					if(k&1)cout<<i<<' ';
					else cout<<j<<' ';
				}
				cout<<'\n';
				return;
			}
		}
	}
	if(n == 2){
		cout<<"NO\n";
		return;
	}
	vector<int> v = {1,2,3};
	do{
		if(paths[v[0]][v[1]] == paths[v[1]][v[2]]){
			assert(paths[v[1]][v[0]] == paths[v[2]][v[1]]);
			if(m%4 == 0){
				cout<<"YES\n";
				for(int i = 0;i<m+1;i++){
					if(i%4 == 0||i%4 == 2)cout<<v[1]<<' ';
					else if(i%4 == 1)cout<<v[0]<<' ';
					else cout<<v[2]<<' ';
				}
				cout<<'\n';
				return;
			}
			else{
				cout<<"YES\n";
				for(int i = 0;i<m+1;i++){
					if(i%4 == 1||i%4 == 3)cout<<v[1]<<' ';
					else if(i%4 == 0)cout<<v[0]<<' ';
					else cout<<v[2]<<' ';
				}
				cout<<'\n';
				return;
			}
		}
	}while(next_permutation(v.begin(),v.end()));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		solve(i);
	}
}
