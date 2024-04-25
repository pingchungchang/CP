#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	tuple<int,int,int> arr[n];
	int c = 1;
	for(auto &i:arr){
		cin>>get<0>(i)>>get<1>(i);
		get<2>(i) = c++;
	}
	sort(arr,arr+n,[](tuple<int,int,int> &a,tuple<int,int,int>&b){
			if(get<0>(a)*(get<0>(b)+get<1>(b))!=get<0>(b)*(get<0>(a)+get<1>(a)))return get<0>(a)*(get<0>(b)+get<1>(b))>get<0>(b)*(get<0>(a)+get<1>(a));else return get<2>(a)<get<2>(b);});
	for(auto &i:arr)cout<<get<2>(i)<<' ';
}
