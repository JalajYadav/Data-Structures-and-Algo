#include<bits/stdc++.h>
using namespace std;

//this is the dfs for step 1 inOrder to get the topological sort
void dfs(vector<int> adj[],vector<int>&vis,stack<int>&stk,int node){
    vis[node]=1;
    for(int e:adj[node]){
        if(!vis[e]){
            dfs(adj,vis,stk,e);
        }
    }
    //ye bat yaad rakhna ki stack me push hum tab marte h jab hum backtrack kr rhe ho
    stk.push(node);
}
//this is the dfs according to the stack of topological sort
void dfsForStack(vector<int> transpose[],vector<int>&vis,int node){
    vis[node]=1;
    for(int ele :transpose[node]){
        if(!vis[ele]){
            cout<<ele<<" ";
            dfsForStack(transpose,vis,ele);
        }
    }
}


int main(){
    int nodes;
    cout<<"Enter the number of Nodes";
    cin>>nodes;

    int edges;
    cout<<"Enter the number of Edges";
    cin>>edges;

    vector<int> adj[nodes];
    for(int i =0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> vis(nodes,0);
    stack<int> stk;
    //Step 1 : Toposort
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            dfs(adj,vis,stk,i);
        }
    }

    //Steps 2 : transpose

    vector<int>transpose[nodes];
    for(int i=0;i<nodes;i++){
        vis[i]=0;//remember for step 3 you nedd to switch the visited node around...
        for(int e:adj[i]){
            transpose[e].push_back(i);
        }
    }


    //Steps 3: this is the final dfs
    while(!stk.empty()){
        if(!vis[stk.top()]){
            cout<<"SCC grp : "<<stk.top()<<" ";
            dfsForStack(transpose,vis,stk.top());
        }
        stk.pop();
    }
    
    return 0;
}