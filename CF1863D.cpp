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
	string arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<m;i++){
		int cnt = 0;
		for(int j = 0;j<n;j++){
			if(arr[j][i] == 'W')cnt--;
			else if(arr[j][i] == 'B')cnt++;
		}
		for(int j = 0;j<n;j++){
			if(arr[j][i] == 'L'){
				if(cnt>0)arr[j][i] = 'W',arr[j][i+1] = 'B',cnt--;
				else arr[j][i] = 'B',arr[j][i+1] = 'W',cnt++;
			}
		}
	}
	for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 'W')cnt--;
			else if(arr[i][j] == 'B')cnt++;
		}
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 'U'){
				if(cnt>0)arr[i][j] = 'W',arr[i+1][j] = 'B',cnt--;
				else arr[i][j] = 'B',arr[i+1][j] = 'W',cnt++;
			}
		}
	}
	//for(auto &i:arr)cout<<i<<'\n';cout<<'\n';return;
	for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 'W')cnt++;
			else if(arr[i][j] == 'B')cnt--;
		}
		if(cnt){
			cout<<"-1\n";
			return;
		}
	}
	for(int i = 0;i<m;i++){
		int cnt = 0;
		for(int j = 0;j<n;j++){
			if(arr[j][i] == 'W')cnt++;
			else if(arr[j][i] == 'B')cnt--;
		}
		if(cnt){
			cout<<"-1\n";
			return;
		}
	}
	for(auto &i:arr)cout<<i<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
