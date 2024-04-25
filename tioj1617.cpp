#include <bits/stdc++.h>
#include "lib1617.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

/*
int Get_Box(){
	int n;
	cin>>n;
	return n;
}
int Med3(int a,int b,int c){
	cout<<"med:";
	cout<<a<<' '<<b<<' '<<c<<endl;
	int re;
	cin>>re;
	return re;
}
void Report(int k){
	cout<<"quess:"<<k<<endl;
	return;
}

*/


int main(){
	int n = Get_Box();
	pii p = {1,2};
	for(int i = 3;i<=n;i++){
		auto re = Med3(p.fs,p.sc,i);
		if(p.fs == re)p.fs = i;
		else if(p.sc == re)p.sc = i;
	}
	vector<int> v;
	for(int i = 1;i<=n;i++){
		if(p.fs == i||p.sc == i)continue;
		v.push_back(i);
	}
	nth_element(v.begin(),v.begin()+v.size()/2,v.end(),[&](int a,int b){return Med3(a,b,p.fs) == a;});
	Report(v[v.size()/2]);
}
