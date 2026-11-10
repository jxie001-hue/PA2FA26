#include "sl_list.h"
// in this file, finish insert tail, remove tail, get head, get tail
SLList::SLList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

SLList::~SLList() {
    Clear();
}

void SLList::InsertHead(int head) {
    SLNode* new_node = new SLNode(head);

    new_node->set_next_node(head_);

    head_ = new_node;

    if (size_ == 0) tail_ = head_;

    size_++;
}

void SLList::InsertTail(int tail) {
    SLNode* new_node = new SLNode(tail);

    // case when there's only 1 node
    if (size_ == 0) {
        head_ = tail_ = new_node;
    } else {
        tail_->set_next_node(new_node);

        tail_ = new_node;
    }

    size_++;
}
void SLList::RemoveHead() {
    // just in case empty head_
    if (head_ == nullptr) return;

    // this is the 2nd node of the list
    SLNode* temp_node = head_->next_node();

    // erase current head
    delete head_;

    if (size_ == 1) tail_ = temp_node;

    // declear new head

    head_ = temp_node;

    // update size
    size_--;
}

void SLList::RemoveTail() {
    // just in case empty tail_
    if (tail_ == nullptr) return;

    // just incase size is 1
    if (size_ == 1) {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
        size_--;
        return;
    }

    // the second to last node
    SLNode* temp_node = head_;

    for (unsigned int x = 1; x < size_-1; x++) {
        temp_node = temp_node->next_node();
    }

    // delete the bad boy and declear the new tail 🚩
    delete tail_;

    tail_ = temp_node;

    tail_->set_next_node(nullptr);

    // update size
    size_--;
}

void SLList::Insert(int num) {
    SLNode* temp_node = new SLNode(num);

    if (size_ == 0) {
        head_ = temp_node;
        tail_ = temp_node;
    } else if (num <= head_->contents()) {
        temp_node->set_next_node(head_);
        head_ = temp_node;
    } else {
    SLNode* current = head_;
    while (current->next_node() != nullptr &&
    current->next_node()->contents() < num) {
        current = current->next_node();
    }
    temp_node->set_next_node(current->next_node());
    current->set_next_node(temp_node);

    // just in case
    if (temp_node->next_node() == nullptr) {
        tail_ = temp_node;
    }
    }

    size_++;
}

bool SLList::RemoveFirstOccurence(int num) {
    // just in case
    if (head_ == nullptr) {
        return false;
    }

    if (head_->contents() ==num) {
        SLNode* temp_node = head_;
        // shift the head
        head_ = head_->next_node();

        delete temp_node;
        size_--;

        if (head_ == nullptr) {
            tail_ = nullptr;
        }
        return true;
    }

    // time for the real stuff
    SLNode* current = head_;

    while (current->next_node() != nullptr &&
    current->next_node()->contents() != num) {
        current = current->next_node();
    }

    // just in case
    if (current->next_node() == nullptr) {
        return false;
    }
    SLNode* temp_node = current->next_node();

    current->set_next_node(temp_node->next_node());

    // just in case
    if (temp_node == tail_) {
        tail_ = current;
    }

    delete temp_node;
    size_--;

    return true;
}

int SLList::GetHead() const {
    if (head_ == nullptr) return 0;

    return head_->contents();
}

int SLList::GetTail() const {
    if (tail_ == nullptr) return 0;

    return tail_->contents();
}

void SLList::Clear() {
    while (head_ != nullptr) {
        RemoveHead();
    }

    tail_ = nullptr;
}

unsigned int SLList::size() const {
    return size_;
}

std::string SLList::ToString() const {
    std::string content = "";
    SLNode* current_node = head_;

    for (unsigned int x = 0; x < size_; x++) {
        content += std::to_string(current_node->contents());
        if (x+1 < size_) content += ", ";
        current_node = current_node->next_node();
    }

    return content;
}
