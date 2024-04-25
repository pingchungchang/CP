#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll,ll> hs;
map<ll,ll> fs;
long long g(long long x){
//	cout<<"G"<<x<<' ';
	if(x<=2){
		return x*x-1;
	}
	else return 2;
}
long long h(long long x){
//	cout<<"H"<<x<<' ';
	if(hs.count(x) !=0)return hs[x];
	if(x<2){
		hs[x] = -1;
		return -1;
	}
	else{
		hs[x] = 2+h(x-1)-h(x-2);
		return hs[x];
	}
}
long long f(long long x){
//	cout<<"F"<<x<<' ';
	if(fs.count(x)!=0)return fs[x];
	long long k = h(x);
	if(x>k){
		fs[x] = f(x-1)-k;
	}
	else if(x<k){
		long long m = g(x);
		fs[x] =  f(m)-m;
	}
	else{
		fs[x] = 1;
	}
	return fs[x];
}

int main(){
	long long x;
	
	cin>>x;
	cout<<f(x);
}
