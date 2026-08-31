#include <stdio.h>

enum state {
    NORMAL,
    SAW_SLASH,
    BLOCK_COMMENT,
    LINE_COMMENT,
    SAW_STAR
};

// We didn't deal with the case where '\\' appears
// in a string literal or character constant.
int main(void) {
    enum state currentState = NORMAL;
    int c;
    while ((c = getchar()) != EOF) {
        if (currentState == NORMAL) {
            if (c == '/') {
                currentState = SAW_SLASH;
            } else {
                putchar(c);
            }
        } else if (currentState == SAW_SLASH) {
            if (c == '*') {
                currentState = BLOCK_COMMENT;
            } else if (c == '/') {
                currentState = LINE_COMMENT;
            } else {
                putchar('/');
                putchar(c);
                currentState = NORMAL;
            }
        } else if (currentState == BLOCK_COMMENT) {
            if (c == '*') {
                currentState = SAW_STAR;
            }
        } else if (currentState == LINE_COMMENT) {
            if (c == '\n') {
                currentState = NORMAL;
                putchar(c);
            }
        } else if (currentState == SAW_STAR) {
            if (c == '/') {
                currentState = NORMAL;
                putchar(' '); // Replace the comment with a space
            } else if (c != '*') {
                currentState = BLOCK_COMMENT;
            }
        }
    }
    if (currentState == SAW_SLASH) {
        putchar('/');
    }
    return 0;
}