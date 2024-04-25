#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int num[26] = {};
	for(auto &i:s)num[i-'a']++;
	int n;
	cin>>n;
	int arr[n];
	int cnt[n] = {};
	string ans(n,'#');
	for(auto &i:arr)cin>>i;
	for(int idx = 25;idx>=0;idx--){
		vector<int> v;
		for(int i = 0;i<n;i++){
			if(ans[i] != '#')continue;
			if(arr[i] == cnt[i]){
				v.push_back(i);
			}
		}
		for(int i = 0;i<n;i++){
			if(ans[i] == '#'){
				for(auto &j:v){
					cnt[i] += abs(i-j);
				}
			}
		}
		//cout<<idx<<' '<<v.size()<<endl;
		while(v.size()>num[idx])idx--;
		for(auto &i:v)ans[i] = idx+'a';
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
