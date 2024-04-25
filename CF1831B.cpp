#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n],brr[n];
	map<int,int> ma,mb;
	int pre = -1;
	int cnt = 0;
	for(auto &i:arr){
		cin>>i;
		if(pre == i)cnt++;
		else cnt = 1;
		pre = i;
		ma[i] = max(cnt,ma[i]);
	}
	pre =-1,cnt = 0;
	for(auto &i:brr){
		cin>>i;
		if(pre == i)cnt++;
		else cnt = 1;
		pre = i;
		mb[i] = max(cnt,mb[i]);
	}
	int ans = 0;
	for(auto &i:ma){
		ans = max(ans,i.sc+mb[i.fs]);
	}
	for(auto &i:mb)ans = max(ans,i.sc+ma[i.fs]);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
