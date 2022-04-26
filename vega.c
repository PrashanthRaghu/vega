

#include <signal.h>
#include "signal.c"


int main(int argc, char const *argv[]) {
  /* code */

  /* Signal Handlers */
  signal(SIGINT, sig_int_handler);
  signal(SIGTERM, sig_term_handler);
  signal(SIGHUP, sighup_hup_handler);
  signal(SIGUSR1, sig_usrhandler);
  signal(SIG)


  return 0;
}
