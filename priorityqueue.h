#include <map>
#include <utility>


using namespace std;

typedef float Priority;
template <typename Item>


class priorityqueue: public multimap<Priority, Item> {
  public:
    priorityqueue() {
        
    }
    
    
    Item& front() {
        typename multimap<Priority, Item>::iterator it = Queue.begin();
        return it->second;
    }
    
    void pop() {
        Queue.erase(Queue.begin());
    }
    
    void push(Item x, Priority p) {
        Queue.insert(pair<Priority, Item>(p, x));
        
    }
    
    priorityqueue(const priorityqueue &ob) {
        multimap<Priority, Item> copy (Queue);
        
        
    }
    
    priorityqueue& operator=(const priorityqueue &ob) {
        Queue.clear();
        Queue = ob->Queue;
        return Queue;
    }
    
  private:
    multimap<Priority, Item> Queue;
    
};