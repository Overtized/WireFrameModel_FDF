/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:28:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/06/28 13:28:54 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *str, char c)
{
	int	inword;
	int	wordcount;
	int	i;

	inword = 0;
	i = 0;
	wordcount = 0;
	while (str[i])
	{
		if (str[i] != c && inword == 0)
		{
			inword = 1;
			wordcount++;
		}
		else if (str[i] == c)
			inword = 0;
		i++;
	}
	return (wordcount);
}

static void	freetab(char **tab, int lasttab)
{
	int	i;

	i = 0;
	while (i < lasttab)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

static int	tabfill(char **tab, char const *str, char delim)
{
	int	i;
	int	wordlength;
	int	tabnumb;

	i = 0;
	tabnumb = 0;
	wordlength = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		while (str[i] != delim && str[i])
		{
			wordlength++;
			i++;
		}
		tab[tabnumb] = malloc (sizeof (char) * (wordlength + 1));
		if (!tab[tabnumb])
			return (freetab(tab, tabnumb), 0);
		ft_strlcpy (tab[tabnumb], &str[i - wordlength], wordlength + 1);
		tabnumb++;
		wordlength = 0;
	}
	tab[tabnumb] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	size_t	wordnumber;
	char	**tab;

	if (!str)
		return (NULL);
	if (!*str)
	{
		tab = malloc(sizeof (char *) * 1);
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	wordnumber = ft_countword(str, c);
	tab = malloc((wordnumber + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!tabfill(tab, str, c))
		return (NULL);
	return (tab);
}
