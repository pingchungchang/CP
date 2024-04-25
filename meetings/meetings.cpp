#include "meetings.h"
#include <bits/stdc++.h>
using namespace std;

/*
  int x = Query(0, 1, 2);
    Bridge(u, u + 1);
*/

const int mxn = 2020;
set<int> tree[mxn];
int sz[mxn];
vector<int> perm;
bitset<mxn> done;
bitset<mxn> del;
int N;

int ask(int a,int b,int c){
	//assert(a != b&&b!=c&&c != a);
	return Query(a,b,c);
}
void add_edge(int a,int b){
	//assert(a != b);
	tree[a].insert(b);
	tree[b].insert(a);
	cerr<<"ADD:"<<a<<' '<<b<<endl;
}

void del_edge(int a,int b){
	cerr<<"DEL:"<<a<<' '<<b<<endl;
	//assert(tree[a].find(b) != tree[a].end());
	tree[a].erase(b);
	tree[b].erase(a);
}

void szdfs(int now,int par){
	sz[now] = 1;
	for(auto nx:tree[now]){
		if(del[nx]||nx==par)continue;
		szdfs(nx,now);
		sz[now] += sz[nx];
	}
	return;
}

int get_centroid(int now,int par,int tar){
	for(auto nxt:tree[now]){
		if(nxt == par||del[nxt])continue;
		if(sz[nxt]>tar)return get_centroid(nxt,now,tar);
	}
	return now;
}

void calc(int now,int tar){
	szdfs(now,now);
	cerr<<"CALC:"<<now<<' '<<tar<<' '<<sz[now]<<endl;
	if(sz[now] == 1){
		add_edge(now,tar);
		return;
	}
	else if(sz[now] == 2){
		int nx;
		for(auto &i:tree[now])if(!del[i])nx = i;
		int r = ask(now,nx,tar);
		if(r == tar){
			del_edge(now,nx);
			add_edge(tar,now);
			add_edge(tar,nx);
		}
		else if(r == nx||r == now){
			add_edge(r,tar);
		}
		else{
			done[r] = true;
			del_edge(now,nx);
			add_edge(now,r);
			add_edge(r,nx);
			add_edge(r,tar);
		}
		return;
	}
	now = get_centroid(now,now,(sz[now]-1)/2);
	vector<int> ch;
	for(auto nxt:tree[now]){
		if(del[nxt])continue;
		ch.push_back(nxt);
	}
	del[now] = true;
	for(int i = 1;i<ch.size();i+=2){
		int a = ch[i-1],b = ch[i];
		int r = ask(a,b,tar);
		if(r == now)continue;
		else if(r == a)calc(a,tar);
		else if(r == b)calc(b,tar);
		else if(r == tar){
			int tmp = ask(now,a,tar);
			if(tmp == now){
				del_edge(now,b);
				add_edge(now,tar);
				if(now == tar)cout<<"ERROR"<<endl;
				add_edge(tar,b);
				if(tar == b)cout<<"ERROR"<<endl;
			}
			else{
				del_edge(now,a);
				add_edge(now,tar);
				if(now == tar)cout<<"ERROR"<<endl;
				add_edge(tar,a);
				if(tar == a)cout<<"ERROR"<<endl;
			}
		}
		else{
			int tmp = ask(now,r,a);
			if(tmp == now){
				done[r] = true;
				del_edge(now,b);
				add_edge(now,r);
				if(now == r)cout<<"ER"<<endl;
				add_edge(r,b);
				if(r == b)cout<<"R"<<endl;
				add_edge(r,tar);
				if(r == tar)cout<<"R"<<endl;
			}
			else{
				done[r] = true;
				del_edge(now,a);
				add_edge(now,r);
				if(now == r)cout<<"ER"<<endl;
				add_edge(r,a);
				if(r == b)cout<<"R"<<endl;
				add_edge(r,tar);
				if(r == tar)cout<<"R"<<endl;
			}
		}
		return;
	}
	if(ch.size()&1){
		auto a = ch.back();
		int r = ask(now,a,tar);
		if(r == now){
			add_edge(now,tar);
		}
		else if(r == tar){
			del_edge(now,a);
			add_edge(now,tar);
			add_edge(tar,a);
		}
		else if(r == a)calc(a,tar);
		else{
			done[r] = true;
			del_edge(now,a);
			add_edge(now,r);
			assert(now != r);
			add_edge(r,a);
			assert(r != a);
			add_edge(r,tar);
			assert(r != tar);
		}
		return;
	}
	add_edge(now,tar);
	assert(now != tar);
	return;
}

void addpt(int tar){
	del.reset();
	calc(0,tar);
	done[tar] = true;
}
void answer(){
	for(int i = 0;i<N;i++){
		for(auto nx:tree[i]){
			if(nx>i)Bridge(i,nx);
		}
	}
	return;
}
void print(){
	for(int i = 0;i<N;i++){
		for(auto nx:tree[i]){
			if(nx>i)cout<<i<<":"<<nx<<endl;
		}
	}
	return;
}

void Solve(int NN) {
	N = NN;
	srand(time(NULL));
	for(int i = 0;i<N;i++)perm.push_back(i);
	//random_shuffle(perm.begin(),perm.end());
	done[0] = true;
	for(auto &i:perm)if(!done[i])addpt(i);
	//print();
	answer();
	cerr<<"HI"<<endl;
	return;
}
