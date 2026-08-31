#include <stdio.h>

enum state {
    NORMAL,
    AFTER_SLASH,
    BLOCK_COMMENT,
    BLOCK_COMMENT_STAR,
    LINE_COMMENT,
    STRING_LITERAL,
    STRING_ESCAPE,
    CHARACTER_LITERAL,
    CHARACTER_ESCAPE
};

int main(void)
{
    int c;
    enum state current_state = NORMAL;

    while ((c = getchar()) != EOF) {
        switch (current_state) {
        case NORMAL:
            if (c == '/')
                current_state = AFTER_SLASH;
            else {
                putchar(c);
                if (c == '"')
                    current_state = STRING_LITERAL;
                else if (c == '\'')
                    current_state = CHARACTER_LITERAL;
            }
            break;

        case AFTER_SLASH:
            if (c == '*') {
                putchar(' ');
                current_state = BLOCK_COMMENT;
            } else if (c == '/') {
                putchar(' ');
                current_state = LINE_COMMENT;
            } else {
                putchar('/');
                putchar(c);
                if (c == '"')
                    current_state = STRING_LITERAL;
                else if (c == '\'')
                    current_state = CHARACTER_LITERAL;
                else
                    current_state = NORMAL;
            }
            break;

        case BLOCK_COMMENT:
            if (c == '*')
                current_state = BLOCK_COMMENT_STAR;
            else if (c == '\n')
                putchar('\n');
            break;

        case BLOCK_COMMENT_STAR:
            if (c == '/')
                current_state = NORMAL;
            else {
                if (c == '\n')
                    putchar('\n');
                current_state = (c == '*') ? BLOCK_COMMENT_STAR : BLOCK_COMMENT;
            }
            break;

        case LINE_COMMENT:
            if (c == '\n') {
                putchar('\n');
                current_state = NORMAL;
            }
            break;

        case STRING_LITERAL:
            putchar(c);
            if (c == '\\')
                current_state = STRING_ESCAPE;
            else if (c == '"')
                current_state = NORMAL;
            break;

        case STRING_ESCAPE:
            putchar(c);
            current_state = STRING_LITERAL;
            break;

        case CHARACTER_LITERAL:
            putchar(c);
            if (c == '\\')
                current_state = CHARACTER_ESCAPE;
            else if (c == '\'')
                current_state = NORMAL;
            break;

        case CHARACTER_ESCAPE:
            putchar(c);
            current_state = CHARACTER_LITERAL;
            break;
        }
    }

    if (current_state == AFTER_SLASH)
        putchar('/');

    return 0;
}
