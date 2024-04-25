#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

int n,k,l;

void solve(){
	cin>>n>>k>>l;
	int arr[n];
	for(auto &i:arr)cin>>i;
	vector<pii> alive[n];
	for(int i = 0;i<n;i++){
		int big = l-arr[i];
		if(big>=k)alive[i].push_back({0,k*2-1});
		else{
			alive[i].push_back({0,big});
			if(big>0)alive[i].push_back({2*k-big,2*k-1});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
