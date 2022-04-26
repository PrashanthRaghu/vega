

#include "vega_types.h"
#include "type.h"

namespace vega {

  class vega_base_object {
    private:
      vega_type* type;
      uint32_t refcount;
      vega_base_object *prev;
      vega_base_object *next;
    public:
      void incref();
      void decref();
  };
}
