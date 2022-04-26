

#include "vega_types.h"
##include "object.h"

namespace vega {

  namespace memmanager {

    class VegaArena {
      private:
        void* memory_chunk; /**  Memory block **/
        VegaArena* next; /** Linked list of arenas **/
    };

    class VegaPool {
      private:
        size_t size;
        uint32_t alloc_count;  /** Number of allocated objects **/
        VegaArena* belongs_to; /** The arena the pool  belongs to **/
    };


    /** Inspired from Python Memory Manger **/

    class VegaMemManager {

      public:
        void* alloc_function(size_t size);
        void* calloc_function(size_t size);
        void  dealloc_function(void* block);
    };

    class RawMemManager: public VegaMemManager

    class ObjectMemManager: public vega_mem_manager

 }
}
