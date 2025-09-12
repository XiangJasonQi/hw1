/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "split.h"

using namespace std;

int main(int argc, char* argv[])
{
  Node* in_case = nullptr; 
  Node* in_head =nullptr;
  Node* odd_case = nullptr;
  Node* even_case = nullptr;

  int original_list[4] = {1, 14,24,47};

  for(int i = 0; i < 4; i++){
    Node* new_item = new Node{original_list[i], nullptr};
    if(in_head == nullptr){
      in_head = in_case = new_item;
    } else{
      in_case->next = new_item;
      in_case = new_item;
    }
  }

  split(in_head, odd_case, even_case);

  cout << "even list" << endl;

  Node* temp = odd_case;
  
  while(temp != nullptr){
    cout << temp->value << endl;
    temp = temp->next;
  }

  temp = even_case;

  cout << "odd list" << endl;

  while(temp != nullptr){
    cout << temp->value << endl;
    temp = temp->next;
  }

  delete temp;

  while(in_head != nullptr){
    Node* delete_temp = in_head;
    in_head = in_head->next;
    delete delete_temp;
  }

  while(odd_case != nullptr){
    Node* delete_temp = odd_case;
    odd_case = odd_case->next;
    delete delete_temp;
  }

  while(even_case != nullptr){
    Node* delete_temp = even_case;
    even_case = even_case->next;
    delete delete_temp;
  }
  
}
