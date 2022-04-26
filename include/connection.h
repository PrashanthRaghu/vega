#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#include "vega_types.h"
#include "object.h"

namespace vega {

  namespace connmanager {

    class VegaConnStats {
      private:
        char *buffer;
        size_t size;
        size_t offset;
    };


    class VegaConnSslAttributes {
      private:
        SSL    *ssl;
        char   *ssl_wbuf;
        bool ssl_enabled;
    };

    class VegaConn {
      private:
        struct VegaBaseObject *base;
        int socket_file_descriptor;
        struct sockaddr *sa;
        int state;
        int connection_timeout; /** Timeout the connection in case of inactivity */

        bool set_stale;
        bool mset_res; /** uses mset format for return code */
        bool close_after_write; /** flush write then move to close connection */
        bool rbuf_malloced; /** read buffer was malloc'ed for ascii mget, needs free() */
        bool item_malloced; /** item for conn_nread state is a temporary malloc */

        vega_conn_ssl_attributes attributes;

        enum conn_states  state;
        enum bin_substates substate;

        rel_time_t last_cmd_time;
        struct event event;
        short  ev_flags;
        short  which;   /** which events were just triggered */

        char   *rbuf;   /** buffer to read commands into */
        char   *rcurr;  /** but if we parsed some already, this is where we stopped */
        int    rsize;   /** total allocated size of rbuf */
        int    rbytes;  /** how much data, starting from rcur, do we have unparsed */

        mc_resp *resp; // tail response.
        mc_resp *resp_head; // first response in current stack.
        char   *ritem;  /** when we read in an item's value, it goes here */
        int    rlbytes;

        /* data for the swallow state */
        int    sbytes;    /* how many bytes to swallow */

        int io_queues_submitted; /* see notes on io_queue_t */
        io_queue_t io_queues[IO_QUEUE_COUNT]; /* set of deferred IO queues. */

        enum vega_network_transport transport; /* what transport is used by this connection */
        enum vega_close_reasons close_reason; /* reason for transition into conn_closing */

        /* data for UDP clients */
        int    request_id; /* Incoming UDP request ID, if this is a UDP "connection" */
        struct sockaddr_in6 request_addr; /* udp: Who sent the most recent request */
        socklen_t request_addr_size;

        bool noreply;   /* True if the reply should not be sent. */
        /* current stats command */

        uint64_t cas; /* the cas to return */
        int opaque;
        int keylen;

        vega_conn *next;     /* Used for generating a list of conn structures */
        LIBEVENT_THREAD *thread; /* Pointer to the thread object serving this connection */

      public:
        ssize_t read(vega_conn *c, void *buf, size_t count);
        ssize_t sendmsg(vega_conn *c, struct msghdr *msg, int flags);
        ssize_t write(vega_conn *c, void *buf, size_t count);
    };
  }
}
