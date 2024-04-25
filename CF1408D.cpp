#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>
#pragma GCC optimize("O3")

const int mxn = 2020;
const int Mxn = 1e6+10;
int vals[mxn];
int cnt[Mxn];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	pii arr[n];
	pii brr[m];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(auto &i:brr)cin>>i.fs>>i.sc;
	vector<pii> st;
	sort(brr,brr+m);
	for(auto &i:brr){
		while(!st.empty()&&st.back().sc<i.sc){
			st.pop_back();
		}
		if(st.empty()||st.back().fs != i.fs)st.push_back(i);
	}
	st.push_back({Mxn,-1});
	m = st.size();
	//for(auto &i:st)cout<<i.fs<<','<<i.sc<<' ';cout<<endl;
	vector<tuple<int,int,int>> v;
	for(int i = 0;i<n;i++){
		vector<pii> tmp;
		for(int j = 0;j<m-1;j++){
			tmp.push_back({max(0,st[j].fs-arr[i].fs+1),max(0,st[j+1].sc-arr[i].sc+1)});
		}
		for(int j = 0;j<m;j++){
			if(st[j].fs>=arr[i].fs){
				tmp.push_back({0,max(0,st[j].sc-arr[i].sc+1)});
				break;
			}
		}
		for(int j = 0;j<m;j++){
			if(st[j].sc<=arr[i].sc){
				tmp.push_back({max(st[j].fs-arr[i].fs+1,0),0});
				break;
			}
		}
		sort(tmp.begin(),tmp.end());
		for(int j = 1;j<tmp.size();j++)tmp[j].sc = min(tmp[j].sc,tmp[j-1].sc);
		for(auto &j:tmp){
			v.push_back(make_tuple(j.fs,j.sc,i));
		}
	}
	sort(v.begin(),v.end());
	for(auto &i:v){
		vals[get<2>(i)] = max(get<1>(i),vals[get<2>(i)]);
	}
	for(int i = 0;i<n;i++)cnt[vals[i]]++;
	int pt = Mxn-1;
	while(pt&&!cnt[pt])pt--;
	int ans = pt;
	for(auto &i:v){
		int pos = get<2>(i);
		int val = get<1>(i);
		cnt[vals[pos]]--;
		vals[pos] = min(vals[pos],val);
		cnt[vals[pos]]++;
		while(pt&&!cnt[pt])pt--;
		ans = min(ans,pt+get<0>(i));
	}
	cout<<ans;
}
