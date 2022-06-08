// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache{
    
    public:
    class node 
    {
        public: 
        int key;
        int value;
        node * prev;
        node * next;
        
        node(int _key,int _value)
        {
            key = _key;
            value = _value;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node *> m;
    
    // Constructor for initializing the
    // cache capacity with the given value.
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node * temp)
    {
        node * dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    
    void deletenode(node * temp)
    {
        node * delnext = temp->next;
        node * delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    // This method works in O(1)
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node * res =  m[key];
            m.erase(key);
            int ans = res->value;
            deletenode(res);
            addnode(res);
            m[key] = head->next;
        //   cout << "Got the value : " << ans 
        //         << " for the key: " << key << "\n";
            return ans;
        }
        // cout << "Did not get any value for the key: " 
        //      << key << "\n";
        return -1;
    }
    
    // This method works in O(1)
    void set(int key, int value)
    {
        
        // cout << "Going to set the (key, value) : (" 
        //      << key << ", " << value << ")" << "\n";
        if (m.find(key) != m.end())
        {
            node * exist = m[key];
            m.erase(key);
            deletenode(exist);
        }
        
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends