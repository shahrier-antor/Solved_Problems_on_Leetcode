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
        
        vector<int>solve;
        ListNode head(0);
        ListNode* current = &head;
        
        for(auto node: lists){
            while(node){
                solve.push_back(node->val);
                node = node->next;
            }
        }
        sort(solve.begin(), solve.end());

        for(auto val:solve){
            current->next = new ListNode(val);
            current = current->next;
        }
       return head.next;
    }
};