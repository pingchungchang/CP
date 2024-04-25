#include <bits/stdc++.h>
#include "lib1945.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1<<17;
int arr[mxn];

/*
void Init(){
	return;
}
int Query(int n,int arr[]){
	for(int i = 0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;
	int re;
	cin>>re;
	return re;
}

*/

int main(){
	Init();
	for(int i = 0;i<mxn;i++){
		int tmp[] = {i};
		arr[i] = Query(1,tmp);
	}
	int l = 0,r = mxn-1;
	bool flag = false;
	while(l != r){
		flag = false;
		int mid = (l+r)>>1;
		int tmp[mid-l+1];
		int check = 0;
		for(int i = l;i<=mid;i++)tmp[i-l] = i,check ^= arr[i];
		if(check == Query(mid-l+1,tmp))l = mid+1,flag = true;
		else flag = false,r = mid;
	}
	int cnt[2] = {};
	cnt[arr[l]]++;
	for(int i = 0;i<2;i++){
		int tmp[] = {l};
		cnt[Query(1,tmp)]++;
	}
	if(cnt[0]>cnt[1])arr[l] = 0;
	else arr[l] = 1;
	for(int i = 0;i<mxn;i++)cout<<arr[i]<<' ';
	return 0;
}
