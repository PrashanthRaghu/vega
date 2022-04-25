


/* An item in the connection queue. */
enum vega_conn_queue_item_modes {
    queue_new_conn,   /* brand new connection. */
    queue_pause,      /* pause thread */
    queue_timeout,    /* socket sfd timed out */
    queue_redispatch, /* return conn from side thread */
    queue_stop,       /* exit thread */
    queue_return_io,  /* returning a pending IO object immediately */
#ifdef PROXY
    queue_proxy_reload, /* signal proxy to reload worker VM */
#endif
};
