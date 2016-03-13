/*
** get_next_line.h for get_next_line.h in /home/hoarau_v/Get_next_line
** 
** Made by victor hoarau
** Login   <hoarau_v@epitech.net>
** 
** Started on  Mon Jan 11 17:57:48 2016 victor hoarau
** Last update Sat Mar 12 17:02:18 2016 hoarau
*/

#ifndef READ_SIZE
# define READ_SIZE 10
#endif

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define GNLM_SIZE (READ_SIZE + 1)
# define CSIZE (sizeof(char))
# define INITMP(tmp) (tmp == NULL && ((tmp = malloc(sizeof(char) * GNLM_SIZE)) == NULL))

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(const int fd);
#endif /* !GET_NEXT_LINE_H_ */
