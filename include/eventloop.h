

#include <event2/event.h>


struct vega_eventloop_manager {
  struct event_base vega_loop;
  
};


void vega_connection_listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *user_data);
void vega_conn_writecb(struct bufferevent *bev, void *user_data);
void vega_conn_eventcb(struct bufferevent *bev, short events, void *user_data);
void vega_signal_cb(evutil_socket_t sig, short events, void *user_data);
