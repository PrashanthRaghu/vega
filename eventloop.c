
/*


 Authors: Prashanth Raghu
*/
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#ifndef _WIN32
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/inet.h>
# endif
#include <sys/socket.h>
#endif

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>


void eventloop_init() {
  #if defined(LIBEVENT_VERSION_NUMBER) && LIBEVENT_VERSION_NUMBER >= 0x02000101
      struct event_config *ev_config;
      ev_config = event_config_new();
      event_config_set_flag(ev_config, EVENT_BASE_FLAG_NOLOCK);
      me->base = event_base_new_with_config(ev_config);
      event_config_free(ev_config);
  #else
      me->base = event_init();
  #endif

}
