#include <bits/stdc++.h>
using namespace std;

#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3")
#define push_back emplace_back
const int mxn = 4e5+10;
bitset<mxn> b;
int h[mxn],rnk[mxn];
pair<pii,int> buf[mxn];
vector<pair<pii,int>> v[mxn];
int m;
vector<int> SA (string s) {
    int n = s.size();
    if (n == 1) return {1};
    s = s + string (1, 0);
    vector<int> sa (n + 1), rnk (n + 1), cnt (n + 1);
    int al[256] = {};
    FOR (i, 0, n) al[s[i]]++;
    FOR (i, 1, 255) al[i] += al[i - 1];
    FOR (i, 0, n) sa[--al[s[i]]] = i;
    for (int i = 1, now = 0; i <= n; i++) {
        if (s[sa[i]] != s[sa[i - 1]]) now++;
        rnk[sa[i]] = now;
    }
    for (int len = 1; len <= n; len <<= 1) {
        vector<int> lp (n + 1), tmp (n + 1);
        fill (cnt.begin(), cnt.end(), 0);
        FOR (i, 0, n) {
            lp[i] = sa[i] - len;
            lp[i] += lp[i] < 0 ? n + 1 : 0;
            cnt[rnk[i]]++;
        }
        FOR (i, 1, n) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 0; i--) sa[--cnt[rnk[lp[i]]]] = lp[i];
        tmp[sa[0]] = 0;
        for (int i = 1, now = 0; i <= n; i++) {
            int np1 = sa[i] + len, np2 = sa[i - 1] + len;
            np1 -= np1 > n + 1 ? n + 1 : 0;
            np2 -= np2 > n + 1 ? n + 1 : 0;
            if (rnk[sa[i]] != rnk[sa[i - 1]] || rnk[np1] != rnk[np2]) now++;
            tmp[sa[i]] = now;
        }
        rnk = tmp;
    }
    sa.erase (sa.begin());
    return sa;
}

int main(){
	io
	int n;
	cin>>n;
	vector<int> start;
	string s;
	for(int i = 0;i<n;i++){
		string t;
		cin>>t;
		start.push_back(s.size());
		if(i != 0)s += '#';
		s += t;
	}
	m = s.size();
	auto pos = SA(s);
	for(int i = 0;i<m;i++){
		rnk[pos[i]] = i;
	}
//	for(int i = 0;i<m;i++)cout<<rnk[i]<<' ';
	for(int i= 0;i<m;i++){
		pos[rnk[i]] = i;
	}
	int k = 0;
	for(int i = 0;i<m;i++){
		int pi = rnk[i];
		if(pi == 0){
			k = max(k-1,0);
			continue;
		}
		int pre = pos[pi-1];
		while(pre+k<m&&i+k<m&&s[pre+k] == s[i+k])k++;
		h[pi] = k;
		k = max(k-1,0);
	}
	
	int id[m] = {};
	for(int i= 1;i<m;i++){
		id[i] = upper_bound(_all(start),pos[i])-start.begin();
	}
//	cout<<s<<endl;
//	for(int i = 1;i<m;i++)cout<<h[i]<<' ';return 0;
	int ccc = 0;
	deque<pii> dq;
	int cc[m] = {};
	for(int i = 1;i<n-1;i++){
		if(!dq.empty()&&dq.back().fs>h[i]){
			dq.pop_back();
		}
		dq.push_back(h[i],i);
		cc[id[i]]++;
		if(cc[id[i]] == 1)ccc++;
	}
	cc[id[0]]++;
	ccc++;
	if(n == 1){
		cout<<s;
		return 0;
	}
//	for(int i = 1;i<m;i++)cout<<h[i]<<" ";cout<<endl;
//	for(int i = 1;i<m;i++)cout<<id[i]<<' ';cout<<endl;
	for(int i = n-1;i<m;i++){
//		cout<<i<<":";
//		cout<<st.size()<<endl;
		while(!dq.empty()&&dq.back().fs>h[i])dq.pop_back();
		dq.push_back(h[i],i);
		cc[id[i]]++;
//		for(auto &j:st)cout<<j<<',';
//		for(int j = 0;j<=n;j++)cout<<cc[j]<<' ';cout<<"::";
//		cout<<endl;
		if(cc[id[i]] == 1)ccc++;
		if((i == n-1||(i != n-1&&h[i-n+1]<dq.front().fs))&&(i == m-1||(i != m-1&&h[i+1]<dq.front().fs))&&ccc == n&&dq.front().fs != 0){
			cout<<s.substr(pos[i],dq.front().fs);
			return 0;
		}
		while(!dq.empty()&&dq.front().sc<=i-n+2)dq.pop_front();
		cc[id[i-n+1]]--;
		if(cc[id[i-n+1]] == 0)ccc--;
	}
	cout<<"7122";
}

