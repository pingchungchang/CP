#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(k != 1){
		cout<<"YES\n";
		return;
	}
	else{
		for(int i = 1;i<n;i++){
			if(arr[i]<arr[i-1]){
				cout<<"NO\n";
				return;
			}
		}
		cout<<"YES\n";
		return;
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
