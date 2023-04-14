#ifndef GDPRIORITY_QUEUE_H
#define GDPRIORITY_QUEUE_H

#ifdef WIN32
#include <windows.h>
#endif

#include <vector>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;
using namespace std;

class PriorityQueue : public RefCounted {
    GDCLASS(PriorityQueue, RefCounted);
public:
    void enqueue(Variant obj, float priority);
    Variant dequeue();
    Variant front();
    Variant back();
    int size();
    bool is_empty();

protected:
    static void _bind_methods();

private:
    vector<Variant> queue;
    vector<float> priorities;
};
#endif