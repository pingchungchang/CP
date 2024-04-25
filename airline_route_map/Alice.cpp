#include "Alicelib.h"
#include <cassert>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;


const int mxn = 1020;
const int H = 10;
/*
	InitG( 3, 2 );
	MakeG( 1, 2 );
*/
#define pii pair<int,int>
#define fs first
#define sc second

namespace ALICE{
	vector<pair<int,int>> edges;
	void GO(int N,int M,int A[],int B[]){
		for(int i = 0;i<M;i++){
			edges.push_back({A[i],B[i]});
		}
		for(int i = 0;i<H;i++){
			for(int j = 0;j<N;j++){
				if(j&(1<<i)){
					edges.push_back({j,N+i});
				}
			}
			if(i)edges.push_back({N+i-1,N+i});
			edges.push_back({N+i,N+H});
		}
		for(int i = 0;i<N+H;i++){
			edges.push_back({i,N+H+1});
		}
		InitG(N+H+2,edges.size());
		int pt = 0;
		//cerr<<"ALICE:"<<endl;
		for(auto &i:edges){
			//cerr<<i.fs<<' '<<i.sc<<endl;
		}
		//cerr<<endl;
		for(auto &i:edges)MakeG(pt++,i.fs,i.sc);
		return;
	}
}

void Alice( int N, int M, int A[], int B[] ){
	ALICE::GO(N,M,A,B);
}

