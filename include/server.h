

#include <time.h>

#include "statistics.h"
#include "eventloop.h"


enum vega_keyformat {
  PEM, PKCS_7, PKCS_12, DER
};

struct vega_server_ssl_context {
  SSL_CTX *ssl_ctx; /* holds the SSL server context which has the server certificate */
  char *cipher_list; /* list of SSL ciphers */
  char *ca_cert; /* certificate with CAs. */
  char* chain_cert_path; /* path to the server SSL chain certificate */
  char* key_path; /* path to the server key */
  int  verify_mode; /* client certificate verify mode */
  vega_keyformat keyformat; /* key format , default is PEM */
};

struct vega_server {
  struct vega_stats statistics;
  time_t process_started;     /* when the process was started */
  struct vega_eventloop_manager event_loop;
  struct vega_server_ssl_context ssl_context;
};
