
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

    ```
    int partition(vector<int> & arr, int begin, int end)
    {
        int partition_val = arr[end];
        int sorted_index = begin;
        for (int i = begin; i < end; i++)
        {
            if (arr[i] < partition_val)
            {
                swap(arr[sorted_index], arr[i]);
                sorted_index++;
            }
        }
        swap(arr[sorted_index], arr[end]);
        return sorted_index;
    }
    void quick_sort(vector<int> &arr,int begin,int end)
    {
        int left = begin;
        int right = end;
        if (left < right)
        {
            int index = partition(arr, begin, end);
            quick_sort(arr, begin, index - 1);
            quick_sort(arr, index + 1, end);
        }
    }


    int main()
    {

        vector<int> arr = { 5,8,1,3,10,9,4,0 };
        quick_sort(arr, 0, 7);

        return 0;
    }
    ```

* 反转链表

* 将一个链表拆分成两个（奇数位组成一个链表；偶数位组成一个链表）

* 归并两个有序链表
    ```
    #include <iostream>
    #include <vector>

    using namespace std;

    struct ListNode 
    {
        int val;
        struct ListNode *next;
        ListNode(int x) :val(x), next(NULL) {}
    };

    //根据vector去创建一个链表
    ListNode * create_list_by_vector(vector<int> vi)
    {
        ListNode * head = new ListNode(vi[0]);
        ListNode * p = head;
        for (int i = 1; i < vi.size(); i++)
        {
            ListNode * node = new ListNode(vi[i]);
            p->next = node;
            p = p->next;
        }
        return head;
    }

    ListNode* insert(ListNode * tail, ListNode * node)
    {
        node->next = NULL;
        tail->next = node;
        return node;
    }

    ListNode * merge(ListNode * head1,ListNode * head2)
    {
        ListNode * newhead = new ListNode(-1);
        ListNode * tail = newhead;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val < head2->val)
            {
                ListNode * p = head1->next;
                //插入head1
                tail = insert(tail,head1);
                head1 = p;
            }
            else
            {
                ListNode * p = head2->next;
                //插入head2
                tail = insert(tail,head2);
                head2 = p;
            }
        }

        if(head1!=NULL)
        {
            tail->next = head1;
        }
        else if(head2 != NULL)
        {
            tail->next = head2;
        }
        return newhead->next;
    }

    void print_list(ListNode * head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<endl;
            head=head->next;
        }
    }

    int main()
    {
        int arr[] = {1,3,7,9,16 };
        vector<int> vi1(arr,arr+5);
        ListNode * head1 = create_list_by_vector(vi1);

        int arr2[]= {2,4,8,10,14,20};
        vector<int> vi2(arr2,arr2+6);
        ListNode * head2 = create_list_by_vector(vi2);

        ListNode * newhead = merge(head1,head2);

        print_list(newhead);

        return 0;
    }
    ```

* 第K大的数组
    ```
   int get_partition(vector<int> &vi, int begin, int end)
    {
        int partition = vi[end];
        int sorted = begin;
        for (int i = begin; i < end; i++)
        {
            if (partition > vi[i])
            {
                swap(vi[i], vi[sorted]);
                sorted++;
            }
        }
        swap(vi[sorted], vi[end]);
        return sorted;
    }

    void topk(vector<int> & vi,int k)
    {
        int begin = 0;
        int end = vi.size() - 1;
        int index = get_partition(vi, begin, end);

        while (index != k - 1)
        {
            if (index < k - 1)
            {
                index = get_partition(vi, index + 1, end);
            }
            else
            {
                index = get_partition(vi, begin, index-1);
            }
        }

        cout << vi[index] << endl;
    }
    
    ```
