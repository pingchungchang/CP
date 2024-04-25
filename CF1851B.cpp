#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> od,ev;
	int arr[n];
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		if(k&1)od.push_back(k);
		else ev.push_back(k);
	}
	sort(od.rbegin(),od.rend());
	sort(ev.rbegin(),ev.rend());
	for(auto &i:arr){
		if(i&1)i = od.back(),od.pop_back();
		else i = ev.back(),ev.pop_back();
	}
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
