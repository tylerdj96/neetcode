#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    int val_;
    Node *next_;

public:
    Node(int val)
    {
        val_ = val;
        next_ = nullptr;
    }

    int getValue()
    {
        return val_;
    }

    Node *getNext()
    {
        return next_;
    }

    Node *setNext(Node *next)
    {
        return next_ = next;
    }

    bool hasNext()
    {
        return next_ != nullptr;
    }
};

class LinkedList
{
private:
    Node *head_;
    Node *tail_;

public:
    LinkedList()
    {
        head_ = nullptr;
        tail_ = nullptr;
    }

    int get(int index)
    {
        if (head_ == nullptr)
        {
            return -1;
        };

        int counter = 0;
        Node *itr = head_;

        while (counter != index)
        {
            if (itr == nullptr)
            {
                return -1;
            }
            itr = itr->getNext();
            counter++;
        }

        if (itr == nullptr)
        {
            return -1;
        }

        return itr->getValue();
    }

    void insertHead(int val)
    {
        Node *node = new Node(val);
        if (tail_ == nullptr)
        {
            tail_ = node;
        }
        if (head_ != nullptr)
        {
            node->setNext(head_);
        }
        head_ = node;
    }

    void insertTail(int val)
    {
        Node *node = new Node(val);
        if (head_ == nullptr)
        {
            head_ = node;
        }
        if (tail_ != nullptr)
        {
            tail_->setNext(node);
        }
        tail_ = node;
    }

    bool remove(int index)
    {
        int counter = 0;

        // empty list
        if (head_ == nullptr)
        {
            return false;
        }

        // deleting head
        if (index == 0)
        {
            Node *temp = head_;
            if (head_->hasNext())
            {
                head_ = head_->getNext();
            }
            else
            {
                head_ = nullptr;
            }
            delete temp;
            return true;
        }

        Node *itr = head_;

        // iterate until we are at the node before the one we want to delete
        while (counter < index - 1)
        {
            if (itr->getNext() == nullptr)
            {
                return false;
            }
            itr = itr->getNext();
            counter++;
        }

        // Node to be deleted doesn't exist
        if (!itr->hasNext())
        {
            return false;
        }

        Node *nodeToDelete = itr->getNext();

        if (nodeToDelete->hasNext())
        {
            Node *nextNode = nodeToDelete->getNext();
            itr->setNext(nextNode);
        }

        delete nodeToDelete;

        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;

        if (head_ == nullptr)
        {
            return values;
        }

        Node *itr = head_;
        values.push_back(head_->getValue());
        while (itr->hasNext())
        {
            values.push_back(itr->getNext()->getValue());
            itr = itr->getNext();
        }
        return values;
    }
};