/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:40:08 by cejin             #+#    #+#             */
/*   Updated: 2024/02/29 18:40:36 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(t_pipex *pipex, int argc, char **argv)
{
	(void)pipex;
	(void)argc;
	(void)argv;
	//because we need to replicate: cmd << LIMITER | cmd >> file
	//'>>' this is a redirection with an append
	//so, cmd on the heredoc file |pipe| cmd2 -->result append it in file
	//					|
	//					|
	//					V
	/*here_doc> *things to write\n*
	  here_doc> *things to write\n*
	  here_doc> DELIMITER\n
	*/

	//create a heredoc as the infile
	//read the heredoc file
	//check the delimiter
	//do the cmd and write the result in the pipe
	//read it and do the cmd2
	//write it in the outfile
	return ;
}
