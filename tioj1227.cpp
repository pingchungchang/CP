#include <bits/stdc++.h>
#include "lib1227.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll mxn = 1e6+10;
ll diff[mxn];
ll arr[mxn];
int n;
bool flag = false;
void init(int N, long long D[]){
	n = N;
	for(int i = 0;i<n;i++)arr[i] = D[i];
	return;
}

void change(int a, int b, long long k){
	int es,ee,os,oe;
	if(a == b){
		arr[a] -= k;
		return;
	}
	diff[a] -= k;
	diff[a+1] += k;
	if((b-a+1)&1){
		diff[b+2] += k;
		diff[b+1] -= k;
	}
	else{
		diff[b+2] -= k;
		diff[b+1] += k;
	}
//	for(int i = 0;i<n;i++)cout<<diff[i]<<' ';cout<<endl;
}
long long query(int c){
	if(!flag){
		ll p = 0;
		for(int i = 0;i<n;i+=2){
			p+= diff[i];
			arr[i] += p;
		}
		p = 0;
		for(int i = 1;i<n;i+=2){
			p+=diff[i];
			arr[i] += p;
		}
//		for(int i = 0;i<n;i++)cout<<arr[i]<<',';cout<<endl;
	}
	flag = true;
	return arr[c];
}
