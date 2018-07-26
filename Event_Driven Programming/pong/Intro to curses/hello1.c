#include <stdio.h>
#include <curses.h>

main() {
  initscr();
  clear();
  move(10,20);
  addstr("Hello, world");

  refresh();
  getch();

  endwin();
}
