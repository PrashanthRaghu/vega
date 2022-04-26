

#include "type.h"

struct vega_base_object {
  vega_type* type;
  uint32_t refcount;
};


#define VEGA_INCREF(vega_base_object* obj) obj->refcount++;

#define VEGA_DECREF(vega_base_object* obj)
