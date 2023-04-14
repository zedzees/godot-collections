#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

#include "gdqueue.h"
#include "gdpriority_queue.h"

using namespace godot;

namespace godot_collections {
    void initialize_godot_collections_module(ModuleInitializationLevel p_level) {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
        }
        ClassDB::register_class<Queue>();
        ClassDB::register_class<PriorityQueue>();
    }

    void uninitialize_godot_collections_module(ModuleInitializationLevel p_level) {
        if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
        }
    }

    extern "C" {
        // Initialization.
        GDExtensionBool GDE_EXPORT godot_collections_library_init(const GDExtensionInterface *p_interface, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
            godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

            init_obj.register_initializer(initialize_godot_collections_module);
            init_obj.register_terminator(uninitialize_godot_collections_module);
            init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

            return init_obj.init();
        }
    }
}