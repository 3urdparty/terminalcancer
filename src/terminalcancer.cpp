#include "terminalcancer.hpp"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <tuple>
#include <utility>
using namespace std;

tuple<int, int> getTerminalDimensions() {
  // declare structure of type winsize to store the the terminal dimensions
  struct winsize w;
  // we get the terminal properties and store the object in w
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  // we return a a tuple containing the number of columns (width) and the number
  // of rows (height)
  return {w.ws_col, w.ws_row};
};