//
// Created by User on 14.05.2022.
//

#ifndef LAB2PRJ_LINKEDLISTSEQUENCE_HPP
#define LAB2PRJ_LINKEDLISTSEQUENCE_HPP
#include "IndexOutOfRange.hpp"
#include "Sequence.hpp"
#include <iostream>
#include "LinkedList.hpp"
template <class T> class LinkedListSequence: public Sequence<T>{
private:
    LinkedList<T>* list;

public:
    LinkedListSequence (T* items, int count){
        list = new LinkedList<T>(items,count);
    }
public:
    LinkedListSequence (){
        list = new LinkedList<T>();
    }
public:
    explicit LinkedListSequence (const LinkedList <T> & outer_list){
        list = new LinkedList<T>(outer_list);
    }
public:
    ~LinkedListSequence() = default;    //delete list;
public:
    LinkedListSequence<T>& operator=(const LinkedList <T> & outer_list){
        if (this!=nullptr && this->list!=nullptr){
            delete this->list;
        }
        list = new LinkedList<T>(outer_list);
        return *this;
    }
public:
    T GetFirst() const override{
        return list->GetFirst();
    }
public:
    T GetLast() const override{
        return list->GetLast();
    }
public:
    T Get(size_t i) const override{
        return list->Get(i);
    }
public:
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override{
        auto* new_list = new LinkedListSequence<T> (*this->list->GetSubList(startIndex,endIndex));
        return new_list;
    }
public:
    size_t GetLength() override{
        return list->GetLength();
    }
public:
    void Append(T item) override{
        list->Append(item);
    }
public:
    void Prepend(T item) override{
        list->Prepend(item);
    }
public:
    void InsertAt(T item, size_t index) override{
        list->InsertAt(item,index);
    }
public:
    Sequence <T>* Concat(Sequence <T> *outer_list) override{
        for( int i = 0;i<outer_list->GetLength();i++){
            list->Append(outer_list->Get(i));
        }
        return this;
    }
public:
    void Set(T item,size_t index) override{
        list->Set(item,index);
    }
};
#endif //LAB2PRJ_LINKEDLISTSEQUENCE_HPP

