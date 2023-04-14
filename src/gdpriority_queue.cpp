#include "gdpriority_queue.h"

void PriorityQueue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("enqueue", "obj", "priority"), &PriorityQueue::enqueue);
    ClassDB::bind_method(D_METHOD("dequeue"), &PriorityQueue::dequeue);
    ClassDB::bind_method(D_METHOD("front"), &PriorityQueue::front);
    ClassDB::bind_method(D_METHOD("back"), &PriorityQueue::back);
    ClassDB::bind_method(D_METHOD("is_empty"), &PriorityQueue::is_empty);
    ClassDB::bind_method(D_METHOD("size"), &PriorityQueue::size);
}

void PriorityQueue::enqueue(Variant obj, float priority) {
    queue.push_back(obj);
    priorities.push_back(priority);
}

Variant PriorityQueue::dequeue() {
    Variant element;
    float current_highest_priority = 0.0;
    for (int i = 0; i < queue.size(); i++) {
        float priority = priorities[i];
        if (priority > current_highest_priority) {
            element = queue[i];
        }
    }
    return element;
}

Variant PriorityQueue::front() {
    return queue.front();
}

Variant PriorityQueue::back() {
    return queue.back();
}

bool PriorityQueue::is_empty() {
    return queue.empty();
}

int PriorityQueue::size() {
    return queue.size();
}
