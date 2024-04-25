#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	vector<pll> arr(k);
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	for(int i = 0;i<k;i++){
		if(arr[i].fs<arr[i].sc){
			cout<<"NO\n";
			return;
		}
		else if(i != 0&&arr[i].fs-arr[i].sc<arr[i-1].fs-arr[i-1].sc){
			cout<<"NO\n";
			return;
		}
		else if(arr[i].fs>=3&&arr[i].sc<3){
			cout<<"No\n";
			return;
		}
	}
	if(n == 1){
		cout<<"YES\na\n";
		return;
	}
	else if(n == 2){
		if(k == 2)cout<<"YES\naa\n";
		else cout<<"NO\n";
		return;
	}
	char sh = 'a';
	char now = 'd';
	string s = "abc";
	reverse(arr.begin(),arr.end());
	int cnt = 3;
	while(!arr.empty()){
		while(cnt < arr.back().sc){
			s += now;
			cnt++;
		}
		while(s.size() < arr.back().fs){
			s += sh;
			sh++;
			if(sh>'c')sh = 'a';
		}
		now++;
		arr.pop_back();
	}
	cout<<"YES\n"<<s<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
