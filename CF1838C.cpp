#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1010;
int arr[mxn][mxn];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			arr[i][j] = 0;
		}
	}
	int p = 0;
	if(m%2 == 0){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++)arr[i][j] = ++p;
		}
	}
	else if(n%2 == 0){
		for(int i = 0;i<m;i++){
			for(int j = 0;j<n;j++)arr[j][i] = ++p;
		}
	}
	else{
		vector<int> od,ev;
		for(int i = 1;i<n*m;i+=m){
			if(i&1)od.push_back(i);
			else ev.push_back(i);
		}
		int c = 0;
		for(int i = od.size()-1;i>=0;i--){
			for(int j = 0;j<m;j++){
				arr[c][j] = od[i]+j;
			}
			c++;
		}
		for(int i = ev.size()-1;i>=0;i--){
			for(int j = 0;j<m;j++){
				arr[c][j] = ev[i]+j;
			}
			c++;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<arr[i][j]<<' ';cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
