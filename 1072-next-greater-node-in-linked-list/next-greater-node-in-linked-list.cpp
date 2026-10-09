class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        vector<int> res;

        while(temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        for(int i = 0; i < ans.size(); i++) {
            bool found = false;

            for(int j = i + 1; j < ans.size(); j++) {
                if(ans[i] < ans[j]) {
                    res.push_back(ans[j]);
                    found = true;
                    break;
                }
            }

            if(!found) {
                res.push_back(0);
            }
        }

        return res;
    }
};