#include<bits/stdc++.h>
class LRUCache
{
public:

    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;

            node(int _key,int value){
                key = _key;
                val = value;
            }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int,node*> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end()){
            node* resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()){
            node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key,value));
        mp[key] = head->next;
    }
    //TC = O(N);
    //SC = O(1);
};
