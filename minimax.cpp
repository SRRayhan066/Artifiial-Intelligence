#include<bits/stdc++.h>
using namespace std;
#define ll long 

vector<ll>vec[100];
map<ll,ll>val;
map<ll,bool>vis;

ll minimax(ll source,ll indicator){
    vis[source]=true;
    ll min_val=INT_MAX,max_val=-100000;
    for(auto x : vec[source]){
        if(!vis[x]){
            if(val[x]==INT_MAX){
                ll temp=minimax(x,!indicator);
                min_val=min(min_val,temp);
                max_val=max(max_val,temp);;
            }else{
                min_val=min(min_val,val[x]);
                max_val=max(max_val,val[x]);
            }
        } 
    }
    if(indicator) val[source]=max_val;
    else val[source]=min_val;
    return val[source];
}

int main(){
    freopen("minimax_input.txt","r",stdin);
    int nodes,edges;
    cin>>nodes>>edges;
    while(edges--){
        ll x,y;cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        val[x]=INT_MAX,val[y]=INT_MAX;
    }
    int leaf_nodes;cin>>leaf_nodes;
    for(int i=nodes-(leaf_nodes-1);i<=nodes;i++){
        ll x;cin>>x;
        val[i]=x;
    }
    bool indicator=true;
    ll ans=minimax(1,indicator);
    cout<<ans<<endl;
}