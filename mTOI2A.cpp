#include <bits/stdc++.h>
using namespace std;

struct node{
	int par;
	int nums;
	int id;
	node(){
		par = 0;
		nums = 0;
		id = 0;
	}
	node(int k,int j){
		par = k;
		id = j;
		nums = 0;
	}
};
vector<node> gps;
vector<int> v;
int n,t;
map<int,int> mp;
int findroot(int now){
	while(gps[now].par != now){
		gps[now].par = gps[gps[now].par].par;
		now = gps[now].par;
	}
	return now;
}
void f1(){
	int x,y;
	cin>>x>>y;
	if(findroot(v[x]) == findroot(v[y]))return;
	else{
		int rx = findroot(v[x]);
		int ry = findroot(v[y]);
		gps[ry].nums += gps[rx].nums;
		gps[rx].nums = 0;
		gps[rx].par = ry;
	}
	mp.erase(v[x]);
}

void f2(){
	int x,y;
	cin>>x>>y;
	gps[findroot(v[x])].nums--;
	gps[findroot(v[y])].nums++;
	v[x] = findroot(v[y]);
	return;
}

void f3(){
	int x,p;
	cin>>x>>p;
	if(mp.count(p) == 0){
		mp[p] = gps.size();
		gps.push_back(node(gps.size(),p));
	}
	int pos = mp[p];
	gps[findroot(v[x])].nums--;
	v[x] = pos;
	gps[pos].nums++;	
	return;
}
void f4(){
	int x;
	cin>>x;
	int rx = findroot(v[x]);
	cout<<gps[rx].id<<' '<<gps[rx].nums<<'\n';
	return;
}
void f5(){
	int p;
	cin>>p;
	if(mp.count(p) == 0)cout<<0<<'\n';
	else{
		int pos = mp[p];
		cout<<gps[pos].nums<<'\n';
	}
	return;
}
void print(){
	for(int i = 1;i<=n;i++)cout<<gps[findroot(v[i])].id<<' ';
	cout<<'\n';
	return;
}
void solve(){
	int k;
	cin>>k;
	if(k == 1)f1();
	else if(k == 2)f2();
	else if(k == 3)f3();
	else if(k == 4)f4();
	else f5();
	for(auto it:mp)cout<<it.first<<' '<<it.second<<',';
	cout<<'\n';
	print();
	
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	for(int i = 0;i<5;i++)cin>>n;
	cin>>n>>t;
	gps = vector<node>(n+1);
	v = vector<int>(n+1);
	for(int i = 0;i<=n;i++){
		gps[i].id = i;
		gps[i].par = i;
	}
	for(int i = 0;i<=n;i++)mp[i] = i;
	for(int i =1;i<=n;i++){
		cin>>v[i];
		gps[v[i]].nums++;
	}
	for(int i = 0;i<t;i++)solve();
	print();
}
