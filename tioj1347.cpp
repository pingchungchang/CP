#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double
#define al3 array<int,3>
#define tiii tuple<int,int,int>

const int mxn = 1e6+10;
ll A[mxn],L[mxn];
deque<array<int,3>> dq;
ld dp[mxn];
int N,K;
short P;

inline char readchar(){
	const int S = 1<<16;
	static char buf[S],*p=buf,*q=buf;
	return p == q and (q = (p = buf)+fread(buf,1,S,stdin)) == buf?EOF:*p++;
}

inline int R(){
	int ans = 0;char c = readchar();bool minus = false;
	while((c<'0' or c>'9')and c != '-' and c != EOF)c = readchar();
	if(c == '-')minus = true,c = readchar();
	while(c>='0' and c<='9')ans = ans*10+(c^'0'),c = readchar();
	return minus?-ans:ans;
}

inline ld pw(ld a){
	ld re = 1;
	short p = P;
	while(p){
		if(p&1)re *= a;
		a *= a;
		p>>=1;
	}
	return re;
}

inline ld calc(int a,int b){
	return (ld)pw((ld)abs(A[b]-A[a]-L[a+1]-K))+dp[a];
}

int intersect(int a,int b,int l,int r){
	if(r<l)return l;
	r++;
	while(l != r){
		int mid = (l+r)>>1;
		if(calc(b,mid)>=calc(a,mid))l = mid+1;
		else r = mid;
	}
	if(calc(b,l)>=calc(a,l))return r+1;
	else return l;
}

main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	N = R();K = R();P = R();
	for(int i = 1;i<=N;i++){
		A[i] = R();
	}
	for(int i = 2;i<=N;i++)L[i] = R(),A[i] += A[i-1]+L[i];
	dq.push_back(al3({0,0,N}));
	for(int i = 1;i<=N;i++){
		while(!dq.empty()&&dq[0][2]<i)dq.pop_front();
		dp[i] = calc(dq[0][0],i);
		int pre = dq.back()[2];
		while(!dq.empty()){
			if(dq.back()[1]>i&&calc(dq.back()[0],dq.back()[1])>=calc(i,dq.back()[1])){
				pre = dq.back()[1];
				dq.pop_back();
			}
			else{
				pre = intersect(dq.back()[0],i,i+1,N);
				break;
			}
		}
		if(!dq.empty())dq.back()[2] = pre-1;
		if(pre<=N)dq.push_back(al3({i,pre,N}));
	}
	cout<<(ll)dp[N];
}
