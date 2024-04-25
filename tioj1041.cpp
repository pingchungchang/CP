#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double


struct point{
	ld x,y;
	point(){x = y = 0;}
	point(int a,int b){x = a,y = b;}
	point operator+(point b)const{return point(x+b.x,y+b.y);}
	point operator-(point b)const{return point(x-b.x,y-b.y);}
	ld operator*(point b)const{return x*b.x+y*b.y;}
	ld operator^(point b)const{return x*b.y-y*b.x;}
	bool operator<(point b)const{return x==b.x?y<b.y:x<b.x;}
	bool operator==(point b)const{return x == b.x&&y==b.y;}
};


const int mxn = 55;
vector<point> arr,brr,ch1,ch2;
int n,m;

vector<point> convex_hull(vector<point> &v){
	vector<point> re;
	vector<point> st;
	sort(v.begin(),v.end());
	for(auto &i:v){
		while(st.size()>=2&&((i-st.end()[-1])^(st.end()[-2]-st.end()[-1]))>=0)st.pop_back();
		st.push_back(i);
	}
	re = st;
	sort(v.rbegin(),v.rend());
	for(auto &i:v){
		while(st.size()>=2&&((i-st.end()[-1])^(st.end()[-2]-st.end()[-1]))>=0)st.pop_back();
		st.push_back(i);
	}
	st.pop_back();
	reverse(st.begin(),st.end());
	if(!st.empty())st.pop_back();
	for(auto &i:st)re.push_back(i);
	return re;
}

void solve(){
	for(int i = 0;i<m;i++){
		point tmp;
		cin>>tmp.x>>tmp.y;
		arr.push_back(tmp);
	}
	for(int i = 0;i<n;i++){
		point tmp;
		cin>>tmp.x>>tmp.y;
		arr.push_back(tmp);
	}
	sort(arr.begin(),arr.end());arr.resize(unique(arr.begin(),arr.end())-arr.begin());
	sort(brr.begin(),brr.end());brr.resize(unique(brr.begin(),brr.end())-brr.begin());
	ch1 = convex_hull(arr);
	ch2 = convex_hull(brr);
	int s = ch1.size();
	for(int i = 0;i<s;i++)ch1.push_back(ch1[i]);
	s = ch2.size();
	for(int i = 0;i<s;i++)ch2.push_back(ch2[i]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>m>>n&&n&&m)solve();
}
