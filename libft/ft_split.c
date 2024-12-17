/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:32:59 by alyildiz          #+#    #+#             */
/*   Updated: 2024/12/17 22:21:18 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_c(char car, char c)
{
	if (car == c)
		return (1);
	return (0);
}

static int	count_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] && is_in_c(str[i], c))
			i++;
		if (str[i] && !is_in_c(str[i], c))
		{
			count++;
			while (str[i] && !is_in_c(str[i], c))
				i++;
		}
	}
	return (count);
}

static char	*ft_word(char *str, char c)
{
	int		i;
	char	*word;

	word = 0;
	i = 0;
	while (str[i] && !is_in_c(str[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_in_c(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **tab, int i)
{
	while (i)
	{
		free(tab[i]);
		tab[i] = 0;
		i--;
	}
	free(tab);
	tab = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && is_in_c(*s, c))
			s++;
		if (*s && !is_in_c(*s, c))
		{
			tab[i] = ft_word((char *)s, c);
			if (tab[i++] == 0)
				return (ft_free((char **)tab, i++));
			while (*s && !is_in_c(*s, c))
				s++;
		}
	}
	tab[i] = (0);
	return (tab);
}
/*
int main()
{
    const char *str = "Voici un exemple simple pour la fonction split";
    char charset = ' ';
    char **result = ft_split(str, charset);

    int i = 0;
    while (result[i] != NULL)
    {
        printf("Mot %d: %s\n", i + 1, result[i]);
        i++;
    }

    // Libérer la mémoire allouée pour le résultat
    i = 0;
    while (result[i] != NULL)
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
*/
