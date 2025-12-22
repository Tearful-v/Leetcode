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

    int getlenght(ListNode* dummy) {
    ListNode* temp = dummy->next;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
    }

    ListNode* merge (ListNode* left, ListNode* right){
        ListNode dum(0);
        ListNode* real = &dum;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                real->next = left;
                left = left->next;
                real = real->next;
            }
            else{
                real->next = right;
                right = right->next;
                real = real->next;
            }
        }
        while(left != nullptr){
            real->next = left;
            real = real->next;
            left = left->next;
        }
        while(right != nullptr){
            real->next = right;
            real = real->next;
            right = right->next;
        }
        return dum.next;
    }

    void split(ListNode* &dummy, int step){
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        while(curr != nullptr){
            ListNode* left = curr;
            ListNode* help = left;
            int count = 1;
            while(count != step && help != nullptr && help->next != nullptr){
                count++;
                help = help->next;
            }
            count = 1;
            ListNode* right = nullptr;
            if(help != nullptr){
                right = help->next;
                help->next = nullptr;
            }
            ListNode* connect = nullptr;
            if (right != nullptr){
                help = right;
                while(count != step && help != nullptr && help->next != nullptr){
                    count++;
                    help = help->next;
                }
            }
            if(help != nullptr){
                connect = help->next;
                help->next = nullptr;
            }
            ListNode* merged = merge(left, right);
            prev->next = merged;
            while(prev->next != nullptr){
                prev = prev->next;
            }
            curr = connect;
        }
    }

    void sort(ListNode* &dummy){
        int lenght = getlenght(dummy);
        int step = 1;
        while(step < lenght){
            split(dummy, step);
            step *= 2;
        }
    }

    ListNode* sortList(ListNode* head) {
    if (!head || !head->next) 
        return head;
    ListNode* dummy = new ListNode(0, head);
    sort(dummy);
    return(dummy->next);
    }
};