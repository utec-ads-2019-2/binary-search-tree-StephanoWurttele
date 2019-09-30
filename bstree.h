#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    int sizee;
    int deep;

void traversePreOrder(Node<T>* newroot) {
            Node<T>* temp=newroot;
            cout<<temp->data<<" ";
            if (temp->left)
                this->traversePreOrder(temp->left);
            if (temp->right)
                this->traversePreOrder(temp->right);
            return;
        }


        void traverseInOrder(Node<T>* newroot) {
            Node<T>* temp=newroot;
            if (temp->left)
                this->traverseInOrder(temp->left);
            cout<<temp->data<<" ";
            if (temp->right)
                this->traverseInOrder(temp->right);
            return;
        }

        void traversePostOrder(Node<T>* newroot) {
            Node<T>* temp=newroot;
            if (temp->left)
                this->traversePostOrder(temp->left);
            if (temp->right)
                this->traversePostOrder(temp->right);
            cout<<temp->data<<" ";
            return;
        }


    public:
        BSTree() : root(nullptr) {
            this->deep=-1;
            this->sizee=0;
        };

        Node<T>* getroot(){
            return root;
        }

        bool find(T data) {
            if(!root)
                return false;
            Node<T>* temp=root;
            while(temp->data!=data){
                if(data>temp->data){
                    if(temp->right!=nullptr){
                        temp=temp->right;
                    }
                    else
                        return false;
                }
                else if(data<temp->data){
                    if(temp->left!=nullptr){
                        temp=temp->left;
                    }
                    else
                        return false;
                }
            }
            return true;
        } 

        void insert(T data) {
            this->sizee++;
            Node<T>* newNode= new Node<T>(data);
            Node<T>* temp=this->root;
            int heightt=0;
            while(true){
                if(root){
                    heightt++;
                    if(data<=temp->data){
                        if(temp->left)
                            temp=temp->left;
                        else{
                            temp->left=newNode;
                            
                            break;
                        }
                    }
                    else{
                        if(temp->right!=nullptr){
                            temp=temp->right;
                        }
                        else{
                            temp->right=newNode;
                            break;
                        }
                    }
                }
                else{
                    root=newNode;
                    break;
                }
            }
            if(heightt>this->deep){
                this->deep=heightt;
            }
        }

        // Este código se puede reducir bastante, tienes varias partes repetidas
        bool remove(T data) {
            if(!root){
                return false;
            }
            Node<T>* tempparent=root;
            Node<T>* temp=root;
            while(temp->data!=data){
                if(data>temp->data){
                    if(temp->right!=nullptr){
                        tempparent=temp;
                        temp=temp->right;
                    }
                    else
                        return false;
                }
                else if(data<temp->data){
                    if(temp->left!=nullptr){
                        tempparent=temp;
                        temp=temp->left;
                    }
                    else
                        return false;
                }
            }
            Node<T>* temp2=temp;
            if(temp==root){
                if(sizee==1){
                    root=nullptr;
                }
                else if(temp->right){
                    if(!temp->left)
                        root=temp->right;
                    else
                    {
                        tempparent=temp;
                        temp=temp->left;
                        while(temp->right){
                            tempparent=temp;
                            temp=temp->right;
                        }
                        temp2->data=temp->data;
                        if(tempparent->right==temp)
                            tempparent->right=temp->left;
                        else 
                            tempparent->left=temp->left;
                    }
                }
                else
                    if (temp->left)
                        root=temp->left;
                delete temp;
                this->sizee--;
                return true;
            }
            if(!(temp->left)){
                if(!(temp->right)){
                    if(tempparent){
                        if (tempparent->right==temp)
                            tempparent->right=nullptr;
                        else
                            tempparent->left=nullptr;
                    }
                    delete temp;
                }
                else{
                    if(tempparent->right==temp)
                        tempparent->right=temp->right;
                    else 
                        tempparent->left=temp->right;
                    delete temp;
                }
            }
            else{
                if(!temp->right){
                    if(tempparent->right==temp)
                        tempparent->right=temp->left;
                    else 
                        tempparent->left=temp->left;
                    delete temp;
                }
                else{
                    tempparent=temp;
                    temp=temp->left;
                    while(temp->right){
                        tempparent=temp;
                        temp=temp->right;
                    }
                    temp2->data=temp->data;
                    if(tempparent->right==temp)
                        tempparent->right=temp->left;
                    else 
                        tempparent->left=temp->left;
                    delete temp;
                }
            }
            this->sizee--;
            return true;
        }

        size_t size() {
            return this->sizee;
        }

        int height() {
            return (this->deep);
        }

        void traversePreOrder() {
            if(this->root)
                traversePreOrder(this->root);
            else
            {
                cout<<"Empty!";
            }
            
        return;
        }

        void traverseInOrder() {
            if(this->root)
                traverseInOrder(this->root);
            else
            {
                cout<<"Empty!";
            }
            return;
        }

        void traversePostOrder() {
            if(this->root)
                traversePostOrder(this->root);
            else
            {
                cout<<"Empty!";
            }
            return;
        }

        Iterator<T> begin() {
            return {root,0};
        }

        Iterator<T> end() { 
            return {root,1};
        }

        ~BSTree() {
            // Falta destructor
            // TODO
        }
};

#endif
