/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
         return NULL;
         unordered_map<Node*,Node*> mp;
         Node* newnode = new Node(head->val);
         Node* oldtemp = head->next;
         Node* newtemp = newnode;
         mp[head] = newnode;
         while(oldtemp != NULL){
            Node* secnode = new Node(oldtemp->val);
            mp[oldtemp] = secnode;
            newtemp->next = secnode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
         }
         oldtemp = head;
         newtemp = newnode;
         while(oldtemp != NULL){
              newtemp->random = mp[oldtemp->random];
              oldtemp = oldtemp->next;
              newtemp = newtemp->next;
         }
         return newnode;
    }
};