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
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		arr[i] = -arr[i];
		int c1 = 0,c2 = 0;
		for(int j = 1;j<n;j++){
			if(arr[j]-arr[j-1]>=0)c1++;
			if(arr[j]-arr[j-1]<=0)c2++;
		}
		if(c1>=n/2&&c2>=n/2){
			for(auto &j:arr)cout<<j<<' ';cout<<'\n';
			return;
		}
	}
	assert(false);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
