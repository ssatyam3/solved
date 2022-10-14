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
    int length(ListNode *head){
        ListNode * tmp = head;
        int ans=0;
        while(tmp != NULL){
            ans++;
            tmp = tmp->next;
        }
        return ans;
    }
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL){
            return NULL;
        }
        if(head->next->next== NULL){
            head->next = NULL;
            return head;
        }
        int len = length(head);
        
        len = len/2;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        for(int i=1 ; i<=len ; i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};