#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> getsmall(tuple<int,int,int> k){
	tuple<int,int,int> a = make_tuple(get<1>(k),get<2>(k),get<0>(k));
	tuple<int,int,int> b = make_tuple(get<2>(k),get<0>(k),get<1>(k));
	return min(min(k,a),b);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++)cin>>b[i];
	for(int i = 0;i<=n+1;i++){
		for(int j = n-3;j>=0;j--){
			tuple<int,int,int> x = getsmall(make_tuple(a[j],a[j+1],a[j+2]));
			a[j] = get<0>(x);
			a[j+1] = get<1>(x);
			a[j+2] = get<2>(x);
		}
	}
	
	for(int i = 0;i<=n+1;i++){
		for(int j = n-3;j>=0;j--){
			tuple<int,int,int> x = getsmall(make_tuple(b[j],b[j+1],b[j+2]));
			b[j] = get<0>(x);
			b[j+1] = get<1>(x);
			b[j+2] = get<2>(x);
		}
	}
	
	if(a[n-3] == a[n-1]){
		swap(a[n-2],a[n-1]);
	}
	if(b[n-3] == b[n-1]){
		swap(b[n-2],b[n-1]);
	}
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
