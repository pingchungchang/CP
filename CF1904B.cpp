#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n;
	cin>>n;
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		arr[i].sc = i;
	}
	sort(arr,arr+n);
	int ans[n] = {};
	int pt = 0;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		while(pt<=i){
			sum += arr[pt++].fs;
		}
		while(pt<n&&sum>=arr[pt].fs){
			sum += arr[pt++].fs;
		}
		ans[arr[i].sc] = pt-1;
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
