#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1e5+10;
vector<pii> op;
int bit[mxn];
ll ans[mxn];
int N,M;
int arr[mxn],pos[mxn];
int brr[mxn];
bitset<mxn> done;

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

void process(){
	cin>>N>>M;
	for(int i = 1;i<=N;i++)cin>>arr[i],pos[arr[i]] = i;
	for(int i = 1;i<=M;i++){
		int p;
		cin>>p;
		brr[i] = p;
		op.push_back({pos[p],p});
		done[p] = true;
	}
	for(int i = 1;i<=N;i++){
		if(!done[i])op.push_back({pos[i],i});
	}
	reverse(op.begin(),op.end());
}

const int magic = 200;

void dc(int l,int r){
	if(l == r)return;
	int mid = (l+r)>>1;
	if(r-l+1<=magic){
		for(int i = l;i<=r;i++){
			for(int j = i+1;j<=r;j++){
				if(op[i].fs<op[j].fs&&op[i].sc>op[j].sc)ans[op[j].sc]++;
				else if(op[i].fs>op[j].fs&&op[i].sc<op[j].sc)ans[op[j].sc]++;
			}
		}
		sort(op.begin()+l,op.begin()+r+1);
		return;
	}
	dc(l,mid);
	dc(mid+1,r);
	vector<pii> v;
	int pl = l,pr = mid+1;
	while(pl<=mid||pr<=r){
		int dir = 0;
		if(pl>mid)dir = 1;
		else if(pr>r)dir = 0;
		else if(op[pl].fs>op[pr].fs)dir = 1;
		else dir = 0;
		if(!dir){
			modify(op[pl].sc,1);
			v.push_back(op[pl]);
			pl++;
		}
		else{
			ans[op[pr].sc] += getval(op[pr].sc,mxn-1);
			v.push_back(op[pr]);
			pr++;
		}
	}
	for(int i = l;i<=r;i++)modify(op[i].sc,-getval(op[i].sc,op[i].sc));
	pl = mid,pr = r;
	while(pl >= l||pr>=mid+1){
		int dir = 0;
		if(pl<l)dir = 1;
		else if(pr<mid+1)dir = 0;
		else if(op[pl].fs<op[pr].fs)dir = 1;
		else dir = 0;
		if(!dir){
			modify(op[pl].sc,1);
			pl--;
		}
		else{
			ans[op[pr].sc] += getval(0,op[pr].sc);
			pr--;
		}
	}
	for(int i = l;i<=r;i++){
		op[i] = v[i-l];
		modify(v[i-l].sc,-getval(v[i-l].sc,v[i-l].sc));
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	process();
	auto cp = op;
	dc(0,op.size()-1);
	for(int i = 1;i<cp.size();i++){
		ans[cp[i].sc] += ans[cp[i-1].sc];
	}
	for(int i = 1;i<=M;i++){
		cout<<ans[brr[i]]<<'\n';
	}
	return 0;
}
