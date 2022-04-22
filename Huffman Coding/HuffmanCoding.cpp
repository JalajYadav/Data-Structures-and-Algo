#include<bits/stdc++.h>
using namespace std;

// huffman tree node
struct HeapNode{
    char data;
    unsigned freq;
    HeapNode *left= NULL;
    HeapNode *right= NULL;
    HeapNode(char data,unsigned freq){
        
        this->data=data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(HeapNode* l, HeapNode* r){
        return (l->freq>r->freq);
    }
};

void printCodes(HeapNode* root,string str){
    if(root==NULL)
    return;

    if(root->data!='$')
    cout<<root->data << ": " << str << "\n";

    printCodes(root->left,str+'0');
    printCodes(root->right,str+'1');
}

void HuffmanCodes(char ch[],int freq[],int sz ){

     HeapNode *top, *left,*right;

    priority_queue<HeapNode*,vector<HeapNode*>,compare> minHeap;

    for(int i = 0;i<sz;i++)
    minHeap.push(new HeapNode(ch[i],freq[i]));

    while(minHeap.size()!=1){
        left = minHeap.top();
        minHeap.pop();

        right= minHeap.top();
        minHeap.pop();

        top = new HeapNode('$',left->freq+right->freq);

        top->left = left;
        top->right = right;
        minHeap.push(top);        
    }
   printCodes(minHeap.top(),"");
}

int main(){
    char ch[]={'A','B','C','D','E','F'};
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int sz = sizeof(ch)/sizeof(ch[0]);
    HuffmanCodes(ch,freq,sz);
    return 0;
}