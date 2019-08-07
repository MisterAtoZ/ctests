#include <stdio.h>

enum colors {
        blue,
        green,
        red
};

enum colors get_color() {
    return blue;
}

/*example without arguments*/
int main(void) {
        enum colors my_color;
        puts("Wich color do you want?");
        my_color = get_color();
        
        switch(my_color) {
            case blue:
                puts("Blue is a nice color for a police LED");
                break;
            case green:
                puts("Green is the grass at the other side!");
                break;
            case red:
                puts("Red is apparently a good color for hair");
                break;
        }
    return 0;
}
