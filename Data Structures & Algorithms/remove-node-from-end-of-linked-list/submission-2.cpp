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
    int solve(ListNode* head){
        if(head==NULL) return 0;
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;

        int count=1;
        int length=solve(head);

        if(n==length)return head->next;
        ListNode* temp=head;

        while(temp!=NULL){
            if(count==length-n){
                temp->next=temp->next->next;
            }
            count++;
            temp=temp->next;
        }
        return head;
    }
};
