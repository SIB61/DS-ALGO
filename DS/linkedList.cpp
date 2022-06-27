
#include<bits/stdc++.h>
#include <cstddef>
#include <exception>
#include <iostream>
using namespace std;

template<typename T>
struct node{
  T data;
  struct node * next;
};

template<typename T>
void insertNode( struct node<T> * head, T data){
  struct node<T> * newNode = (struct node<T> *) malloc(sizeof(struct node<T>));
  newNode->data=data;
  newNode->next=NULL;

  struct node<T> * current;
  current = head;

  while (current->next != NULL) {
   current = current->next;
  }
  current->next=newNode;
}

template<typename T>
int countItem(struct node<T> * head){
  struct node<T> * current = head;
  int count = 0;
  while (current!=NULL) {
    count++;
    current=current->next;
  }
  return count;
}

template<typename T>
struct node<T> * deleteNode(struct node<T> * head,int position){
  
  if (position<1 || position> countItem<T>(head)) return head;
  if(position == 1){
    head = head->next;
    return head;
  }
  struct node<T> *current,*prev,*next;
  prev = head;
  current = prev->next;
  next = current->next;

  for(int i = 2;i!=position;i++){
    prev=current;
    current=next;
    next=next->next;
  }

  prev->next=next;
  return head; 
}

template<typename T>
void updateItem(struct node<T> * head,int position,T newData){
  if(position <1 || position>countItem(head)) return;
  struct node<T> *current;
  current = head;
  for(int i = 1 ; i!=position ;i++){
    current=current->next;
  }
  current->data=newData;
}


template<typename T>
void printList(struct node<T> * head){
  struct node<T> * current = head;
  while (current!=NULL) {
    cout<<current->data<<endl;
    current=current->next;
  }
}

int main()
{
  struct node<int> * head = (struct node<int> * ) malloc(sizeof(struct node<int>));
  head->data=2;
  head->next=NULL;
  insertNode<int>(head, 3);
  insertNode<int>(head, 4);
  insertNode<int>(head, 5);
  insertNode<int>(head, 6);
  head=deleteNode<int>(head, 4);
  updateItem(head, 1, 1);
  printList<int>(head);
  return 0;
}
