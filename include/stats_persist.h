
#include "statistics.h"

enum vega_persist_options {
  FILE,
  REDIS
};

struct vega_backend_operations {
  int (writefunc*) (vega_stats* stats);
  void (errorhandler*)();
};

struct vega_connector_object {
    File f;

};

struct redis_connector {
  

}
