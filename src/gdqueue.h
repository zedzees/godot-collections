#ifndef GDQUEUE_H
#define GDQUEUE_H

#ifdef WIN32
#include <windows.h>
#endif

#include <queue>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;
using namespace std;

class Queue : public RefCounted {
    GDCLASS(Queue, RefCounted);
public:
    void push(Variant obj);
    void enqueue(Variant obj);
    Variant dequeue();
    Variant front();
    Variant back();
    int size();
    bool is_empty();

protected:
    static void _bind_methods();

private:
    queue<Variant> q;
};
#endif