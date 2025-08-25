#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	if (ac != 2)
		return(ft_printf(1, "wrong args number, args should be 2\n"));
	if (!test_input(av[1]))
		return (ft_printf(1, "map is not valid \n"));
	ft_printf(1, "hello world\n");
	// t_position **tab; // len tab 
	return(0);
}
// tester les qrgs, tester l'extension du fichier, tester la validite de la map
// ranger dans un tableau de structure contenant tout les infos (position couleur ...).

// //• open, close, read, write,
// malloc, free, perror,
// strerror, exit.
// • All functions of the math
// library (-lm compiler option,
// man 3 math on some operating
// systems).
// • All functions of the MiniLibX
// library.
// • ft_printf or any equivalent
// YOU coded