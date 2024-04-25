#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int inf = 1e9;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	pii sm = {inf,0};
	for(int i = 0;i<n;i++){
		sm = min(sm,make_pair(arr[i],i));
	}
	for(int i = sm.sc+1;i<n;i++){
		if(arr[i]<arr[i-1]){
			cout<<"-1\n";
			return;
		}
	}
	cout<<sm.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
