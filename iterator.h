#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>*> order;
    public:
        Iterator() {
            this->current=nullptr;            
        }

        Iterator(Node<T> *node,int flag) {
            if(!flag){
                while(node){
                    order.push(node);
                    node=node->left;
                }
            }
            else
            {
                while(node){
                    node=node->right;
                }
            }
            this->current=node;
        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            this->current=other->current;
            return (*this);
        }

        bool operator!=(Iterator<T> other) {
            return(this->current!=other.current);
        }

        Iterator<T>& operator++() {
            Node<T>* temp=order.top();
            order.pop();
            if(temp->right){
                order.push(temp->right);
                while(order.top()->left){
                    order.push(order.top()->left);
                }
            }
            if(!order.empty())
                current=order.top();
            else
                current=nullptr;
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            if(current)
                return current->data;
            else
            {
                throw out_of_range("Passed index!");
            }
            
        }
};

#endif
