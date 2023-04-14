#include "gdqueue.h"

void Queue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "obj"), &Queue::push);
    ClassDB::bind_method(D_METHOD("enqueue", "obj"), &Queue::enqueue);
    ClassDB::bind_method(D_METHOD("dequeue"), &Queue::dequeue);
    ClassDB::bind_method(D_METHOD("front"), &Queue::front);
    ClassDB::bind_method(D_METHOD("back"), &Queue::back);
    ClassDB::bind_method(D_METHOD("is_empty"), &Queue::is_empty);
    ClassDB::bind_method(D_METHOD("size"), &Queue::size);
}

void Queue::push(Variant obj) {
    q.push(obj);
}

void Queue::enqueue(Variant obj) {
    q.emplace(obj);
}

Variant Queue::dequeue() {
    Variant element = q.front();
    q.pop();
    return element;
}

Variant Queue::front() {
    return q.front();
}

Variant Queue::back() {
    return q.back();
}

bool Queue::is_empty() {
    return q.empty();
}

int Queue::size() {
    return q.size();
}
