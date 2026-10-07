/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        int countA =0;
        while(tempA != NULL){
            countA++;
            tempA = tempA->next;
        }
        int countB =0;
        ListNode* tempB = headB;
         while(tempB != NULL){
            countB++;
            tempB = tempB->next;
        }
        tempB = headB;
        tempA = headA;
        if(countB > countA){
            for(int i=1;i<=countB-countA;i++){
                 tempB = tempB->next;
            }
                 while(tempA != tempB){
                    tempA = tempA->next;
                    tempB = tempB->next;
                 }
                 return tempA;
            
        }
             else{
            for(int i=1;i<=countA-countB;i++){
                 tempA = tempA->next;
            }
                 while(tempA != tempB){
                    tempA = tempA->next;
                    tempB = tempB->next;
                 }
                 return tempB;
            
             }
        return NULL;
    }
};