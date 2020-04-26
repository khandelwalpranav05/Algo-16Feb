#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        priority_queue<ListNode* , vector<ListNode*>, Compare> pq;

        for (ListNode* head : lists) {
            if (head != NULL) {
                pq.push(head);
            }
        }

        if (pq.empty()) {
            return NULL;
        }

        ListNode* head = pq.top();
        pq.pop();

        ListNode* temp = head;

        if (temp->next != NULL) {
            pq.push(temp->next);
        }

        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();

            temp = temp->next;

            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return head;
    }
};