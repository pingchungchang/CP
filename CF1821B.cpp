#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	int l = n,r = -1;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]){
			l = min(l,i);
			r = max(r,i);
		}
	}
	if(l>r){
		int cnt = 1,pre = 0,ans = 0;
		int l = 0,r = 0;
		for(int i = 0;i<n;i++){
			if(b[i]>=b[pre])cnt++;
			else cnt = 1;
			pre = b[i];
			if(cnt>ans){
				ans = cnt;
				l = i-cnt+1;
				r = i;
			}
		}
		cout<<l+1<<' '<<r+1<<'\n';
		return;
	}
	while(l>0){
		l--;
		if(b[l]>b[l+1]){
			l++;
			break;
		}
	}
	while(r<n-1){
		r++;
		if(b[r]<b[r-1]){
			r--;
			break;
		}
	}
	cout<<l+1<<' '<<r+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
