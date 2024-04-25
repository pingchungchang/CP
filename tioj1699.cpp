#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ushort unsigned short



const ll mxn = 1e5+10;
const int big = USHRT_MAX;
const int sq = sqrt(mxn);
struct Q{
	int32_t id;
	int l,r;
	int32_t k;
	Q(){}
	bool operator<(const Q&b)const{
		return l/sq == b.l/sq?(l/sq&1?r>b.r:r<b.r):l/sq<b.l/sq;
	}
};

vector<Q> req;
bitset<mxn> ans;
int n;
int q;
int arr[mxn];
vector<ushort> freq[mxn];
ushort cnt[mxn];
ushort pt;
vector<int> all;

void add(int p){
	int val = arr[p];
	cnt[val]++;
	freq[cnt[val]].push_back(val);
	pt = max(pt,cnt[val]);
}

void del(int p){
	int val = arr[p];
	assert(cnt[val]>0);
	cnt[val]--;
	freq[cnt[val]].push_back(val);
	while(true){
		while(!freq[pt].empty()&&cnt[freq[pt].back()] != pt)freq[pt].pop_back();
		if(freq[pt].empty())pt--;
		else break;
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	for(int i = 1;i<=n;i++)arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin()+1;
	for(int i = 0;i<q;i++){
		Q tmp;
		int32_t a,b;
		cin>>a>>b;
		assert(a<=big&&b<=big);
		tmp.l = a,tmp.r = b;
		cin>>tmp.k;
		tmp.id = i;
		req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	int pl = 1,pr = 1;
	add(1);
	for(auto &i:req){
		while(i.r>pr)add(++pr);
		while(i.l<pl)add(--pl);
		while(pr>i.r)del(pr--);
		while(pl<i.l)del(pl++);
		if(1LL*pt*i.k>=i.r-i.l+1)ans[i.id] = 1;
	}
	for(int i = 0;i<q;i++)cout<<(ans[i]?"Yes\n":"No\n");
	return 0;
}
