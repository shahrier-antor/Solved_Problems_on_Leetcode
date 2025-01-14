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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//         vector<int>solve;
//         ListNode head(0);
//         ListNode* current = &head;
        
//         for(auto node: lists){
//             while(node){
//                 solve.push_back(node->val);
//                 node = node->next;
//             }
//         }
//         sort(solve.begin(), solve.end());

//         for(auto val:solve){
//             current->next = new ListNode(val);
//             current = current->next;
//         }
//        return head.next;
//     }
// };




class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comparator = [](ListNode* a, ListNode*b){return a->val > b->val; };
        priority_queue <ListNode*, vector<ListNode*>, decltype(comparator)> minHeap(comparator);
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        for(auto list: lists){
            if(list) minHeap.push(list);
        }
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();
            current->next = temp;
            current = current->next;
            if(temp->next)minHeap.push(temp->next);
        }
        return dummy.next;
    }
};