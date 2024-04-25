#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct point{
	ll x,y;
	point(){x = y = 0;}
	point(ll xx,ll yy){x = xx,y = yy;}
	point operator+(point b)const{return point(x+b.x,y+b.y);}
	point operator-(point b)const{return point(x-b.x,y-b.y);}
	ll operator*(point b)const{return x*b.x+y*b.y;}
	ll operator^(point b)const{return x*b.y-y*b.x;}
	bool operator<(point b)const{return x== b.x?y<b.y:x<b.x;}
};

const int mxn = 2e5+10;
point arr[mxn],brr[mxn];
set<point> ss;
vector<point> st;
int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0;i<N;i++)cin>>arr[i].x>>arr[i].y,brr[i] = arr[i];
	sort(arr,arr+N);
	for(int i = 0;i<N;i++){
		while(st.size()>1&&((st.end()[-2]-st.end()[-1])^(arr[i]-st.end()[-1]))<=0)st.pop_back();
		st.push_back(arr[i]);
	}
	for(auto &i:st)ss.insert(i);
	st.clear();
	reverse(arr,arr+N);
	for(int i = 0;i<N;i++){
		while(st.size()>1&&((st.end()[-2]-st.end()[-1])^(arr[i]-st.end()[-1]))<=0)st.pop_back();
		st.push_back(arr[i]);
	}
	for(auto &i:st)ss.insert(i);
	for(int i = 0;i<N;i++){
		if(ss.find(brr[i]) != ss.end())cout<<1;
		else cout<<0;
	}
}
