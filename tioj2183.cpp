#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double
ll cross(pll a,pll b){
    return a.fs*b.sc-a.sc*b.fs;
}

const int mxn = 1e5+10;
const ld eps = 1e-4;
pll arr[mxn],al[mxn],ar[mxn];
vector<pll> get_convex(pll p[],ll sz){
    vector<pair<pll,pll>> st;
    st.push_back({p[0],{0,0}});
    for(int i = 1;i<sz;i++){
        pll dir = {p[i].fs-st.back().fs.fs,p[i].sc-st.back().fs.sc};
        while(!st.empty()&&cross(dir,st.back().sc)<0){
            st.pop_back();
            dir = {p[i].fs-st.back().fs.fs,p[i].sc-st.back().fs.sc};
        }
        st.push_back({p[i],{-dir.fs,-dir.sc}});
    }
    vector<pll> re;
    for(auto &i:st)re.push_back(i.fs);
    return re;
}
ld slope(pll a,pll b){
    return (ld)(a.sc-b.sc)/(a.fs-b.fs);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
    sort(arr,arr+n);
    for(int i = 0;i<n/2;i++)al[i] = arr[i];
    for(int i = n/2;i<n;i++)ar[i-n/2] = arr[i];
    auto lowl = get_convex(al,n/2);
    reverse(al,al+n/2);
    auto upl = get_convex(al,n/2);
    auto lowr = get_convex(ar,n/2);
    reverse(ar,ar+n/2);
    auto upr = get_convex(ar,n/2);
    //conl.push_back(al[0]);
    //conr.push_back(ar[0]);
    pair<pll,pll> line1 = {{2,INT_MAX},{1,1}};
    int p = lowr.size()-1;
//    for(auto &i:lowl)cout<<i.fs<<','<<i.sc<<';';cout<<endl;
//    for(auto &i:upr)cout<<i.fs<<","<<i.sc<<":";cout<<endl;
    for(int i = 0;i<upl.size();i++){
        while(p>0&&cross({upl[i].fs-lowr[p].fs,upl[i].sc-lowr[p].sc},{lowr[p-1].fs-lowr[p].fs,lowr[p-1].sc-lowr[p].sc})>0)p--;
//        cout<<upl[i].fs<<' '<<upl[i].sc<<' '<<lowr[p].fs<<' '<<lowr[p].sc<<endl;
        if(i != 0&&cross({-upl[i].fs+lowr[p].fs,-upl[i].sc+lowr[p].sc},{upl[i-1].fs-upl[i].fs,upl[i-1].sc-upl[i].sc})>eps)break;
		if(slope(line1.fs,line1.sc)>slope(upl[i],lowr[p]))line1 = {upl[i],lowr[p]};
    }
    pair<pll,pll> line2 = {{0,INT_MAX},{1,1}};
    p = 0;
    for(int i = lowl.size()-1;i>=0;i--){
        while(p<upr.size()-1&&cross({lowl[i].fs-upr[p].fs,lowl[i].sc-upr[p].sc},{upr[p+1].fs-upr[p].fs,upr[p+1].sc-upr[p].sc})<0)p++;
//		cout<<lowl[i].fs<<' '<<lowl[i].sc<<' '<<upr[p].fs<<' '<<upr[p].sc<<endl;
        if(i != lowl.size()-1&&cross({-lowl[i].fs+upr[p].fs,-lowl[i].sc+upr[p].sc},{lowl[i+1].fs-lowl[i].fs,lowl[i+1].sc-lowl[i].sc})<-eps)break;
		if(slope(line2.fs,line2.sc)<slope(upr[p],lowl[i]))line2 = {upr[p],lowl[i]};
    }
    pair<ld,ld> x1 = {slope(line1.fs,line1.sc),line1.fs.sc-slope(line1.fs,line1.sc)*line1.fs.fs},x2 = {slope(line2.fs,line2.sc),line2.fs.sc-slope(line2.fs,line2.sc)*line2.fs.fs};
    pair<ld,ld> ans;
    ans.fs = (x1.sc-x2.sc)/(x2.fs-x1.fs);
    ans.sc = x1.fs*ans.fs+x1.sc;
//    cout<<line1.fs.fs<<' '<<line1.fs.sc<<','<<line1.sc.fs<<' '<<line1.sc.sc<<endl;
//    cout<<line2.fs.fs<<' '<<line2.fs.sc<<','<<line2.sc.fs<<' '<<line2.sc.sc<<endl;
	//cout<<x1.fs<<' '<<x1.sc<<endl;
    cout<<fixed<<setprecision(2)<<ans.fs<<' '<<ans.sc;
}
/*
6
0 0
-1 0
0 -1
1 1
1 2
2 1
*/
