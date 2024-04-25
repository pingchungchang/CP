#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-1;j++){
			if(arr[i][j] == '0')continue;
			bool flag = false;
			if(i+1<n&&arr[i+1][j] == '1')flag = true;
			if(j+1<n&&arr[i][j+1] == '1')flag = true;
			if(!flag){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
