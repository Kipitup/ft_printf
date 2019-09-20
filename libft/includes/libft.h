/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:58:24 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 00:30:13 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "vector.h"
/*
** # for linux set-up #
*/
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*
** ############################################################################
** ############################## STRUCTURES ##################################
** ############################################################################
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ############################################################################
** ############################## LINKED LIST #################################
** ############################################################################
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstfindone(t_list *lst, size_t rank);

/*
** ############################################################################
** ########################### MEM MANIPULATION ###############################
** ############################################################################
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *buff, int c, size_t len);
char				*ft_memjoin_str(char const *s_first, char const *s_last);

/*
** ############################################################################
** ########################## STRING MANIPULATION #############################
** ############################################################################
*/

size_t				ft_strlen(const char *c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *pile, const char *pin);
char				*ft_strnstr(const char *pil, const char *need, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strcapitalize(char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_bzero(void *s, size_t n);
void				ft_swap(void **one, void **two);
int					get_next_line(const int fd, char **line);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_strisupcase(char *str);
int					ft_strislowcase(char *str);
int					ft_strisblank(char *str);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strchr_str(const char *str, char *find);
char				*ft_strndup(const char *src, size_t size);

/*
** ############################################################################
** ########################## NUMBER MANIPULATION #############################
** ############################################################################
*/

int64_t				ft_absolute(int64_t nb);
size_t				ft_nb_unitlen(int nb);
int					ft_fibonacci(int index);
int					ft_atoi(const char *str);
char				*ft_itoa(int64_t n);
char				*ft_u_itoa(uint64_t n);
char				*ft_itoa_base(int64_t n, uint8_t base);
char				*ft_u_itoa_base(uint64_t n, uint8_t base);
char				*ft_itoa_base_maj(uint64_t n, uint8_t base, uint64_t flag);
char				*ft_ox_itoa_base(uint64_t n, uint8_t base, uint64_t flag);
double				ft_pow(double x, double y);
unsigned long		ft_pow_positive(unsigned long x, unsigned long y);
size_t				ft_uint64_t_len(uint64_t num, uint8_t base);
size_t				ft_int64_t_len(int64_t num, uint8_t base);
t_vector			*ft_ftoa(double value, uint64_t precision, uint32_t option);
t_vector			*ft_fldtoa(long double value, uint64_t precision, uint32_t option);
size_t				ft_len_printf(uint64_t value, uint64_t flag, size_t len);

/*
** ############################################################################
** ########################### WRITE OPERATION ################################
** ############################################################################
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *s, int fd);

#endif
