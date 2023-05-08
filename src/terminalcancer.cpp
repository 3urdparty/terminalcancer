#include "terminalcancer.hpp"

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
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

// Code copied from https://stackoverflow.com/a/16361724/20904220
char getch(void) {
  // declares a variable to store the character inputted
  char buf = 0;
  // creates a termios object
  struct termios old = {0};
  fflush(stdout);
  if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0) perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
  printf("%c\n", buf);
  return buf;
}

// Same code as getch but does not output the character
char getche(void) {
  char buf = 0;
  struct termios old = {0};
  fflush(stdout);
  if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0) perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
  return buf;
}

void flushTerminal(){
  char clear_terminal[] = R"(printf "\33c\e[3J")";
  system(clear_terminal);
}