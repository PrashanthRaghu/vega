

#include "vega_types.h"
#include "object.h"

class vega_type {
  char* name;
  char* documentation;

  void (dealloc*)(vega_base_object* object);
  vega_base_object* (alloc*)();
};
