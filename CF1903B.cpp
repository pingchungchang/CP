#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int arr[mxn][mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)cin>>arr[i][j];
	int ans[n];
	for(int i = 0;i<n;i++){
		ans[i] = (1<<30)-1;
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			ans[i] &= arr[i][j];
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			if((ans[i]|ans[j]) != arr[i][j]){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
