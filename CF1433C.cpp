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
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int big = *max_element(_all(v));
	for(int i = 0;i<n;i++){
		if(i == 0&&v[i+1]<v[i]&&v[i] == big){
			cout<<i+1<<'\n';
			return;
		}
		else if(i == n-1&&v[i]>v[i-1]&&v[i] == big){
			cout<<i+1<<'\n';
			return;
		}
		else if(i != n-1&&i != 0&&v[i] == big&&(v[i]>v[i-1]||v[i]>v[i+1])){
//			cout<<v[i-1]<<' '<<v[i]<<' '<<v[i+1]<<",";
			cout<<i+1<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

