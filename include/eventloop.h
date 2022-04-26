

#include <event2/event.h>

namespace vega {
  namespace loop {

    class VegaEventloopManager {
      private:
        struct event_base vega_loop;

      public:
        void conn_listener(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *user_data);
        void conn_writecb(struct bufferevent *bev, void *user_data);
        void conn_eventcb(struct bufferevent *bev, short events, void *user_data);
    };
  }
}
