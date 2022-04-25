



struct vega_hostname {
  char* name;
  char* ip;
};

struct vega_client {

};

struct vega_server {
  int port;
  vega_hostname hostname;

  /* List of connected clients */
  vega_client* connected_clients;
  
};
