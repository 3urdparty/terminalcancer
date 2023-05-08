#ifndef TERMINALCANCER_HPP
#define TERMINALCANCER_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include <tuple>
#include <utility>
#include <vector>
using namespace std;

/// @brief returns the dimensions of the current terminal
/// @return returns a tuple containing the terminal width and height
tuple<int, int> getTerminalDimensions();

/// @brief the getch function from conio.h on windows ported to mac and linux
/// environments. It gets the character from the stdin without needing to press
/// enter and prints it to screen
/// @return the character inputted
char getch();

/// @brief the getch function from conio.h on windows ported to mac and linux
/// environments. It gets the character from the stdin without needing to press
/// enter but does not print it to screen
/// @return the character inputted
char getche();

/// @brief Flushes terminal of its history
void flushTerminal();
#endif
