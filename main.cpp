#include "MyList.h"

int main() {
//     //2, 6, 8 ,4
//
//     Node<int> first(2); // info = 2, next = &second;
//
//     Node<int> second(6); // info = 6, next = &third;
//     first.next = &second;
//
//     Node<int> third(8) ; // info = 8, next = &fourth;
//     second.next = &third;
//
//     Node<int> fourth(4); // info = 4, next = nullptr;
//     third.next = &fourth;
//
//     // Обхід списку
//     Node<int> *p = &first;
//
//     while (p != nullptr) {
//         p->show();
//         p = p->next;
//     }

    // List<int> nums; // head = nullptr
    // nums.push_back(6); // head = tail = 6
    // nums.push_back(4); //head = 6, tail = 4
    // nums.push_back(8); //head = 6, tail = 8
    // nums.push_back(2); //head = 6, tail = nullptr
    // nums.showList();

    DList<int> nums; // head = nullptr
    nums.push_back(6); // head = tail = 6
    nums.push_back(4); //head = 6, tail = 4
    nums.push_back(8); //head = 6, tail = 8
    nums.push_back(2); //head = 6, tail = nullptr
    nums.push_front(13); // Додавання вузла на початок списку
    nums.insertBefore(9, 30); // Додавання вузла перед заданим значенням
    nums.insertAfter(13,130); //Додавання вузла після заданого значення
    nums.erase(455);


    cout << "Звичайний список: ";
    nums.show();
    cout << endl;
    // cout << "Перевернутий список: ";
    // nums.show_reverse();

    // std::list<int> nums; //STD STL
    // nums.push_back(6); // head = tail = 6
    // nums.push_back(4); //head = 6, tail = 4
    // nums.push_back(8); //head = 6, tail = 8
    // nums.push_back(4); //head = 6, tail = nullptr



    // std::list<int>::iterator p;
    // std::list<int>::iterator pDel;
    // for (p = nums.begin(); p != nums.end(); ) {
    //     pDel = p;
    //     p++;
    //     if (*pDel == 4) {
    // cout << "DELETE: " << *pDel << " ";
    //         nums.erase(pDel);
    //         cout << endl;
    //     }
    // }
    // cout << endl;

    // for (int a : nums) {
    //     cout << a << " ";
    // }
    // cout << endl;


return 0;
}
