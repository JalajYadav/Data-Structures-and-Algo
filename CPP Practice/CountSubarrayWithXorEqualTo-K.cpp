#include <bits/stdc++.h>
using namespace std;
// Day4: (Hashing)


// P.5) Count the number of subarrays having a given XOR

// Given an array of integers arr[] and a number m,
// count the number of subarrays having XOR of their elements as m.


// Input : arr[] = {4, 2, 2, 6, 4}, m = 6
// Output : 4
// Explanation : The subarrays having XOR of 
//               their elements as 6 are {4, 2}, 
//               {4, 2, 2, 6, 4}, {2, 2, 6},
//                and {6}
int Solution(vector<int>&vec, int K){
    int cnt=0;
    int XR=0;
    unordered_map<int,int>ump;
    //==================================================
    
    
    // I want to do this in adifferent way 
    // this fails neutrals like 2 ,2 will fuck this up  

    // ❌for(int i =0;i<vec.size();++i){
    // ❌  
    // ❌  XR=XR^vec[i];
    // ❌  if(XR==K)
    // ❌  cnt++;
    // ❌  int Y =XR^K;
    // ❌  if(ump.find(Y)==ump.end()){
    // ❌      ump[Y]++;
    // ❌  }else{
    // ❌      cnt+=ump[Y];
    // ❌     ump[Y]++;
    // ❌  }
    // ❌}
    for(int i =0;i<vec.size();++i){
        XR=XR^vec[i];
        if(XR==K)
        cnt++;
        int Y =XR^K;
        
        if(ump.find(Y)!=ump.end())
        cnt+=ump[Y];
      
            
        ump[XR]++;
        
    }
    //==================================================
    return cnt;
}

int main() {
	int sz=0,K=0;
    cout<<"Enter Size of array\n";
    cin>>sz;
    vector<int>vec(sz);
    for(int i = 0;i<sz;i++){
        cout<<"Enter"<<i<<"th ele. of array: ";
        cin>>vec[i];
    }
    
    cout<<"Enter The value of K\n";
    cin>>K;
    cout<<"The Count is >>>>>>>> "<<Solution(vec,K);

	return 0;
}