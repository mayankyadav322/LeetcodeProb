/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
      ListNode* tail =head;
      int count=0;
      while(tail->next != NULL){
         tail =tail->next;
        count++;     
      } 
      count++;
      k = k%count;
      if(k == 0) return head;
      ListNode* curr = head;
      for(int i=0;i<count-k-1;i++){
        curr = curr->next;
      }
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
      
         

      return head;
    }
};