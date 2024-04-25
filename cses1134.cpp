#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


map<int,int> mp;
set<int> st;
vector<pii> ans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n-2];
	for(auto &i:arr)cin>>i,mp[i]++;
	for(int i = 1;i<=n;i++){
		if(mp.find(i) == mp.end())st.insert(i);
	}
	for(auto &i:arr){
		int mex = *st.begin();
		st.erase(mex);
		ans.push_back({mex,i});
		mp[i]--;
		if(mp[i] == 0){
			mp.erase(i);
			st.insert(i);
		}
	}
	ans.push_back({*st.begin(),*st.rbegin()});
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
