#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	set<int> st;
	for(int i = 1;i<=n;i++)st.insert(i);
	for(auto &i:arr){
		cin>>i;
		if(i)st.erase(i),i = i&1;
		else i = -1;
	}
	if(st.size() == n){
		if(n == 1)cout<<"0\n";
		else cout<<1<<'\n';
		return 0;
	}
	vector<pii> v[3];
	vector<pii> vv;vv.push_back({0,0});
	for(int i = 1;i<n;i++){
		if(arr[i] == -1)vv.back().sc = i;
		else{
			vv.back().sc = i;
			vv.push_back({i,i});
		}
	}
	vector<pii> sp[2];
	for(auto &i:vv){
		if(i.fs == i.sc)continue;
		if(arr[i.fs] == -1){
			sp[arr[i.sc]&1].push_back({1,i.sc-i.fs});
		}
		else if(arr[i.sc] == -1){
			sp[arr[i.fs]&1].push_back({1,i.sc-i.fs});
		}
		else if(arr[i.fs] == arr[i.sc])v[arr[i.fs]&1].push_back({2,i.sc-i.fs-1});
		else v[2].push_back({1,i.sc-i.fs-1});
	}
	for(auto &i:sp)sort(i.begin(),i.end());

	/*
	for(auto &i:vv)cout<<i.fs<<','<<i.sc<<';';
	cout<<endl;
	for(int i = 0;i<3;i++){for(auto &j:v[i])cout<<j.sc*100+j.fs<<' ';cout<<endl;}
   */
	int cnt[2] = {(n)>>1,(n+1)>>1};
	int ans = 0;
	for(auto &i:arr)if(i != -1)cnt[i]--;
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	for(auto &i:v[0]){
		if(i.sc<=cnt[0]){
			cnt[0] -= i.sc;
		}
		else ans+=i.fs;
	}
	for(auto &i:v[1]){
		if(i.sc<=cnt[1])cnt[1] -= i.sc;
		else ans += i.fs;
	}
	for(auto &i:sp[0]){
		if(i.sc<=cnt[0])cnt[0]-=i.sc;
		else ans += i.fs;
	}
	for(auto &i:sp[1]){
		if(i.sc<=cnt[1])cnt[1]-=i.sc;
		else ans += i.fs;
	}
	ans += v[2].size();
	cout<<ans;
}
