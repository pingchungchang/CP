#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n],brr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	int ans[n] = {};
	for(int i = 0;i<n;i++){
		int a = arr[i],b = brr[i],c = 0;
		if(a == 0&&b == 0)ans[i]|=(1<<10)-1;
		else if(a == 0)ans[i]|=1<<0;
		else if(b == 0)ans[i]|=1<<1;
		if(a == 0||b == 0){
			continue;
		}
		while(true){
			while(a<b*2){
				//cout<<a<<' '<<b<<endl;
				if(a == 0){
					break;
				}
				c++;
				swap(a,b);
				b = abs(a-b);
			}
			//cout<<a<<' '<<b<<endl;
			if(a == 0)break;
			if(b == 0){
				c++;
				break;
			}
			a %= b*2;
		}
		ans[i]|=1<<(c%3);
	}
	for(int i = 1;i<n;i++)ans[i]&=ans[i-1];
	if(ans[n-1])cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
