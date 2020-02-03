/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main Function
*/

#include "scene.h"
#include "my.h"

void legend(void)
{
    my_printf("\n*********************************\n");
    my_printf("*             LEGEND            *\n");
    my_printf("*********************************\n\n");
    my_printf("  ****** Avertissement:  ******   \n\n");
    my_printf(" The limit of the map is (20, 120)\n");
    my_printf(" Don't exceed this limit\n\n");
    my_printf("  ******      Tiles:     ******   \n\n");
    my_printf("       o '1': Ground\n");
    my_printf("       o '2': Spikes\n");
    my_printf("       o 'o': Coin\n");
    my_printf("       o '7': End Map\n");
    my_printf("\n");
}

void help(void)
{
    my_printf("\nA runner game created with CSFML.\n");
    my_printf("*********************************\n");
    my_printf("\n*********************************\n");
    my_printf("*             USAGE             *\n");
    my_printf("*********************************\n\n");
    my_printf("    ./my_runner <path to the map>\n\n");
    my_printf("Exemple: ");
    my_printf(" ./my_runner bonus/maps/level1.txt\n");
    my_printf("\n*********************************\n");
    my_printf("*            OPTIONS            *\n");
    my_printf("*********************************\n\n");
    my_printf("  o -h print the usage\n");
    my_printf("  o -l to read the .legend\n");
    my_printf("\n*********************************\n");
    my_printf("*       USER INTERACTIONS       *\n");
    my_printf("*********************************\n\n");
    my_printf("  o ARROW_UP_KEY \t jump\n\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_printf("Error: Use -h to see the arguments\n");
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return (0);
    }
    if (my_strcmp(av[1], "-l") == 0) {
        legend();
        return (0);
    }
    core_t core = {0};
    core.filename = av[1];
    core.exit = -1;
    start(&core);
    if (core.exit > -1)
        return (core.exit);
    return (0);
}