#include "seats.h"
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int big = 1010;
const int mxn = 1e6+10;

struct SEG{
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)
	struct node{
		int mn,tag,cnt;
		node(){}
	};
	node seg[mxn*4];
	void build(int now,int l,int r){
		if(l == r){
			seg[now].cnt = 1;
			return;
		}
		build(ls,l,mid);build(rs,mid+1,r);
		seg[now].cnt = seg[ls].cnt+seg[rs].cnt;
	}
	void modify(int now,int l,int r,int s,int e,int v){
		if(s>e)return;
		if(l>=s&&e>=r){
			seg[now].tag += v;
			return;
		}
		if(mid>=s)modify(ls,l,mid,s,e,v);
		if(mid<e)modify(rs,mid+1,r,s,e,v);
		seg[now].mn = min(seg[ls].tag+seg[ls].mn,seg[rs].tag+seg[rs].mn);
		seg[now].cnt = 0;
		if(seg[ls].tag+seg[ls].mn == seg[now].mn)seg[now].cnt += seg[ls].cnt;
		if(seg[rs].tag+seg[rs].mn == seg[now].mn)seg[now].cnt += seg[rs].cnt;
		return;
	}
#undef ls
#undef rs
#undef mid
};

SEG seg;
vector<vector<int>> grid;
pii pos[mxn];
int N,M;

void add(int r,int c,int coef = 1){
	vector<int> v = {grid[r][c],grid[r][c+1],grid[r+1][c],grid[r+1][c+1]};
	sort(v.begin(),v.end());
	seg.modify(0,0,N*M-1,v[0],v[1]-1,coef);
	seg.modify(0,0,N*M-1,v[2],v[3]-1,big*coef);
	return;
}

int getans(){
	int cnt = seg.seg[0].cnt,val = seg.seg[0].mn+seg.seg[0].tag;
	if(val != 4)return 0;
	else return cnt;
}

void give_initial_chart(int H, int W, std::vector<int> R, std::vector<int> C) {
	N = H,M = W;
	grid = vector<vector<int>>(N+2,vector<int>(M+2,N*M));
	seg.build(0,0,N*M-1);
	for(int i = 0;i<N*M;i++){
		pos[i] = pii(R[i],C[i]);
		pos[i].fs++;
		pos[i].sc++;
		grid[pos[i].fs][pos[i].sc] = i;
	}
	for(int i = 0;i<=N;i++){
		for(int j = 0;j<=M;j++){
			add(i,j,1);
		}
	}
	return;
}

int swap_seats(int a, int b) {
	pii pa = pos[a],pb = pos[b];
	for(int i = -1;i<1;i++){
		for(int j = -1;j<1;j++){
			add(pa.fs+i,pa.sc+j,-1);
			add(pb.fs+i,pb.sc+j,-1);
		}
	}
	swap(pos[a],pos[b]);
	swap(grid[pa.fs][pa.sc],grid[pb.fs][pb.sc]);
	for(int i = -1;i<1;i++){
		for(int j = -1;j<1;j++){
			add(pa.fs+i,pa.sc+j,1);
			add(pb.fs+i,pb.sc+j,1);
		}
	}
	return getans();
}
