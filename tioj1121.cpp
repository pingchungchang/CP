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

void solve(int n){
	string s;
	cin>>s;
	pair<deque<char>,int> v[n];
	for(auto &i:s)v[0].fs.push_back(i);
	v[0].sc = 1;
	for(int i= 1;i<n;i++){
		v[i].fs = v[i-1].fs;
		v[i].fs.push_back(v[i].fs.front());
		v[i].fs.pop_front();
		v[i].sc = i+1;
	}
	sort(v,v+n);
	int re = 0;
	for(int i = 0;i<n;i++){
		if(v[i].sc == 2)re = i+1;
		cout<<v[i].fs.back();
	}
	cout<<"\n"<<re<<'\n';
	return;
}
int main(){
	int n;
	while(cin>>n)solve(n);
}

