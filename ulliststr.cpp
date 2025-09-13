#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if(head_ == nullptr){
    Item* new_item = new Item();

    head_ = tail_ = new_item;

    tail_->val[tail_->first] = val;
    tail_->last++;

  } else if (tail_->last == ARRSIZE){
    Item* new_item = new Item();
    tail_->next = new_item;
    new_item->prev = tail_;
    tail_ = new_item;

    tail_->val[tail_->last] = val;
    tail_->last++;

  } else{
    tail_->val[tail_->last] = val;
    tail_->last++;

  }
  size_++;

}

void ULListStr::push_front(const std::string& val){
  if(head_ == nullptr){
    Item* new_item = new Item();

    head_ = tail_ = new_item;

    new_item->val[new_item->first] = val;
    new_item->last++;

  } else if(head_->first > 0){
    head_->first--;
    head_->val[head_->first]  = val;

  } else {
    Item* new_item = new Item();
    new_item->next = head_;
    head_->prev = new_item;
    new_item->next = head_;
    head_ = new_item;
    
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;

    head_->val[head_->first] = val;

  }

  size_++;
}

void ULListStr::pop_back(){
  if(head_ == nullptr){
    return;
  } 
  
  tail_->last--;
  size_--;
  
  if(tail_->prev == nullptr && tail_->last == tail_->first){
    delete head_;
    head_ = tail_ = nullptr;
  } else if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    delete temp;

  }

}

void ULListStr::pop_front(){
  if(head_ == nullptr){
    return;
  } 

  head_->first++;
  size_--;

  if(head_->next == nullptr && head_->first == head_->last){
    delete head_;
    head_ = tail_ = nullptr;
  } else if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete temp;
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(head_ == nullptr || loc >= size_){
    return NULL;
  }

  if(loc < (head_->last - head_->first)){ 
    return &head_->val[head_->first + loc];

  } else{
    size_t remain = loc - (head_->last - head_->first);
    Item* temp = head_->next;

    if(temp == nullptr) return NULL;

    remain = helper_get_loc(remain, temp);

    return &temp->val[temp->first + remain];

    }
}

size_t ULListStr::helper_get_loc(size_t loc, Item*& temp) const{

  size_t used = temp->last - temp->first; 
  
  if(loc < used ){
    return loc;
  }

    loc = loc -used;
    temp = temp->next;
    return helper_get_loc(loc, temp);
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
