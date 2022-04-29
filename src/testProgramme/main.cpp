#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* curHead;
    ListNode* rc(ListNode* head)
    {
        if(head->next == NULL || head == NULL)
        {
            curHead = head;
            return head;
        }
        //取得已翻转链表的最后一个结点（尾结点）
        ListNode* tmp = rc(head->next);
        cout<<"取得已翻转链表的最后一个结点: "<<tmp->val<<endl;
        //将尾结点的next指针域指向递归的当前节点head
        tmp->next = head;
        cout<<"将尾结点的next指针域指向递归的当前节点head; "<<head->val<<endl;
        //当前节点的next指针域置为空，防止出现环
        head->next = NULL;
        return head;
    }

public:
    ListNode* reverseList(ListNode* head) {
        rc(head);
        return curHead;
    }
};

void printLink(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout<<endl;
}


int main()
{
    ListNode *head = new ListNode(0);
    ListNode *tmp = head;
    

    for(int i = 1 ; i < 6 ; ++i)
    {
        ListNode *c = new ListNode(i);
        tmp->next = c;
        tmp = c;
    }
    printLink(head);

    Solution S;

    ListNode *reHead = S.reverseList(head);
    printLink(reHead);

    system("pause");
    return 0;
}

