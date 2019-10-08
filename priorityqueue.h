#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <ostream>
#include <istream>
#include <initializer_list>

template <class Item,class Grade>
class PriorityQueue
{
    struct Element{
        Element* next;
        Item item;
    };
    struct Grading{
        Grading* next;
        Grade grade;
        Element* gradeQueueEnd;
    };

    Element* head;
    Grading* gradings;
    Grade defaultGrade_;

public:
    PriorityQueue();
    PriorityQueue(const std::initializer_list list);
    ~PriorityQueue();
    Item pop();
    void push(Item item,Grade grade);
    void push(Item item);
    void setDefaultGrade(Grade grade);
    Grade defaultGrade();
    
    Item operator[](int index);
    void operator=(PriorityQueue queue);
    friend std::ostream& operator<< (std::ostream& stream,PriorityQueue& queue);
    friend std::istream& operator>> (std::istream& stream,PriorityQueue& queue);
};

template <class Item,class Grade>
std::ostream operator<< (std::ostream& stream,PriorityQueue<Item,Grade>& queue);

template <class Item,class Grade>
std::istream operator>> (std::istream& stream,PriorityQueue<>& queue);

#endif // PRIORITYQUEUE_H

