#include "List.h"
#include <iostream>

int main()
{
    List<int> lst;
    for (int i = 0; i < 10; ++i)
    {
        lst.push_back(i);
    }

    lst.pop_back();

    for (auto it : lst)
    {
        std::cout << it << "\t";
    }
    std::cout << std::endl << std::endl;

    /*
    const Object &operator*() const
    const_iterator &operator++()
    const_iterator operator++(int)
    const_iterator &operator--()
    const_iterator operator--(int)
    bool operator==(const const_iterator &rhs) const
    bool operator!=(const const_iterator &rhs) const
    Object &retrieve() const
    const_iterator(Node *p) : current{p}
    Object &operator*()
    const Object &operator*() const
    iterator &operator++()
    iterator operator++(int)
    iterator &operator--()
    iterator operator--(int)
    iterator(Node *p) : const_iterator{p}
    List(std::initializer_list<Object> il) : List()
    List(const List &rhs)
    List &operator=(List copy)
    List(List &&rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    iterator begin()
    const_iterator begin() const
    iterator end()
    const_iterator end() const
    int size() const
    bool empty() const
    void clear()
    Object &front()
    const Object &front() const
    Object &back()
    const Object &back() const
    void push_front(const Object &x)
    void push_front(Object &&x)
    void push_back(const Object &x)
    void push_back(Object &&x)
    void pop_front()
    void pop_back()
    iterator insert(iterator itr, const Object &x)
    iterator insert(iterator itr, Object &&x)
    iterator erase(iterator itr)
    iterator erase(iterator from, iterator to)
    */

    List<int> list0;
    std::cout << list0.size() << std::endl;
    list0.printList();
    std::cout << std::endl;

    List<int> list1{1, 2, 3, 4, 5};
    list1.printList();
    std::cout << std::endl;

    list1.pop_back();
    list1.printList();
    list1.back();
    list1.pop_front();
    list1.printList();
    list1.front();
    std::cout << std::endl;

    List<int> list2;
    List<int> list3;
    list2 = list1;
    list2.printList();
    list2 = list3 = List<int> {5, 4, 3, 2, 1};
    list2.printList();
    list3.printList();
    list2 = std::move(list1);
    list2.printList();
    std::cout << std::endl;

    list2.push_front(9);
    list2.printList();
    list2.push_back(10);
    list2.printList();
    list2.push_front(4 + 4);
    list2.printList();
    list2.push_back(5 + 6);
    list2.printList();
    list2.clear();
    list2.printList();
    std::cout << std::endl;

    List<int> list4{1, 2, 3, 4, 5};
    List<int>::iterator itr1 = list4.begin();
    std::cout << *itr1 <<std::endl;
    *itr1 = -1;
    list4.printList();
    std::cout << *(itr1 ++) << std::endl;
    std::cout << *itr1 << std::endl;
    List<int>::iterator itr2 = list4.end();
    std::cout << *(itr2 --) << std::endl;
    std::cout << *itr2 << std::endl;
    std::cout << *(++itr1) << " " << *(--itr2) << std::endl;
    std::cout << *itr1 << " " << *itr2 << std::endl;
    std::cout << (itr1 == itr1) << std::endl;
    std::cout << (itr1 == itr2) << std::endl;
    std::cout << (itr1 != itr1) << std::endl;
    std::cout << (itr1 != itr2) << std::endl;
    std::cout << std::endl;

    itr1 = list4.insert(itr1, -2);
    list4.printList();
    std::cout << *itr1 <<std::endl;
    itr2 = list4.insert(itr2, 9+1);
    list4.printList();
    std::cout << *itr2 << std::endl;
    itr1 = list4.erase(itr1);
    list4.printList();
    std::cout << *itr1 <<std::endl;
    itr2 = list4.erase(itr1, ++itr2);
    list4.printList();
    std::cout << *itr2 << std::endl;
    std::cout << std::endl;




    
    











    // for (auto it = lst.begin(); it != lst.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }

//     List<int> lst = {1, 2, 3, 4, 5};
//     for (auto &x : lst)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

// //    List<int> lst2 = std::move(lst);
//     List<int> lst2 = List<int> {5, 6};
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

//     lst2 = std::move(lst);
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;
    // while(1){};
    return 0;
}
