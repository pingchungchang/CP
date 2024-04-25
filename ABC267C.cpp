#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	int n,m;
	cin>>n>>m;
	ll total = 0,ans = INT_MIN;
	ll arr[n];
	ll sum = 0;
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<m;i++){
		total += (i+1)*arr[i];
		sum += arr[i];
	}
	ans = total;
	for(int i = 1;i<=n-m;i++){
		total -= sum;
		total += m*arr[m+i-1];
		sum -= arr[i-1];
		sum += arr[m+i-1];
		ans = max(ans,total);
//		cout<<i<<' '<<total<<endl;
	}
	cout<<ans;
}

