#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a,vector<int>b){
    return a[0]<b[0];
}
void unionn(int u, int v,vector<int>&parent,vector<int>&rank){
    int uparent = parent[u];
    int vparent = parent[v];

    if(rank[uparent]<rank[vparent]){
        parent[u]=v;
    }else if(rank[vparent]<rank[uparent]){
        parent[v]=u;
    }else{
        rank[u]++;
        parent[v]=u;
    }
}
int findParent(int x, vector<int>parent){
    if(parent[x]==x)
    return x;

    return parent[x]=findParent(parent[x],parent);
}
int main(){
    //In Kruskal's ALgo you do not need to store an adjacency list rather you would require a linear data structure and that would help you with sorting in order of weight
    cout<<"Enter the number of nodes: ";
    int nodes;
    cin>>nodes;
    vector<int>parent(nodes+1);
    for(int i =0;i<=nodes;i++){
        parent[i]=i;
    }
    vector<int>rank(nodes+1,0);
    cout<<"Enter the number of edges: ";
    int edges = -1;
    cin>>edges;
    vector<vector<int>> vec;
    int w,u,v;
    for(int i=0;i<edges;i++){
    	cout<<"Enter the weight-initialNode-finalNode: "  ;
        cin>>w>>u>>v;
        vec.push_back({w,u,v});
    }

    //Now i m gonna implemetn Kruskal's Function
    sort(vec.begin(),vec.end(),cmp);
    
    //If u wish to print the data structure i used
    // for(auto v:vec){
    //     for(int e:v){
    //         cout<<e;
    //     }
    //     cout<<endl;
    // }
    vector<pair<int,int>> mst;
    int cost=0;
    for(vector<int> v:vec){
        if(findParent(v[1],parent)!=findParent(v[2],parent)){
            unionn(v[1],v[2],parent,rank);
            cost+=v[0];
            mst.push_back(make_pair(v[1],v[2]));
        }
    }

    cout<<"The total Cost of the MST is "<<cost<<endl;
    for(auto it:mst){
        cout<<"The Node "<<it.first<<" is connectd to :"<<it.second<<endl;
    }
    
    return 0;
}