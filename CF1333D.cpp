#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

set<int> st,st2;
int n,k;
string s;

inline void check(int id){
	if(id>=n||id<=0)return;
	if(s[id+1] == 'L'&&s[id] == 'R')st2.insert(id);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>s;
	int kk = k;
	s = "#"+s;
	vector<vector<int>> v;
	for(int i = 1;i<n;i++){
		check(i);
	}
	swap(st2,st);
	int sum = 0;
	while(!st.empty()){
		v.push_back({});
		st2.clear();
		for(auto &i:st){
			s[i] = 'L';
			s[i+1] = 'R';
			check(i-1);
			check(i);
			check(i+1);
			v.back().push_back(i);
			sum++;
		}
		swap(st2,st);
	}
	//cout<<sum<<endl;
	for(auto &i:v){
		//for(auto &j:i)cout<<j<<' ';cout<<endl;
	}
	if(v.size()>k||sum<k){
		if(v.size()>k)cout<<-1;
		else cout<<-1;
		return 0;
	}
	vector<vector<int>> ans;
	for(int i = 0;i<v.size();i++){
		if(v[i].empty())continue;
		if(v.size()-i == k){
			ans.push_back(v[i]);
			k--;
			continue;
		}
		ans.push_back({v[i].back()});
		v[i].pop_back();
		k--;
		i--;
	}
	assert(ans.size() == kk);
	for(auto &i:ans){
		cout<<i.size()<<' ';for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	return 0;
}
