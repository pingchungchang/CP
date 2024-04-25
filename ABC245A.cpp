#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	pii a;
	pii b;
	cin>>a.fs>>a.sc>>b.fs>>b.sc;
	b.sc++;
	b.fs += b.sc/60;
	b.sc%=60;
	if(a>=b){
		cout<<"Aoki";
	}
	else cout<<"Takahashi";
}

