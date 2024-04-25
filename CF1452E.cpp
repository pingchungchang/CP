#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int suf[m+1] = {};
	pii arr[m];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	sort(arr,arr+m,[](pii &a,pii &b){
			return a.fs+a.sc<b.fs+b.sc;
	});
	for(int i = 1;i<=n-k+1;i++){
		int sum = 0;
		for(int j = m-1;j>=0;j--){
			sum += max(0,min(i+k-1,arr[j].sc)-max(i-1,arr[j].fs-1));
			suf[j] = max(suf[j],sum);
		}
	}
	for(int j = m-1;j>=0;j--)suf[j] = max(suf[j],suf[j+1]);
	int ans = 0;
	for(int i = 1;i<=n-k+1;i++){
		int sum = 0;
		for(int j = 0;j<m;j++){
			sum += max(0,min(i+k-1,arr[j].sc)-max(i-1,arr[j].fs-1));
			ans = max(ans,sum+suf[j+1]);
		}
	}
	cout<<ans;
}
