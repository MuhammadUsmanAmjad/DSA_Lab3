#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter n:\n";
    cin >> n;
    int number;
    int max_num;
    int sec_max = -9999;
    cout << "enter numbers:\n";
    cin >> number;
    max_num = number;
    int i = 0;
    while (i < n - 1)
    {
        cin >> number;

        if (number > max_num)
        {
            sec_max = max_num;
            max_num = number;
        }
        else if (sec_max < number && number != max_num)
            sec_max = number;

        i++;
    }
    cout << "max num is:  " << max_num << endl;
    cout << "2nd max num is:  " << sec_max << endl;
}
// template <typename T>
// struct node
// {
//     T data;
//     node<T> *prev;
//     node<T> *next;
//     node<T>(T val)
//     {
//         prev = NULL;
//         next = NULL;
//         data = val;
//     }
//     template <typename Y>
//     friend class linklist;
// };
// template <typename T>
// class linklist
// {
//     // friend void deleteNode(node<T> *head, node<T> *del);
//     class iterator
//     {
//         friend class linklist;

//     private:
//         node<T> *nodePtr;

//         iterator(node<T> *newPtr) : nodePtr(newPtr) {}

//     public:
//         iterator() : nodePtr(nullptr) {}

//         bool operator!=(const iterator &itr) const
//         {
//             return nodePtr != itr.nodePtr;
//         }

//         // Overload for the dereference operator *
//         T &operator*() const
//         {
//             return nodePtr->next->data;
//         }

//         // Overload for the postincrement operator ++
//         iterator operator++(int)
//         {
//             iterator temp = *this;
//             nodePtr = nodePtr->next;
//             return temp;
//         }
//     }; // End of inner class iterator

// public:
//     node<T> *head;
//     node<T> *tail;
//     linklist<T>()
//     {
//         head = NULL;
//         tail = NULL;
//     }
//     iterator begin() const
//     {
//         return head;
//     }

//     iterator end() const
//     {
//         return tail;
//     }
//     linklist<T>(linklist<T> const &obj)
//     {
//         if (this->head != NULL)
//         {
//             node<T> *t = head;

//             while (head->next != t)
//             {
//                 node<T> *temp = head;
//                 head = head->next;
//                 delete temp;
//             }
//         }
//         node<T> *temp = obj.head;
//         do
//         {
//             insertattail(temp->data);
//             temp = temp->data;

//         } while (temp != head);
//     }
//     ~linklist<T>()
//     {
//         node<T> *t = head;

//         while (head->next != t)
//         {
//             node<T> *temp = head;
//             head = head->next;
//             delete temp;
//         }

//         cout << "~linklist<T>\n";
//     }
//     void insert_at_head(T const val)
//     {
//         node<T> *n = new node<T>(val);
//         if (head == NULL)
//         {
//             head = n;
//             tail = n;
//             return;
//         }
//         n->next = head;
//         head->prev = n;
//         head = n;
//     }
//     void insertattail(T const val)
//     {
//         node<T> *n = new node(val);
//         if (head == NULL)
//         {
//             head = n;
//             tail = n;
//             return;
//         }
//         node<T> *temp = head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = n;
//         n->prev = temp;
//         tail = n;
//         tail->next = head;
//     }
//     void deleteathead()
//     {
//         if (head == NULL)
//             return;
//         node<T> *temp = head;
//         head = head->next;

//         tail->next = head;
//         head->prev = NULL;
//         delete temp;
//     }
//     void deleteattail()
//     {
//         node<T> *temp = tail;
//         tail = tail->prev;
//         tail->prev->next = tail;
//         tail->next = head;
//         delete temp;
//     }
//     void display()
//     {
//         node<T> *temp = head;
//         while (temp != tail)
//         {
//             cout << temp->data << "->";
//             temp = temp->next;
//         }
//         cout << temp->data;
//         cout << "\n_______________________________\n";
//     }
//     int size() const
//     {
//         int i = 1;
//         node<T> *temp = head;
//         while (temp->next != head)
//         {
//             i++;
//             temp = temp->next;
//         }
//         return i;
//     }
//     bool IsEmpty()
//     {
//         if (head == NULL)
//             return true;
//         return false;
//     }
//     T return_middle()
//     {
//         int count = size() / 2;
//         node<T> *temp = head;
//         int i = 0;
//         while (temp->next != head && i < count)
//         {
//             temp = temp->next;
//             i++;
//         }
//         return temp->data;
//     }
//     T return_max()
//     {
//         node<T> *temp = head;
//         T max_val = head->data;
//         temp = temp->next;
//         while (temp != tail->next)
//         {
//             if (max_val < temp->data)
//                 max_val = temp->data;
//             temp = temp->next;
//         }
//         return max_val;
//     }
//     void insertafter(T val, int key)
//     {
//         if (key < 0 || key > size())
//         {
//             insertattail(val);
//             return;
//         }
//         node<T> *t = new node(val);
//         if (key == 0)
//         {
//             t->next = head;
//             head->prev = t;
//             tail->next = t;
//             head = t;
//             return;
//         }
//         int i = 0;
//         node<T> *temp = head;
//         while (i < key)
//         {
//             temp = temp->next;
//             i++;
//         }
//         node<T> *temp2 = temp;
//         temp = t;
//         t->prev = temp2->prev;
//         temp2->prev->next = t;
//         t->next = temp2;
//         temp2->prev = t;
//     }
//     void insertbefore(T val, int key)
//     {
//         if (key < 0 || key > size())
//         {
//             insertattail(val);
//             return;
//         }
//         node<T> *t = new node(val);
//         if (key == 1)
//         {
//             t->next = head;
//             head->prev = t;
//             tail->next = t;
//             head = t;
//             return;
//         }
//         node<T> *temp = head;
//         int i = 0;
//         while (i < key - 1)
//         {
//             temp = temp->next;
//             i++;
//         }
//         node<T> *temp2 = temp;
//         temp = t;
//         t->prev = temp2->prev;
//         t->next = temp2;
//         temp2->prev->next = t;
//         temp2->prev = t;
//     }
//     void delete_duplicates()
//     {
//         if ((head) == NULL)
//             return;

//         node<T> *current = head;
//         node<T> *next;

//         while (current->next != NULL)
//         {

//             if (current->data == current->next->data)

//                 deleteNode(head, current->next);

//             else
//             {
//                 // tail->next = head;
//                 current = current->next;
//             }
//         }
//     }
//     void deleteNode(node<T> *h, node<T> *del)
//     {

//         if (h == NULL || del == NULL)
//             return;
//         if (h == del)
//         {
//             h = del->next;
//             tail->next = h;
//         }

//         if (del->next != NULL)
//             del->next->prev = del->prev;
//         if (del->prev != NULL)
//             del->prev->next = del->next;
//         delete del;
//     }
//     void insert(int data)
//     {
//         node<T> *current;
//         node<T> *newNode = new node<T>(data);
//         // if list is empty
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = head;
//         }

//         // if the node is to be inserted at the beginning
//         // of the doubly linked list
//         else if ((head)->data >= newNode->data)
//         {
//             newNode->next = head;
//             newNode->next->prev = newNode;
//             head = newNode;
//             tail->next = head;
//         }

//         else
//         {
//             current = head;

//             while (current != tail &&
//                    current->next->data <= newNode->data)
//                 current = current->next;

//             newNode->next = current;
//             newNode->next->prev = newNode;
//             current->next = newNode;
//             newNode->prev = current;
//             tail = newNode;
//             tail->next = head;
//         };
//     }
// };
// int main()
// {
//     linklist<int> *l1 = new linklist<int>();
//     l1->insert_at_head(3);
//     l1->insert_at_head(2);
//     l1->insert_at_head(1);
//     l1->insert_at_head(1);
//     l1->insert_at_head(34);
//     l1->insertattail(0);
//     l1->display();
//     cout << "\n After Deletetion At head:\n";
//     l1->deleteathead();
//     l1->display();
//     cout << "\n After Deletetion At Tail:\n";
//     l1->deleteattail();
//     l1->display();

//     l1->insertafter(-8, 1);
//     cout << "Inserted after:\n";
//     l1->display();

//     l1->insertbefore(-1, 1);
//     cout << "Inserted before:\n";
//     l1->display();

//     cout << "Size:  " << l1->size() << endl;
//     cout << "Middle: " << l1->return_middle() << endl;
//     cout << " Max: " << l1->return_max() << endl;
//     delete l1;
//     linklist<int> *l = new linklist<int>;
//     l->insert(1);
//     l->insert(0);
//     l->insert(-9);
//     l->insert(2);
//     l->insert(8);
//     l->insert(8);
//     l->insert(9);
//     l->insert(-11);
//     l->display();

//     return 0;
// }