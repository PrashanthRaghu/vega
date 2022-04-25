

int int main(int argc, char const *argv[]) {
  /* code */

  /* Signal Handlers */
  signal(SIGINT, sig_handler);
  signal(SIGTERM, sig_handler);
  signal(SIGHUP, sighup_handler);
  signal(SIGUSR1, sig_usrhandler);


  return 0;
}
