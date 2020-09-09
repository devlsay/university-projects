#pragma once

namespace dst
{
  template <typename T>
  class node;
  template <typename T>
  class list;

  class string;

  template <typename T>
  class node
  {
  public:
    node(T data = T(), node *pNext = nullptr);

    T data;
    node *pNext;
  };

  template <typename T>
  class list
  {
    node<T> *pHead;
    int Size;

  public:
    list();
    ~list();

    void push_front(T data);
    void insert(T data, int index);
    void push_back(T data);

    void pop_front();
    void removeAt(int index);
    void pop_back();

    void clear();

    int GetSize() { return Size; }
    T &operator[](const int index);
  };

  template <typename T>
  inline node<T>::node(T data, node *pNext)
  {
    this->data = data;
    this->pNext = pNext;
  }

  template <typename T>
  inline list<T>::list()
  {
    Size = 0;
    pHead = nullptr;
  }

  template <typename T>
  inline list<T>::~list()
  {
    clear();
  }

  template <typename T>
  inline void
  list<T>::push_front(T data)
  {
    pHead = new node<T>(data, pHead);
    Size++;
  }

  template <typename T>
  inline void
  list<T>::insert(T data, int index)
  {
    if (index == 0)
      push_front(data);
    else
    {
      node<T> *previous = this->pHead;

      for (int i = 0; i < index - 1; i++)
        previous = previous->pNext;

      node<T> *newNode = new node<T>(data, previous->pNext);

      previous->pNext = newNode;

      Size++;
    }
  }

  template <typename T>
  inline void
  list<T>::push_back(T data)
  {
    if (pHead == nullptr)
      pHead = new node<T>(data);
    else
    {
      node<T> *current = this->pHead;

      while (current->pNext != nullptr)
        current = current->pNext;

      current->pNext = new node<T>(data);
    }
    Size++;
  }

  template <typename T>
  inline void
  list<T>::pop_front()
  {
    node<T> *temp = pHead;

    pHead = pHead->pNext;

    delete temp;

    Size--;
  }

  template <typename T>
  inline void
  list<T>::removeAt(int index)
  {
    if (index == 0)
      pop_front();
    else
    {
      node<T> *previous = this->pHead;

      for (int i = 0; i < index - 1; i++)
        previous = previous->pNext;

      node<T> *toDelete = previous->pNext;

      previous->pNext = toDelete->pNext;

      delete toDelete;

      Size--;
    }
  }

  template <typename T>
  inline void
  list<T>::pop_back()
  {
    removeAt(Size - 1);
  }

  template <typename T>
  inline void
  list<T>::clear()
  {
    while (Size)
      pop_front();
  }

  template <typename T>
  T &list<T>::operator[](const int index)
  {
    int counter = 0;

    node<T> *current = this->pHead;

    while (current != nullptr)
    {
      if (counter == index)
        return current->data;

      current = current->pNext;
      counter++;
    }
  }
} // namespace dst
