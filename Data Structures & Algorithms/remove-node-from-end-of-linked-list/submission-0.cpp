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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> ans;
        ListNode* temp=head;

        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* dtemp=dummy;

        for(int i=0;i<ans.size();i++){
            if(i==(ans.size()-n))continue;
            ListNode* node=new ListNode(ans[i]);
            dtemp->next=node;
            dtemp=dtemp->next;
        }
        return dummy->next;
    }
};
