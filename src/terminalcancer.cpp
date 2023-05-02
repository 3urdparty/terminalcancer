#include "terminalcancer.hpp"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <tuple>
#include <utility>
using namespace std;
tuple<int, int> getTerminalDimensions() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return {w.ws_col, w.ws_row};
};