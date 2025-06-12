#ifdef WIN32
#   include <windows.h>
    /* Not yet. */
#else
#   include <stdio.h>
#   include <ncurses.h>
#   include <menu.h>
#   include <string.h>

void AppWindow() {
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("osloader v1.00\n");
    ch = getch();

    if(ch == KEY_F(1)){
        printw("Not implemented.\n");
    } else {
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();
    getch();
    endwin();
}

int main() {
    AppWindow();
    return 0;
}
#endif