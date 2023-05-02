#ifndef TERMINALCANCER_HPP
#define TERMINALCANCER_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <tuple>
#include <utility>
#include <vector>
using namespace std;
tuple<int, int> getTerminalDimensions();

#endif
