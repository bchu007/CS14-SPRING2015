#ifndef _NODELIST_
#define _NODELIST_

using namespace std;

template <typename T>
// typedef string T;

class Node {
    public:
        T data;
        Node<T> *next;
        Node(T data) : data(data), next(0) {}
};

template <typename T>
class List {
    public: 
        //constructors
        List() {
            head = 0;
            tail = 0;
        }
        
        List(const T & str) {
            
            Node<T>* temp = new Node<T>(str);
            head = temp;
            tail = temp;
        }
        //destructor
        ~List() {
            while(head) {
                Node<T> *temp = head;
                head = temp->next;
                delete temp;
            }
        }
        
        int size() const{
            Node<T>* ptr = head;
            int size = 0;
            while(ptr) {
                
                size++;
                ptr = ptr->next;
            }
            return size;
            
        }
        
        void push(T str) {
            
            if(head == 0) {
                Node<T>* temp = new Node<T>(str);
                head = temp;
                tail = temp;
            }
            Node<T>* temp = new Node<T>(str);
            tail->next = temp;
            tail = temp;
        }
        void Rotate(int k) {
            if(head == tail) {
                return;
            }
            
            Node<T>* temp = head;
            int sz = size();
           

            if(k >= sz) {
                cout << "k is larger than the link list, cannot rotate" << endl;
                return;
                
            }
            Node<T>* goal = head;
            
            for(unsigned i = 0; i < k; i++) {
                goal = goal->next;
            }
            
            
            while(head != goal) {
                tail->next = head;
                tail = head;
                head = head->next;
            }
            tail->next = NULL;
            head = goal;
            
        

        }
        
        
        void display() {
            Node<T>* temp = head;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
       
        void pop_front() {
            if(head == NULL) {
                return;
            }
            
            Node<T>* temp = head;
            head = temp->next;
            delete temp;
        
        }
        
        void elementSwap(int pos) {
            
            Node<T>* curr;
            Node<T>* next;
            Node<T>* after;
            Node<T>* pred;
            Node<T>* ptr = head; 
            int counter = 0;
            
            int sz = size(); //exceeds index
            if(pos >= sz - 1) {
                cout << "Error: not a valid index" << endl;
                return;
            }
            
            if(sz < 2) { //list has one or less nodes, do nothing
                return;
            }
            
            if(pos == 0) {  //first node swap, change head
                curr = head;
                next = ptr->next;
                next->next = head;
                head = next;
                
                
                if(sz == 2) {
                    tail = head->next;
                    head->next = NULL;
                }
                else {
                    after = next->next;
                    curr->next = after;
                }
                return;
            }
            
            do {
                pred = ptr;
                ptr = ptr->next;
                counter++;
                
                if(counter == pos) {
                    if(ptr->next != tail) {

                        next = ptr->next;
                        after = next->next;
                        
                        pred->next = next;
                        next->next = ptr;
                        ptr->next = after;
                        
                    }
                    else {
                        next = ptr->next;
                        
                        pred->next = next;
                        next->next = ptr;

                        ptr->next = NULL;
                        tail = ptr;
                    }
                    return;
                }
                
                next = ptr->next;
                after = next->next;
                
            }while(ptr->next != tail);
            
        }
        
        //pass in List explicitly and it returns its rotated plus original 
        List operator+(const List& head2) {
            
            Node<T>* ptr = head;
            Node<T>* ptr2 = head2.head;
            List<T> store(0);
            
            
            while(ptr && ptr2) {
                store.push(ptr->data + ptr2->data);
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
            store.pop_front();
            return store;
        } 
        
        
    private:
        Node<T>* head;
        Node<T>* tail;
};

#endif
