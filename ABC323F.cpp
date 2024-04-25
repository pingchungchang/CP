#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll dist(pll a,pll b){
	return abs(a.fs-b.fs)+abs(a.sc-b.sc);
}

ll calc(pll now,pll tar,pll ban){
	return dist(now,tar);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pll a,b,c;
	cin>>a.fs>>a.sc>>b.fs>>b.sc>>c.fs>>c.sc;
	if((a.fs==b.fs&&a.fs == c.fs)||(a.sc == c.sc&&a.sc == b.sc)){
		if(a.fs == b.fs&&a.fs == c.fs){
			swap(a.fs,a.sc);swap(b.fs,b.sc);swap(c.fs,c.sc);
		}
		if((a.fs<=b.fs&&b.fs<=c.fs)||(a.fs>=b.fs&&b.fs>=c.fs)){
			cout<<dist(a,c);
			return 0;
		}
		else{
			cout<<dist(a,b)+dist(b,c)+3;
			return 0;
		}
	}

	if(b.fs == c.fs||b.sc == c.sc){
		if(b.fs == c.fs){
			swap(a.fs,a.sc);swap(b.fs,b.sc);swap(c.fs,c.sc);
		}
		if((a.fs<=b.fs&&b.fs<=c.fs)||(a.fs>=b.fs&&b.fs>=c.fs)){
			cout<<dist(a,b)+dist(b,c);
			return 0;
		}
		else{
			cout<<dist(a,b)+dist(b,c)+1;
			return 0;
		}
	}

	int d1 = (b.fs<=c.fs?-1:1),d2 = (b.sc<=c.sc?-1:1);
	pll p1 = {b.fs+d1,b.sc},p2 = {b.fs,b.sc+d2};
	cout<<min(calc(a,p1,b),calc(a,p2,b))+dist(b,c)+2;
}
