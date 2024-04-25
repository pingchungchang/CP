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
int n;
ll f(vector<int> &arr){
	ll now = 1;
	ll h = 0;
	for(int i = 0;i<n;i++){
		h += now*arr[i];
		now *= 100;
	}
	return h;
}
int main(){
	io
	cin>>n;
	vector<int> v(n);
	queue<vector<int>> q;
	set<ll> goneto;
	int tar;
	for(int i = 0;i<n;i++)cin>>v[i];
	cin>>tar;
	for(int i = 0;i<n;i++){
		vector<int> tmp(n+1,0);
		tmp[i] = v[i];
		tmp.back() = 1;
		q.push(tmp);
		goneto.insert(f(tmp));
	}
	goneto.insert(0);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
//		for(auto i:now)cout<<i<<' ';cout<<endl;
		for(int i = 0;i<n;i++){
			if(now[i] == tar){
				cout<<now.back();
				return 0;
			}
		}
		for(int i = 0;i<n;i++){
			auto tmp = now;
			tmp[i] = 0;
			if(goneto.find(f(tmp)) == goneto.end()){
				tmp.back()++;
				goneto.insert(f(tmp));
				q.push(tmp);
			}
			tmp = now;
			tmp[i] = v[i];
			if(goneto.find(f(tmp)) == goneto.end()){
				tmp.back()++;
				goneto.insert(f(tmp));
				q.push(tmp);
			}
			for(int j = 0;j<n;j++){
				if(i == j)continue;
				tmp = now;
				if(tmp[i]+tmp[j]<=v[i]){
					tmp[i] += tmp[j];
					tmp[j] = 0;
				}
				else{
					tmp[j] -= v[i]-tmp[i];
					tmp[i] = v[i];
				}
				tmp.back()++;
				if(goneto.find(f(tmp)) == goneto.end()){
					goneto.insert(f(tmp));
					q.push(tmp);
				}
			}
		}
	}
	cout<<-1;
}

