

#include "vega_types.h"

typedef uint32_t blocksize;

struct vega_arena {
  void* memory_chunk; /**  Memory block **/
  struct vega_arena* next; /** Linked list of arenas **/
};

struct vega_pool {
  blocksize size;
  uint32_t alloc_count;

  struct vega_arena* belongs_to;
};

struct vega_mem_manager {
  void* (alloc_function*)();
  void* (dealloc_function*)();
};

vega_mem_manager vega_raw_mem_manager = {
  raw_memory_alloc,
  raw_memory_dealloc
};


vega_mem_manager vega_obj_manager = {

}

void* raw_memory_alloc();

void* raw_memory_dealloc();

void* raw_memory_alloc();

void* raw_memory_dealloc();
