/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:20:01 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/27 17:53:34 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_double_char(char **commands)
{
	int	i;

	i = 0;
	if (!commands && !*commands)
		return ;
	while (commands[i])
	{
		free (commands[i]);
		i++;
	}
	if (commands)
		free (commands);
}

// static void	ft_free_args(t_map **commands)
// {
// 	t_map	*cursor;

// 	if (!commands && !*commands)
// 		return ;
// 	while (commands && *commands)
// 	{
// 		cursor = (*commands)->next;
// 		ft_free_double_char((*commands)->commands);
// 		if ((*commands)->path)
// 			free((*commands)->path);
// 		free(*commands);
// 		*commands = cursor;
// 	}
// }

// static void	ft_free_files(t_files **files)
// {
// 	if (!files || !*files)
// 		return ;
// 	if ((*files)->file1)
// 	{
// 		free((*files)->file1);
// 		(*files)->file1 = NULL;
// 	}
// 	if ((*files)->file2)
// 	{
// 		free((*files)->file2);
// 		(*files)->file2 = NULL;
// 	}
// 	ft_safe_close(&(*files)->fds[0]);
// 	ft_safe_close(&(*files)->fds[1]);
// 	ft_safe_close(&(*files)->pipes[0]);
// 	ft_safe_close(&(*files)->pipes[1]);
// 	ft_safe_close(&(*files)->last_read_fd);
// 	free(*files);
// 	*files = NULL;
// }

void	ft_free_structs(t_map *commands)
{
	if (commands)
	{
		free(commands);
	}
	// if (commands)
	// 	ft_free_args(commands);
	// if (files)
	// 	ft_free_files(files);
}

void	ft_safe_close(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
