#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);
        vector<int>price(V,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push(make_pair(0,0));
        
        price[0]=0;
        while(!pq.empty()){
            int node =pq.top().second;
            mst[node]=true;
            pq.pop();
            for(vector<int> vec:adj[node]){
                price[vec[0]]=min(price[vec[0]],vec[1]);
                if(price[vec[0]]==vec[1]){
                    parent[vec[0]]=node;
                    pq.push(make_pair(price[vec[0]],vec[0]));
                }
            }
        }
        int res = 0;
        for(int e:price)
        res+=e;

        for(int x:price)
        cout<<x;
        cout<<endl;
        for(bool x:mst)
        cout<<x;
        cout<<endl;
        for(int x:parent)
        cout<<x;
        cout<<endl;

        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends