#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int arr[mxn];
int n,C;

void solve(){
	for(int i = 0;i<=C;i++)arr[i] = 0;
	cin>>n>>C;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[k] = 1;
	}
	for(int i = 1;i<=C;i++)arr[i] += arr[i-1];
	for(int i = 1;i<=C;i++){
		if(arr[i] == arr[i-1])continue;
		for(int j = 1;j*i<=C;j++){
			int l = i*j-1,r = min(C,i*(j+1)-1);
			if(arr[r]-arr[l] != 0){
				if(arr[j] == arr[j-1]){
					cout<<"No\n";
					return;
				}
			}
		}
	}
	cout<<"Yes\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
