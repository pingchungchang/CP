#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

static int A[5000];

void solve(int N) {
	int arr[N+1],sign[N+1],brr[N+1],ans[N+1];
	for(auto &i:sign)i = 1;
	for(int i = 2;i<=N;i++)arr[i] = query(i-1,i);
	for(int i = 3;i<=N;i++)brr[i] = query(i-2,i);
	for(int i = 3;i<=N;i++){
		if(arr[i]+arr[i-1] == brr[i]){
			sign[i] = sign[i-1];
		}
		else{
			sign[i] = -sign[i-1];
		}
		//else assert(false);
	}
	//for(int i = 1;i<=N;i++)cout<<sign[i]<<' ';cout<<endl;
	for(int i = 2;i<=N;i++){
		arr[i] = arr[i]*sign[i]+arr[i-1];
	}
	//for(int i = 1;i<=N;i++)cout<<arr[i]<<' ';cout<<endl;
	int sh = 1-*min_element(arr+1,arr+N+1);
	for(int i = 1;i<=N;i++)arr[i] += sh;
	if(min_element(arr+1,arr+N+1)-arr>max_element(arr+1,arr+N+1)-arr){
		for(int i = 1;i<=N;i++)arr[i] = N+1-arr[i];
	}

	for(int i = 1; i <= N; i++) {
		answer(i,arr[i]);
	}
	return;

}
