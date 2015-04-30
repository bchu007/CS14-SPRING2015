// -*- bst.h -*-
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;


#define nil 0

// #define Value int // restore for testing.
template <typename Value>
class BST {
    class Node { // binary tree node
        public:
            Node* left;
            Node* right;
            Value value;
            Node( const Value v = Value() )
            : value(v), left(nil), right(nil) {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() {
            // returns the height of the subtree rooted at this node
                return findHeight(this);
            }
            
            
            int size() {
            // returns the size of the subtree rooted at this node,
                return findSize(this);
            }
              
        private: 
            int findHeight(Node* p) {
                if(p == nil) {
                    return -1;
                }
               if(findHeight(p->left) > findHeight(p->right)) {
                   return findHeight(p->left) + 1;
               }
               return findHeight(p->right) + 1;
                
            }
            
            int findSize(Node* p) {
                if(p == nil) {
                    return 0;
                }
                else {
                    return (findSize(p->left) + findSize(p->right)) + 1;
                }
            }
            
            
            
    }; // Node
    // const Node* nil; // later nil will point to a sentinel node.
    Node* root;
    int count;
    public:
        int size() {
        // size of the overall tree.
            return size(root);
        }
        int size( Node* p ) {
            if(p == nil) {
                return 0; 
            }
            else {
                return (size(p->left) + size(p->right)) + 1;
            }
        }
        bool empty() { return size() == 0; }
        void print_node( const Node* p ) {
        // Print the node’s value.
            cout << p->value << flush;
            return;
        }
        bool search ( Value x ) {
        // search for a Value in the BST and return true iff it was found.
            return search(x, root);
        }
        bool search(Value x, Node* p) {
            if(p == nil) {
                return false;
            }
            if(p->value == x) {
                return true;
            }
            inorder(p->left);
            inorder(p);
            inorder(p->right);
        }
        void preorder()const {
        // Traverse and print the tree one Value per line in preorder.
            preorder(root);
        }
        void preorder(Node* p) {
            if(p == nil) {
                return;
            }
            print_node(p);
            preorder(p);
            preorder(p->left);
            preorder(p->right);
        }
        void postorder()const {
        // Traverse and print the tree one Value per line in postorder.
            postorder(root);
        }
        void postorder(Node* p) {
            if(p == nil) {
                return;
            }
            print_node(p);
            postorder(p->left);
            postorder(p->right);
            postorder(p);
        }
        void inorder()const {
        // Traverse and print the tree one Value per line in inorder.
            inorder(root);
        }
        void inorder(Node* p) {
            if(p == nil) {
                return;
            }
            print_node(p);
            inorder(p->left);
            inorder(p);
            inorder(p->right);
        }
        Value& operator[] (int n) {
        // returns reference to the value field of the n-th Node.
            p[root, n];
        }
        Value& operator[] (Node* p, int n) {
        // returns reference to the value field of the n-th Node.
            if(n == 0) {
                return p;
            }
            inorder(p->left, n - 1);
            inorder(p, n - 1);
            inorder(p->right, n - 1);
        
        }
        
        BST() : count(0), root(nil) {}
        void insert( Value X ) { root = insert( X, root ); }
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
        if ( T != nil ) {
            if ( X > T->value ) {
                T->right = remove( X, T->right );
            } else if ( X < T->value ) {
                T->left = remove( X, T->left );
            } else { // X == T->value
                if ( T->right != nil ) {
                    Node* x = T->right;
                while ( x->left != nil ) x = x->left;
                T->value = x->value; // successor’s value
                T->right = remove( T->value, T->right );
                } else if ( T->left != nil ) {
                    Node* x = T->left;
                while ( x->right != nil ) x = x->right;
                T->value = x->value; // predecessor’s value
                T->left = remove( T->value, T->left );
                } else { // *T is external
                delete T;
                T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
        }
        void okay( ) { okay( root ); }
        void okay( Node* T ) {
        // diagnostic code can be installed here
        return;
        }
    }; // BST
#endif