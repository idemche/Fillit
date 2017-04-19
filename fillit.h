/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:55:24 by araichyn          #+#    #+#             */
/*   Updated: 2016/12/06 14:42:08 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_TMINO 26
# define NUM_SHAPES 19
# define BLK_SZ 20
# define BLK_WD 4
# define BLK_HT 4
# define C_ETY '.'
# define C_FLL '#'

extern char			g_print_char;
extern const char	*const g_arr[];

typedef struct		s_tmino
{
	int		width;
	int		height;
	char	*map;
}					t_tmino;

typedef enum		e_shape
{
	J1, J2, J3, J4, L1, L2, L3, L4, O, I1, I2, S1, S2, Z1, Z2, T1, T2, T3, T4
}					t_shape;

int					build_arr(int fd, t_tmino ***build_arr);
int					check_block(char *b);
int					find_tmino(char *b);
t_tmino				*build_tmino(char *buffer);
char				*strip_nl(char *s);
char				*norm_shape(char *buffer);
char				*pack_shapes(t_tmino **tmino_arr, int *sz_p);
void				display_sq(char *res, int sq_size);
int					find_solution(t_tmino **tmino_arr, char **field, int level,
		int sq_size);
int					place_tmino(t_tmino *tmino, char **field, int sq_size,
		int i);
void				remove_tmino(t_tmino *tmino, char **field, int sq_size,
		int i);
int					check_place(t_tmino *tmino, char **field, int sq_size,
		int i);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_puterr(const char *s);
char				*ft_strshift(char *s, int n);
int					ft_abs(int n);
int					ft_fssq(int num);
#endif
