#include <stdio.h>
#include <curses.h>

main() {
  int i;
  initscr();
  clear();
  for (i = 0; i < 20; i++) {
    move(i,i+1);
    if (i%2==1)
      standout();
    addstr("Hello, world");
    if (i%2==1)
      standend();
    sleep(1);
    refresh();
  }

  endwin();
}
