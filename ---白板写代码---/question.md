
### 白板写代码

1. 链表排序

    ```
    #include<iostream>
    #include<algorithm> 
    #include<vector>
    using namespace std;


    struct node
    {
        int val;
        node * next;
        node(int value) { val = value; next = NULL; }
    };

    //链表排序
    node* list_sort(node * head) {
        if (head == NULL||head->next==NULL) {
            return head;
        }

        node * p_cur = head->next;
        head->next = NULL;
        //创建一个虚拟头结点
        node * sortedhead = new node(INT_MIN);
        sortedhead->next = head;

        while (p_cur != NULL) {
            node * temp = p_cur->next;
            p_cur->next = NULL;

            node * sorted_begin = sortedhead;
            node * sorted_end = sortedhead->next;

            //插入p_cur
            while (sorted_end != NULL) {
                if (p_cur->val >= sorted_begin->val && p_cur->val <= sorted_end->val) {
                    //插入在begin 和end中间
                    sorted_begin->next = p_cur;
                    p_cur->next = sorted_end;
                    sorted_begin = sorted_begin->next;
                    break;
                }
                else {
                    sorted_begin=sorted_begin->next;
                    sorted_end =sorted_end->next;
                }
            }
            //将p_cur加入尾部
            if (sorted_end == NULL) {
                sorted_begin->next = p_cur;
            }

            //指向下一个，继续插入
            p_cur = temp;
        }


        return sortedhead->next;
    }

    int main()
    {
        node head(5);
        node n1(3);
        node n2(8);
        node n3(7);
        node n4(1);

        head.next = &n1;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;

        node * new_head = list_sort(&head);



        system("pause");
        return 0;
    }
    ```

* 两个有序数组归并

* 顺时针打印矩阵（todo）

* 快速排序

* 反转链表

* 将一个链表拆分成两个（奇数位组成一个链表；偶数位组成一个链表）