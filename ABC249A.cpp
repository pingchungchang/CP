#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int a,b,c,d,e,f,x;
	cin>>a>>b>>c>>d>>e>>f>>x;
	int d1 = x/(a+c)*b*a+min(a,x%(a+c))*b;
	int d2 = x/(d+f)*e*d+min(d,x%(d+f))*e;
	if(d1>d2)cout<<"Takahashi";
	else if(d1<d2)cout<<"Aoki";
	else cout<<"Draw";
}

