

#if defined(__BEOS__)
# define VEGA_OS_BEOS
#elif (defined(__APPLE__) && defined(__GNUC__)) || defined(__MACOSX__)
# define VEGA_OS_MACOSX
#elif defined(__NetBSD__)
# define VEGA_OS_NETBSD
#elif defined(__FreeBSD__)
# define VEGA_OS_FREEBSD
#elif defined(__OpenBSD__)
# define VEGA_OS_OPENBSD
#elif defined(__sgi)
# define VEGA_OS_IRIX
#elif defined(__AIX)
# define VEGA_OS_AIX
#elif defined(__LINUX__) || defined(__linux__) || defined(__linux)
# define VEGA_OS_LINUX
#elif defined(__SUN__) || defined(__sun) || defined(sun)
# define VEGA_OS_SOLARIS
#elif defined(__hpux__) || defined(__hpux)
# define VEGA_OS_HPUX
#elif defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
# define VEGA_OS_WINDOWS
# define VEGA_OS_WIN64
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
# define VEGA_OS_WINDOWS
# define VEGA_OS_WIN32
#else
# warning "unknown OS, please report this"
#endif

namespace vega {

  namespace settings {
    class vega_port_manager {
      private:
        int identifier;
        int port;
        vega_protocol protocol;
    };

    class vega_server_settings {
      private:
        size_t maxbytes;
        int maxconns;
        vega_port_manager* ports;
        char *inter;
        int verbose;
        rel_time_t oldest_live; /* ignore existing items older than this */
        uint64_t oldest_cas; /* ignore existing items with CAS values lower than this */
        int evict_to_free;
        char *socketpath;   /* path to unix socket if using local socket */
        char *auth_file;    /* path to user authentication file */
        int access;  /* access mask (a la chmod) for unix domain socket */
        double factor;          /* chunk size growth factor */
        int chunk_size;
        int num_threads;        /* number of worker (without dispatcher) libevent threads to run */
        int num_threads_per_udp; /* number of worker threads serving each udp socket */
        char prefix_delimiter;  /* character that marks a key prefix (for stats) */
        int detail_enabled;     /* nonzero if we're collecting detailed stats */
        int reqs_per_event;     /* Maximum number of io to process on each
                                   io-event. */
        bool use_cas;
        enum protocol binding_protocol;
        int backlog;
        int item_size_max;        /* Maximum item size */
        int slab_chunk_size_max;  /* Upper end for chunks within slab pages. */
        int slab_page_size;     /* Slab's page units. */
        volatile sig_atomic_t sig_hup;  /* a HUP signal was received but not yet handled */
        bool sasl;              /* SASL on/off */
        bool maxconns_fast;     /* Whether or not to early close connections */
        bool lru_crawler;        /* Whether or not to enable the autocrawler thread */
        bool lru_maintainer_thread; /* LRU maintainer background thread */
        bool lru_segmented;     /* Use split or flat LRU's */
        bool slab_reassign;     /* Whether or not slab reassignment is allowed */
        int slab_automove;     /* Whether or not to automatically move slabs */
        double slab_automove_ratio; /* youngest must be within pct of oldest */
        unsigned int slab_automove_window; /* window mover for algorithm */
        int hashpower_init;     /* Starting hash power level */
        bool shutdown_command; /* allow shutdown command */
        int tail_repair_time;   /* LRU tail refcount leak repair time */
        bool flush_enabled;     /* flush_all enabled */
        bool dump_enabled;      /* whether cachedump/metadump commands work */
        char *hash_algorithm;     /* Hash algorithm in use */
        int lru_crawler_sleep;  /* Microsecond sleep between items */
        uint32_t lru_crawler_tocrawl; /* Number of items to crawl per run */
        int hot_lru_pct; /* percentage of slab space for HOT_LRU */
        int warm_lru_pct; /* percentage of slab space for WARM_LRU */
        double hot_max_factor; /* HOT tail age relative to COLD tail */
        double warm_max_factor; /* WARM tail age relative to COLD tail */
        int crawls_persleep; /* Number of LRU crawls to run before sleeping */
        bool temp_lru; /* TTL < temporary_ttl uses TEMP_LRU */
        uint32_t temporary_ttl; /* temporary LRU threshold */
        int idle_timeout;       /* Number of seconds to let connections idle */
        unsigned int logger_watcher_buf_size; /* size of logger's per-watcher buffer */
        unsigned int logger_buf_size; /* size of per-thread logger buffer */
        unsigned int read_buf_mem_limit; /* total megabytes allowable for net buffers */
        bool drop_privileges;   /* Whether or not to drop unnecessary process privileges */
        bool watch_enabled; /* allows watch commands to be dropped */
        bool relaxed_privileges;   /* Relax process restrictions when running testapp */
        bool meta_response_old; /* use "OK" instead of "HD". for response code TEMPORARY! */

    #ifdef TLS
        bool ssl_enabled; /* indicates whether SSL is enabled */
        SSL_CTX *ssl_ctx; /* holds the SSL server context which has the server certificate */
        char *ssl_chain_cert; /* path to the server SSL chain certificate */
        char *ssl_key; /* path to the server key */
        int ssl_verify_mode; /* client certificate verify mode */
        int ssl_keyformat; /* key format , default is PEM */
        char *ssl_ciphers; /* list of SSL ciphers */
        char *ssl_ca_cert; /* certificate with CAs. */
        rel_time_t ssl_last_cert_refresh_time; /* time of the last server certificate refresh */
        unsigned int ssl_wbuf_size; /* size of the write buffer used by ssl_sendmsg method */
        bool ssl_session_cache; /* enable SSL server session caching */
        int ssl_min_version; /* minimum SSL protocol version to accept */
    #endif
        int num_napi_ids;   /* maximum number of NAPI IDs */
        char *memory_file;  /* warm restart memory file path */
    #ifdef PROXY
        bool proxy_enabled;
        bool proxy_uring; /* if the proxy should use io_uring */
        char *proxy_startfile; /* lua file to run when workers start */
        void *proxy_ctx; /* proxy's state context */
    #endif
    };
  }
}
