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

set<pll> st;
int main(){
	io
	ll n,m;
	cin>>n>>m;
	ll tmp[n];
	ll arr[n];
	ll pre = -1;
	ll cnt= 0;
	ll total = n*(n+1)*(n+2)/6;
	for(int i = 0;i<n;i++)arr[i] = i;
	for(int i = 0;i<n;i++){
		cin>>tmp[i];
		ll p = i,v = tmp[i];
		ll ta,tb;
		if(p != 0&&arr[p] == arr[p-1])ta = 1;
		else ta = 0;
		if(p != n-1&&arr[p] == arr[p+1])tb = 1;
		else tb = 0;
//		cout<<i<<' '<<ta<<tb<<' '<<total<<endl;
//		for(int j = 0;j<n;j++)cout<<arr[j]<<' ';cout<<endl;
		if(p != 0&&v == arr[p-1]&&ta == 0){
			total -= p*(n-p);
		}
		else if(p != 0&&v != arr[p-1]&&ta == 1){
			total += p*(n-p);
		}
		if(p <n-1&&v == arr[p+1]&&tb == 0){
			total -= (p+1)*(n-p-1);
		}
		else if(p<n-1&&v != arr[p+1]&&tb == 1){
			total += (p+1)*(n-p-1);
		}
		arr[p] = v;
	}
//	cout<<total<<endl;
	while(m--){
		ll p,v;
		cin>>p>>v;
		p--;
		ll ta,tb;
		if(p != 0&&arr[p] == arr[p-1])ta = 1;
		else ta = 0;
		if(p <n-1&&arr[p] == arr[p+1])tb = 1;
		else tb = 0;
		if(p != 0&&v == arr[p-1]&&ta == 0){
			total -= p*(n-p);
		}
		else if(p != 0&&v != arr[p-1]&&ta == 1){
			total += p*(n-p);
		}
		if(p <n-1&&v == arr[p+1]&&tb == 0){
			total -= (p+1)*(n-p-1);
		}
		else if(p<n-1&&v != arr[p+1]&&tb == 1){
			total += (p+1)*(n-p-1);
		}
		arr[p] = v;
//		for(auto j:arr)cout<<j<<' ';
		cout<<total<<'\n';
	}
	return 0;
}

