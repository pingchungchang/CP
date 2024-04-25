#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	s += '<';
	int arr[n] = {},brr[n] = {};
	for(int i = 0;i<n;i++)arr[i] = i+1;
	int pre = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '<'){
			reverse(arr+pre,arr+i+1);
			pre = i+1;
		}
	}
	for(int i = 0;i<n;i++)brr[i] = n-i;
	pre = 0;
	s.back() = '>';
	for(int i = 0;i<n;i++){
		if(s[i] == '>'){
			if(pre != -1)reverse(brr+pre,brr+i+1);
			pre = i+1;
		}
	}
	for(auto &i:brr)cout<<i<<' ';cout<<'\n';
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
