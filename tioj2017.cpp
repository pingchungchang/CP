#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
ll arr[mxn],rpos[mxn];
int n;
deque<int> dq;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	ll ans = 0;
	for(int i = n;i>=0;i--){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		if(!dq.empty()){
			ans += n-dq.back()+1;
		}
		dq.push_back(i);
	}
	cout<<ans;
}
