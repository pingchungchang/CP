#include <bits/stdc++.h>
#include "lib1635.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

/*
int Initialize(){
	cout<<"init:";
	int k;
	cin>>k;
	return k;
}
int Max(int a,int b){
	cout<<"ask:"<<a<<' '<<b<<endl;
	int k;
	cin>>k;
	return k;
}
void Report(int k){
	cout<<"Guess:";
	cout<<k<<endl;
	return;
}
*/

int main(){
	int n = Initialize();
	int l = 1,r = n;
	while(l+1<r){
		int mid = (l+r)>>1;
		if(Max(mid,mid+1) == mid+1)l = mid+1;
		else r = mid;
	}
	if(Max(l,r) == r)Report(r);
	else Report(l);
}
