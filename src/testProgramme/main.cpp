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
        //ȡ���ѷ�ת��������һ����㣨β��㣩
        ListNode* tmp = rc(head->next);
        cout<<"ȡ���ѷ�ת��������һ�����: "<<tmp->val<<endl;
        //��β����nextָ����ָ��ݹ�ĵ�ǰ�ڵ�head
        tmp->next = head;
        cout<<"��β����nextָ����ָ��ݹ�ĵ�ǰ�ڵ�head; "<<head->val<<endl;
        //��ǰ�ڵ��nextָ������Ϊ�գ���ֹ���ֻ�
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

