#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> store;
vector<int> subset;

void gensubset(vector<int> &a, int n,int index){
    if(index==n){
        store.push_back(subset);
    }else{
        subset.push_back(a[index]);
        gensubset(a,n,index+1);
        subset.pop_back();
        gensubset(a,n,index+1);
    }

}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    gensubset(a,n,0);
    // to avoid duplicate subset when there is repeating element in vector 'a', 
    //sort all subsets and then put in a set.
    for(int i=0;i<store.size();i++){
        sort(store[i].begin(),store[i].end());
    }
    set<vector<int>> st(store.begin(),store.end()); // contain multiple vectors, unordered_set can't contain vectors.
    vector<vector<int>> res;
    for(auto it=st.begin();it!=st.end();it++){
        res.push_back(*it);
    }

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}