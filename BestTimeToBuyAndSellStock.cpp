vector<int> m;
int nowsmallest = prices[0];
int nowbiggest = prices[0];
for(int i =1;i<prices.size();i++){
    if(nowsmallest>prices[i]){
        m.push_back(nowbiggest-nowsmallest);
        nowsmallest = prices[i];
        nowbiggest = prices[i];
    }
    nowbiggest = max(nowbiggest,prices[i]);
}
m.push_back(nowbiggest - nowsmallest);
m.push_back(0);
sort(m.begin(),m.end());
return m[m.size()-1];
