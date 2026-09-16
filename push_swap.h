/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 12:56:39 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 18:17:05 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_stack;

typedef struct s_counters
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counters;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_UNDEFINED,
}	t_strategy;

typedef struct s_context
{
	t_stack		a;
	t_stack		b;
	t_counters	ops;
	t_strategy	strategy;
	double		disorder;
	int			bench_mode;	
}	t_context;

/* parsing */
int		parse_args(int argc, char *argv[], t_context *ctx);

/* stack*/
void	stack_init(t_stack *s);
t_node	*stack_new_node(int content);
void	stack_add_bottom(t_stack *s, t_node *node);
void	stack_clear(t_stack *s);

/* operations */

/* algorithms*/

/* bench */

/* utils */
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_split(char **arr);
int		ft_isvalid(char *n);
int		ft_atoi(const char *n);
size_t	ft_strlen(const char *s);

#endif