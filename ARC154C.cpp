#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> a,b;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		a.push_back(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(b.empty()||b.back() != k)b.push_back(k);
	}
	while(b.size()>1&&b.back() == b[0])b.pop_back();
	if(a.size() == b.size()){
		for(int i = 0;i<n;i++){
			if(a[i] != b[i]){
				cout<<"No\n";
				return;
			}
		}
		cout<<"Yes\n";
		return;
	}
	for(int i = 0;i<n;i++)a.push_back(a[i]);
	for(int i = 0;i<n;i++){
		int p = 0;
		for(int j = 0;j<n;j++){
			if(p != b.size()&&a[i+j] == b[p])p++;
		}
		if(p == b.size()){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
