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
	int ans = k;
	if(k == 4){
		int ev = 0,od = 0;
		for(auto &i:arr){
			if(i%4 == 0){
				cout<<"0\n";
				return;
			}
			else if(i&1){
				ans = min(ans,(i+3)/4*4-i);
				od++;
			}
			else ev++;
		}
		if(ev>=2)ans = 0;
		else if(ev == 1)ans = min(ans,1);
		else ans = min(ans,2);
	}
	else{
		for(auto &i:arr){
			if(i%k == 0)ans = 0;
			ans = min(ans,k-i%k);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
