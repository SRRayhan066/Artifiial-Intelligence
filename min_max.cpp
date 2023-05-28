#include<bits/stdc++.h>
using namespace std;

void min_max_algorithm(vector<int>vec[],int n,int limit,int level,bool indicator){
    if(level==log2(n)) return;
    for(int i=0;i<limit;i++) cout<<vec[level][i]<<" ";
    cout<<endl;
    for(int i=0;i<limit;i+=2){
        int val;
        if(indicator) val=max(vec[level][i],vec[level][i+1]);
        else val=min(vec[level][i],vec[level][i+1]);
        vec[level+1].push_back(val);
    }
    return min_max_algorithm(vec,n,limit/2,level+1,!indicator);
}

int main(){
    cout<<"Enter the number of elements :: ";
    int n;cin>>n;
    int ansLevel=log2(n);
    int level=0;
    vector<int>vec[n+1];
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vec[level].push_back(x);
    }
    bool indicator = ansLevel&1;
    min_max_algorithm(vec,n,n,level,indicator);
    cout<<"The ans is :: "<<vec[ansLevel][0]<<endl;
    return 0;
}