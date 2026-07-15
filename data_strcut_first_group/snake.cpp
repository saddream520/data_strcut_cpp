#include<iostream>
#include<string>
using namespace std;
template<typename S>
// 首先我们需要创造出一条蛇
class show_snake
{
    struct snake
    {
        snake*next;
        snake*prev;
        S body;
        snake(S body_val)
        :body(body_val),next(nullptr),prev(nullptr)
        {

        }
    };
    snake*head;
    snake*tail;
    int size;
public:
    show_snake()
    {
        head =new snake(S());
        tail =new snake(S());
        size = 0;
        head->next =tail;
        tail->prev =head;
    }
    ~show_snake()
    {
        delete head;
        delete tail;
    }
    void addfirst(S e)
    {
        snake*new_body =new snake(e);
        snake*temp = head->next;
        temp ->prev =new_body;
        new_body ->next =temp;

        head->next =new_body;
        new_body->next = temp;
        size++;
    }

    void display() {
        cout << "size = " << size << endl;
        for (snake* p = head->next; p != tail; p = p->next) {
            cout << p->body << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }
    
};
int main()
{
    show_snake<string>Snake;
    string e ="o";
    for(int i =0;i<5;i++)
    {
        Snake.addfirst(e);
    }
    Snake.display();
    cin.get();
}