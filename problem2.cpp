// #include <iostream>
// using namespace std;
// template <typename T>
// class stack
// {
//     struct node
//     {
//         node *next;
//         T data;

//         node(T data)
//         {
//             this->next = NULL;
//             this->data = data;
//         }
//     };

// public:
//     node *head;
//     int topp = -1;

//     stack<T>()
//     {
//         this->head = NULL;
//     }

//     bool empty()
//     {
//         return (this->head == NULL);
//     }

//     void push(T data)
//     {
//         node *new_node = new node(data);
//         if (this->head == NULL)
//         {
//             this->head = new_node;
//             this->topp++;
//             return;
//         }
//         new_node->next = head;
//         head = new_node;
//         this->topp++;
//     }
//     void pop()
//     {

//         if (this->head == NULL)
//             return;

//         if (this->head->next == NULL)
//         {
//             delete head;
//             head = NULL;
//             topp--;
//             return;
//         }
//         node *temp = this->head;
//         head = head->next;
//         delete temp;
//         topp--;
//     }

//     void display()
//     {
//         if (head == NULL)
//         {
//             cout << "Empty!\n";
//             return;
//         }
//         node *temp = this->head;
//         while (temp != NULL)
//         {
//             cout << temp->data << "  ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }

//     int getSize()
//     {
//         return this->top;
//     }

//     T top()
//     {
//         return this->head->data;
//     }

//     ~stack<T>()
//     {
//         while (this->head != NULL)
//         {
//             node *temp = this->head;
//             this->head = this->head->next;
//             delete temp;
//         }
//         cout << "~Stack<T>() called\n";
//     }

//     void recur(node *head)
//     {
//         if (head == NULL)
//         {
//             return;
//         }
//         recur(head->next);
//         cout << head->data << "  ";
//     }
// };

// int priority(char ch)
// {
//     if (ch == '+' || ch == '-')
//         return 1;

//     if (ch == '*' || ch == '/')
//         return 2;

//     if (ch == '^')
//         return 3;

//     return 0;
// }
// string convert(string infix)
// {
//     int i = 0;
//     string postfix = "";
//     stack<int> s;

//     while (infix[i] != '\0')
//     {
//         if (infix[i] == ' ')
//         {
//             i++;
//         }

//         // if operand add to the postfix expression
//         if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
//         {
//             postfix += infix[i];
//             i++;
//         }
//         // if opening bracket then push the stack
//         else if (infix[i] == '(')
//         {
//             s.push(infix[i]);
//             i++;
//         }
//         else if (infix[i] == ')')
//         {
//             while (s.top() != '(')
//             {
//                 postfix += s.top();
//                 s.pop();
//             }
//             s.pop();
//             i++;
//         }
//         else
//         {
//             while (!s.empty() && priority(infix[i]) <= priority(s.top()))
//             {
//                 postfix += s.top();
//                 s.pop();
//             }
//             s.push(infix[i]);
//             i++;
//         }
//     }
//     while (!s.empty())
//     {
//         postfix += s.top();
//         s.pop();
//     }

//     // cout << "Postfix Expression is : " << postfix; // it will print postfix conversion
//     return postfix;
// }

// int main()
// {
//     string infix = "( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) )";
//     cout << "Enter infix expression:-\n";
//     getline(cin, infix);
//     string postfix;
//     postfix = convert(infix);
//     cout << postfix << endl;

//     //     Enter infix expression:-
//     // ( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) )
//     // ~Stack<T>() called
//     // AXBXCYAY+BY+CX***
//     return 0;
// }