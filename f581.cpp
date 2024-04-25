#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(2*n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		if(i !=0)v[i]+= v[i-1];
	}
	int sum = v[n-1];
	for(int i = n;i<2*n;i++){
		v[i] = v[i-n]+sum;
	}
	int now = 0;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		int shift = 0;
		if(now !=0)shift = v[now-1];
		shift = (shift+k);
		int pos = lower_bound(v.begin(),v.end(),shift)-v.begin();
		now = pos+1;
		if(now>=n)now %=n;
//		cout<<shift<<' '<<pos<<endl;
	}
	cout<<now;
}
//5 5
//1 1 1 1 1
//2 3 1 1 2
//2
//1
//2
//3
//1
//1
//4

/*
5 4
1 100 1 1 1
90 90 90 90
*/
