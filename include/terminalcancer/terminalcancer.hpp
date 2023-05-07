#ifndef TERMINALCANCER_HPP
#define TERMINALCANCER_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <tuple>
#include <utility>
#include <vector>
using namespace std;

/// @brief returns the dimensions of the current terminal
/// @return returns a tuple containing the terminal width and height
tuple<int, int> getTerminalDimensions();

#endif
