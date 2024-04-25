#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int cnt[2] = {};
	ll ans[2] = {};
	int n;
	cin>>n;
	int arr[n];
	cnt[0] = 1;
	int sum  =0;
	for(auto &i:arr){
		cin>>i;
		if(i>0)i = 0;
		else i = 1;
		sum ^= i;
		ans[1] += cnt[sum^1];
		ans[0] += cnt[sum];
		cnt[sum]++;
	}
	cout<<ans[1]<<' '<<ans[0];
}
