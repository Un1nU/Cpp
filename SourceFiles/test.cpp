#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

struct queue
{
    int* array;
    int capacity;
    int size;
    int front;
    int back;

    queue(int cap): capacity(cap), size(0), front(-1), back(-1) {array = new int[cap];}
};

void printQueue(queue q)
{   
    int i = (q.front + 1) % q.capacity;
    for (; i != q.back; i = (i + 1) % q.capacity)
    {
        cout << q.array[i] << " ";
    }
    cout << q.array[i] << " ";
    cout << endl;
}

bool isFull(queue q) { return q.size >= q.capacity;}
bool isEmpty(queue q) { return q.size == 0;}

int queuePop(queue& q)
{
    if (q.size == 0) return INT32_MIN;

    q.front = (q.front + 1) % q.capacity;
    int frontItem = q.array[q.front];
    q.size--;

    return frontItem;
}

void queuePush(queue& q, int num)
{
    if (q.size >= q.capacity)
    {
        cout << "queue has full" << endl;
        return;
    }

    q.back = (q.back + 1) % q.capacity;
    q.array[q.back] = num;
    q.size++;
}

int main()
{
    // 这种初始化的方式是创建一个指针，指向了常量区，即常量指针，因而导致值不可修改，在【1】处产生段错误
    //char* text = "GET\thttps://www.baidu.com/\tHTTP/1.1"  

    // char [] 分配在栈中，值可以改变，因而不会报错
    // char text[] = "GET\thttps://www.baidu.com/\tHTTP/1.1";

    // char* m_url = NULL;
    // char* url = NULL;

    // m_url = strpbrk(text, " \t");

    // *m_url++ = '\0'; // 【1】

    // printf("%c\n", *m_url);

/*---------------------------------------------------*/
    // queue q(10);

    // for (int i = 0; i < q.capacity; i++)
    // {
    //     cin >> q.array[i];
    //     q.back = (q.back + 1) % q.capacity;
    //     q.size++;
    // }

    // printQueue(q);

    // queuePop(q);
    // queuePop(q);
    // queuePop(q);

    // printQueue(q);

    // queuePush(q, 9);
    // queuePush(q, 999);
    // queuePush(q, 111);

    // queuePush(q, 222);
    // queuePush(q, 333);

    // printQueue(q);

/*----------------------------------------------*/
    // vector<int> buf;

    // buf.reserve(5);

    // buf[0] = 1;
    // cout << buf[0] << endl;
    // buf[1] = 2;
    // cout << buf[1] << endl;

    // for (auto item : buf)
    //     cout << item << " ";
    // cout << endl;

/*---------------------------------------------*/
    cout << 7 / 2 << endl;

    return 0;
}