/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:05:53 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/02 12:12:11 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

size_t			ft_numlen(long n);

/*
** COLORS DEINES
*/

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/*
** Get_next_line
*/

# define FD_MAX (1024)
# define BUFFER_SIZE (42)

int				get_next_line(int const fd, char **line);

/*
** Lists
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstaddfront(t_list **alst, t_list *new);
void			ft_lstaddback(t_list **alst, t_list *new);
t_list			*ft_lstgetlast(t_list *lst);
void			ft_lstfree(t_list *begin, void (*f)(void *));
void			ft_lstprint(t_list *list);
size_t			ft_lstsize(t_list *alst);

/*
** Functions manipulate memory
*/

void			*ft_realloc(void *ptr, size_t new_size);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memdup(const void *s, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Functions manipulate strings
*/

void			ft_free_str(char **str);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strsdup(const char *s1, size_t start);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcatf(const char *s1, char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);

/*
** Functions manipulate tabs
*/

void			ft_free_array(char **array);
int				ft_tabsize(char **tab);
char			**ft_tab_split_to_id(char **tab, int pos);
char			**ft_tab_split_from_id(char **tab, int pos);

/*
** Functions test/convert
*/

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_baseconv(unsigned long nbr, int base, int minlem);

/*
** Functions for tests
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

/*
** Functions to write
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
size_t			ft_putchar(char c);
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_putstr(char *s);
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putnbr(long n);
size_t			ft_putnbr_fd(long n, int fd);
size_t			ft_put_tab(char **tab);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);

/*
** Functions to error gestion
*/
char			*ft_strerror(int errnum);
void			ft_perror(char *s);

#endif
