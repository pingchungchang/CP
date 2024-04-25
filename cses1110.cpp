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
#pragma GCC optimize("O3")
int n;
int r;
const int mxn = 1e6+10;
vector<pair<pii,int>> buckets[mxn];
void bucket_sort(int rnk[],int d){
	vector<pair<pii,int>> v(n);
	for(auto &i:buckets)i.clear();
	for(int i = 0;i<n;i++){
		v[i].fs.fs = rnk[i];
		if(i+d>=n){
			v[i].fs.sc = rnk[i+d-n];
		}
		else v[i].fs.sc = rnk[i+d];
		v[i].sc = i;
	}
	for(int i = 0;i<n;i++){
		buckets[v[i].fs.sc].push_back(v[i]);
	}
//	for(auto &i:v)cout<<i.fs.fs<<' '<<i.fs.sc<<',';
	int cnt = 0;
	for(int i = 0;i<r;i++){
		for(auto &j:buckets[i]){
			v[cnt++] = j;
		}
	}
	for(auto &i:buckets)i.clear();
	for(int i =0;i<n;i++){
		buckets[v[i].fs.fs].push_back(v[i]);
	}
//	return;
	cnt = -1;
	pair<pii,int> pre = {{-1,-1},-1};
	for(int i = 0;i<r;i++){
		for(auto &j:buckets[i]){
			if(pre.sc != -1&&pre.fs.fs == j.fs.fs&&pre.fs.sc == j.fs.sc){
				rnk[j.sc] = cnt;
			}
			else{
				rnk[j.sc] = ++cnt;
				pre = j;
			}
		}
	}
	return;
}
int main(){
	io
	string s;
	cin>>s;
	n = s.size();
	r = max(27,n);
	int rnk[n] = {};
	vector<int> all;
	for(int i = 0;i<n;i++){
		rnk[i] = s[i]-'a';
	}
	for(int i = 1;i<n;i<<=1){
//		for(auto i:rnk)cout<<i<<' ';cout<<endl;
		bucket_sort(rnk,i);
	}
	pii ans = {INT_MAX,INT_MAX};
	for(int i = 0;i<n;i++){
		ans = min(ans,{rnk[i],i});
	}
	string re = s.substr(ans.sc,n-ans.sc);
	for(int i = 0;i<ans.sc;i++)re += s[i];
	cout<<re;
}

