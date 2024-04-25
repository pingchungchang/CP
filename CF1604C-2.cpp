#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	map<int,int> mp;
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<int> mv(n,INT_MAX);
	for(int i = 0;i<n;i++){
		int now = v[i];
		for(int j = i;j>=0;j--){
			if(now%(j+2) != 0){
				mv[i] = i-j;
				break;
			}
		}
		if(mp.count(mv[i]) == 0)mp[mv[i]] = 1;
		else mp[mv[i]]++;
	}
	int now = 0;
	for(auto i:mp){
//		cout<<i.fs<<' '<<i.sc<<',';
		if(now<i.fs){
			cout<<"No\n";
			return;
		}
		else{
			now += i.sc;
		}
	}
	cout<<"Yes\n";
	return;
}
int main(){
	io;
	int t;
	cin>>t;
	for(int i= 0;i<t;i++)solve();
}
