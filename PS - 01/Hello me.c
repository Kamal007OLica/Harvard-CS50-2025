#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string name = get_string("what is your name?");
    printf("hello, %s\n", name);
}
