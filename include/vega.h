

#include <time.h>

#include "statistics.h"
#include "eventloop.h"

namespace vega {

  namespace core {

    enum VegaKeyFormat {
      PEM, PKCS_7, PKCS_12, DER
    };

    class VegaServer {

      private:
        class vega_stats statistics;
        time_t process_started;     /* when the process was started */
        VegaEventloopManager event_loop;
        VegaServerSslContext ssl_context;
    };
  }
}
