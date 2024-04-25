//failed
#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int bit[30];
void modify(int bit[],int p,int val){
    for(;p<30;p+= p&-p)bit[p] += val;
    return;
}
int getval(int bit[],int s,int e){
    int re = 0;
    for(;e>0;e -= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}
struct Q{
    int pos,coef,tp;
    int id;
    //l:pos,r:coef,id:val
    Q(int ttt,int lll,int rrr,int ii = 0){
        tp = ttt,pos = lll,coef = rrr;
        id = ii;
    }
};
vector<Q> req;
int ans[mxn];
void dc(int l,int r){
    // cout<<l<<' '<<r<<endl;
    if(l == r)return;
    int mid = (l+r)>>1;
    dc(l,mid);
    dc(mid+1,r);
    vector<Q> pl,pr;
    for(int i = mid;i>=l;i--)pl.push_back(req[i]);
    for(int i = r;i>mid;i--)pr.push_back(req[i]);
    int sum = 0;
    int pt = l;
    while(!pl.empty()||!pr.empty()){
        bool isl = false;
        if(pr.empty())isl = true;
        else if(pl.empty())isl = false;
        else if(pl.back().pos<=pr.back().pos)isl = true;
        else isl = false;
        if(isl){
            auto now = pl.back();
            req[pt++] = now;
            pl.pop_back();
            if(now.tp == 1){
                sum += now.coef*getval(bit,now.id+1,30-1);
                modify(bit,now.id,now.coef);
            }
        }
        else{
            auto now = pr.back();
            pr.pop_back();
            req[pt++] = now;
            if(now.tp == 0){
                ans[now.id] += sum;
            }
        }
    }
    cout<<l<<' '<<r<<":";
    for(int i = l;i<=r;i++)cout<<req[i].tp<<' '<<req[i].pos<<' '<<req[i].coef<<' '<<req[i].id<<", ";for(int i = 0;i<3;i++)cout<<ans[i]<<",";cout<<endl;
    for(int i = 1;i<30;i++)modify(bit,i,-getval(bit,i,i));
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = "#"+s;
    int q;
    cin>>q;
    for(int i = 1;i<=n;i++){
        req.push_back(Q(1,i,1,s[i]-'a'+1));
    }
    int cnt = 0;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int p;char c;
            cin>>p>>c;
            req.push_back(Q(1,p,-1,s[p]-'a'+1));
            req.push_back(Q(1,p,1,c-'a'+1));
            s[p] = c;
        }
        else{
            int l,r;
            cin>>l>>r;
            req.push_back(Q(0,l-1,-1,cnt));
            req.push_back(Q(0,r,1,cnt++));
        }
    }
    cout<<"HI"<<endl;
    dc(0,req.size()-1);
    cout<<"done"<<endl;
    cout<<cnt<<endl;
    for(int i = 0;i<cnt;i++)cout<<ans[i]<<' ';
}