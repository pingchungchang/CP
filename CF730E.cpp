#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct node{
	int id;
	int from;
	int score;
	node(){}
	node(int a,int b,int c){
		id = a,from = b,score = c;
	}
	bool operator<(const node &b)const{
		return score == b.score?id<b.id:score>b.score;
	}
};

bool dir(pii a){
	return a.fs>a.sc;
}
bool cover(pii a,pii b){
	if(a.fs>a.sc)swap(a.fs,a.sc);
	if(b.fs>b.sc)swap(b.fs,b.sc);
	if(a.fs>b.fs)swap(a,b);
	return a.sc>b.sc;
}
bool intersect(pii a,pii b){
	if(a.fs>a.sc)swap(a.fs,a.sc);
	if(b.fs>b.sc)swap(b.fs,b.sc);
	if(a.fs>b.fs)swap(a,b);
	return a.sc>b.fs;
}

const int mxn = 202;
vector<node> all;
pii arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ans = 0;
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		node tmp(i,0,a);
		all.push_back(tmp);
		tmp.score += b;
		tmp.from = true;
		all.push_back(tmp);
	}
	sort(all.begin(),all.end());
	for(int i = 0;i<all.size();i++){
		if(all[i].from)arr[all[i].id].sc = i;
		else arr[all[i].id].fs = i;
	}
	/*
	for(auto &i:all)cout<<i.id<<' '<<i.score<<' '<<i.from<<endl;
	cout<<endl;for(int i = 1;i<=n;i++){
		cout<<arr[i].fs<<' '<<arr[i].sc<<endl;
	}cout<<endl;

   */
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(cover(arr[i],arr[j])){
				ans++;
			}
			else if(!intersect(arr[i],arr[j]))continue;
			else if(dir(arr[i]) == dir(arr[j]))ans += 2;
			else ans += 1;
		}
	}
	cout<<ans;
}
