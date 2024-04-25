#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
const int sq = sqrt(mxn);
vector<int> freq[mxn];
int arr[mxn];
int ptr;
int cnt[mxn];
int ans[mxn];

struct Q{
	int l,r,id;
	Q(){
		l = 0,r = 0,id = 0;
	}
	bool operator<(const Q& b)const{
		return l/sq == b.l/sq?(l/sq&1?r>b.r:r<b.r):l/sq<b.l/sq;
	}
};

vector<Q> req;
int pl,pr;

void add(int id){
	int pos = arr[id];
	cnt[pos]++;
	freq[cnt[pos]].push_back(pos);
	if(ptr<cnt[pos])ptr = cnt[pos];
	return;
}

void del(int id){
	int pos = arr[id];
	cnt[pos]--;
	freq[cnt[pos]].push_back(pos);
	while(true){
		while(!freq[ptr].empty()&&cnt[freq[ptr].back()] != ptr)freq[ptr].pop_back();
		if(!freq[ptr].empty())break;
		ptr--;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=q;i++){
		Q tmp;
		cin>>tmp.l>>tmp.r;
		tmp.id = i;
		req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	pl = pr = 1;
	add(1);
	for(auto &i:req){
		while(pr<i.r){
			pr++;
			add(pr);
		}
		while(pl>i.l){
			pl--;
			add(pl);
		}
		while(pr>i.r){
			del(pr);
			pr--;
		}
		while(pl<i.l){
			del(pl);
			pl++;
		}
		ans[i.id] = ptr;
	}
	for(int i = 1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
