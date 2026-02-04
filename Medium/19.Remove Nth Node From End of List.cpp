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
  int lenght(ListNode *head) {
    ListNode *temp = head;
    int count = 1;
    while (temp->next != nullptr) {
      temp = temp->next;
      count++;
    }
    return count;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int size = lenght(head);
    if (n == size)
      return head->next;
    ListNode *temp = head;
    int count = 1;
    while (count != size - n && temp != nullptr) {
      temp = temp->next;
      count++;
    }
    temp->next = temp->next->next;
    return head;
  }
};
