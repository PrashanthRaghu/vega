

struct vega_stats {
    uint64_t      total_conns;
    uint64_t      rejected_conns;
    uint64_t      malloc_fails;
    uint64_t      listen_disabled_num;
    uint64_t      time_in_listen_disabled_us;  /* elapsed time in microseconds while server unable to process new connections */
    uint64_t      log_worker_dropped; /* logs dropped by worker threads */
    uint64_t      log_worker_written; /* logs written by worker threads */
    uint64_t      log_watcher_skipped; /* logs watchers missed */
    uint64_t      log_watcher_sent; /* logs sent to watcher buffers */
#ifdef TLS
    uint64_t      ssl_handshake_errors; /* TLS failures at accept/handshake time */
    uint64_t      ssl_new_sessions; /* successfully negotiated new (non-reused) TLS sessions */
#endif
    struct timeval maxconns_entered;  /* last time maxconns entered */
    uint64_t       round_robin_fallback; /* see doc/napi_ids.txt */
};
