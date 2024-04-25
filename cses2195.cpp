#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct Pt{
	ll x,y;
	Pt(){x = y = 0;}
	Pt(ll xx,ll yy):x(xx),y(yy){}
	Pt operator+(Pt b)const{return Pt(x+b.x,y+b.y);}
	Pt operator-(Pt b)const{return (*this)+Pt(-b.x,-b.y);}
	ll operator*(Pt b)const{return x*b.x+y*b.y;}
	ll operator^(Pt b)const{return x*b.y-y*b.x;}
	bool operator<(Pt b)const{return x == b.x?y<b.y:x<b.x;}
	bool operator==(Pt b)const{return x==b.x&&y==b.y;}
};

const int mxn = 2e5+10;
int N;
Pt arr[mxn];
vector<Pt> down,up;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	sort(arr+1,arr+N+1);
	for(int i = 1;i<=N;i++){
		while(up.size()>1&&((up.end()[-2]-up.end()[-1])^(arr[i]-up.end()[-1]))<0)up.pop_back();
		up.push_back(arr[i]);
		while(down.size()>1&&((down.end()[-2]-down.end()[-1])^(arr[i]-down.end()[-1]))>0)down.pop_back();
		down.push_back(arr[i]);
	}
	for(int i = 1;i+1<down.size();i++)up.push_back(down[i]);
	cout<<up.size()<<'\n';
	for(auto &i:up)cout<<i.x<<' '<<i.y<<'\n';
}
