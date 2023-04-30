// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
        Item* prev;
    };
    Item* head;
    Item* tail;
    TPQueue::Item* create(const T&);

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T&);
    T pop();
};

template<typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& value) {
    Item* item = new item;
    item->data = value;
    item->next = item->prev = nullptr;
    return item;
}

template<typename T>
T TPQueue<T>::pop() {
    if (head == nullptr) {
        throw std::string("Queue is Empty");
    } else {
        Item* temp = head->next;
        T value = head->data;
        delete head;
        head = temp;
        return value;
    }
}

template<typename T>
void TPQueue<T>::push(const T& value) {
    if (head == nullptr) {
        head = create(vlaue);
        tail = head;
    } else if (tail->data.prior >= value.prior) {
        tail->next = create(value);
        tail->next->prev = tail;
        tail = tail->next;
    } else {
        Item* item = create(value);
        Item* temp = tail;
        while (temp != head && value.prior > temp->data.prior) {
            temp = temp->prev;
        }
        temp->next->prev = item;
        item->next = temp->next;
        temp->next = item;
        item->prev = temp;
    }
}

template<typename T>
TPQueue<T>::~TPQueue() {
    while (head != nullptr) {
        pop();
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
