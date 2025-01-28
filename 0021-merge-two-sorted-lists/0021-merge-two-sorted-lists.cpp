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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* answer = new ListNode();
        ListNode* head = answer;
        
        while(list1!= nullptr || list2!=nullptr){

            if(list1!=nullptr && (list2==nullptr || list1->val<=list2->val)){
                answer->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{

                answer->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            answer = answer->next;
        }
        
        return head->next;
    }
};