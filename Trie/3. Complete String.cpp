#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL );
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool getEnd(){
        return flag;
    }
};

class Trie {
    private: Node* root;

    public:  Trie(){
        root = new Node();
    }
    
    public: void insert(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }

    public: bool isPrefixExist(string word){

        bool fl = true;
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                
                node = node->get(word[i]);
                fl = fl & node->getEnd(); 
            }
            else{
                return false;
            }
            
        }
        return fl;
    }

};

string completeString(int n, vector<string> &a){
    
    Trie* trie = new Trie();

    for(auto it : a){
        trie->insert(it);
    }

    string longest = "";

    for(auto it : a){

        if(trie->isPrefixExist(it)){
            if(it.length() > longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest){
                longest = it;
            } 
        }
    }

    if(longest == "") return "None";

    return longest;
}
//TC = O(N*len) + O(N*len);



