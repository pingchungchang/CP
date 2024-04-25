#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n+1];
	vector<int> v;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		v.push_back(i);
	}
	int ans = 0;
	for(int i = 30;i>=k;i--){
		int cnt = 0;
		for(auto &j:v){
			if((1<<i)&arr[j])cnt++;
		}
		if(cnt>=2){
			ans |= 1<<i;
			vector<int> vv;
			for(auto &j:v){
				if((1<<i)&arr[j])vv.push_back(j);
			}
			swap(vv,v);
		}
	}
	vector<vector<int>> check;
	check.push_back(v);
	for(int i = k-1;i>=0;i--){
		vector<vector<int>> tmp;
		bool flag = false;
		for(auto &j:check){
			vector<int> v1,v2;
			for(auto &jj:j){
				if((1<<i)&arr[jj])v2.push_back(jj);
				else v1.push_back(jj);
			}
			if(v1.size()>=2||v2.size()>=2)flag = true;
			if(v1.size()>=2)tmp.push_back(v1);
			if(v2.size()>=2)tmp.push_back(v2);
		}
		if(flag)swap(tmp,check);
	}
	int a = check[0][0],b = check[0][1];
	ans = 0;
	for(int i = 0;i<k;i++){
		int ta = arr[a]&(1<<i),tb = arr[b]&(1<<i);
		if(ta == tb){
			if(!ta)ans|=(1<<i);
		}
	}
	cout<<a<<' '<<b<<' '<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
