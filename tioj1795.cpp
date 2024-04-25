#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int big = 0;
int small = 0;
int dsjset[(int)1e5+5];
int findpar(int n){
	while(dsjset[n] != n){
		dsjset[n] = dsjset[dsjset[n]];
		n = dsjset[n];
	}
	return n;
}
int main(){
	io
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,less<pair<int,pair<int,int>>>> pq1;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		pq.push(make_pair(c,make_pair(a,b)));
	}
	for(int i = 0;i<n;i++)dsjset[i] = i;
	while(!pq.empty()){
		int a = pq.top().sc.fs;
		int b = pq.top().sc.sc;
		int c= pq.top().fs;
		pq1.push(pq.top());
		pq.pop();
		a = findpar(a);
		b = findpar(b);
		if(a == b)continue;
		dsjset[a] = b;
		small += c;
	}
	for(int i = 0;i<n;i++)dsjset[i] = i;
	while(!pq1.empty()){
		int a = pq1.top().sc.fs;
		int b = pq1.top().sc.sc;
		int c= pq1.top().fs;
		pq1.pop();
		a = findpar(a);
		b = findpar(b);
		if(a == b)continue;
		dsjset[a] = b;
		big += c;
	}
	if(k<=big&&k>=small)cout<<"TAK";
	else cout<<"NIE";
}

