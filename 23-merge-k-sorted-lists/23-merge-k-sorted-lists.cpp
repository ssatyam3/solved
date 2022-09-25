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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        ListNode* tmp = NULL;
        for(int i=0 ; i<lists.size() ; i++){
            tmp = lists[i];
            while(tmp != NULL){
                ans.push_back(tmp->val);
                tmp =tmp->next;
            }
        }
        
        sort(ans.begin(),ans.end());
        if(ans.size()==0){
            return NULL;
        }
        
        ListNode* head = new ListNode(ans[0]);
        ListNode* res = head;
        for(int i=1 ; i<ans.size() ; i++){
            ListNode* tmp = new ListNode(ans[i]);
            head->next = tmp;
            head = head->next;
        }
        return res;
    }
};