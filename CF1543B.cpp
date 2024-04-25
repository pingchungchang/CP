#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll arr[n],sum = 0;
	for(auto &i:arr){
		cin>>i;
		sum += i;
	}
	ll d = sum%n;
	for(auto &i:arr)i = sum/n;
	for(int i = 0;i<d;i++)arr[i]++;
	sort(arr,arr+n);
	ll c1 = 0,c2 = 0;
	for(auto &i:arr){
		if(i == sum/n)c1++;
		else c2++;
	}
	cout<<c1*c2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
