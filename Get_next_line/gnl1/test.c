#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	*get_new_text(char *str, t_list *list)
{
	char	*result;
	size_t	i;

	if (str[0] && ft_strchr(str, '\n'))
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		result = ft_strdup(&str[i + 1]);
		if (!result)
			ft_del(list);
	}
	else
		result = NULL;
	free(str);
	return (result);
}

char	*get_one_line(char *str)
{
	char	*result;
	size_t	i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		result = malloc(sizeof(char) * i + 2);
		if (!result)
			return (NULL);
		result[++i] = '\0';
		while (i)
		{
			i--;
			result[i] = str[i];
		}
	}
	else
		return (ft_strdup(str));
	return (result);
}

char	*read_line(int fd, char *text)
{
	char	*temp;
	ssize_t	buf_size;

	if (!text)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buf_size = BUFFER_SIZE;
	while (text && !ft_strchr(text, '\n') && buf_size != 0)
	{
		buf_size = read(fd, temp, BUFFER_SIZE);
		if (buf_size < 0 || (buf_size == 0 && text && !text[0]))
		{
			free(text);
			text = NULL;
			break ;
		}
		temp[buf_size] = '\0';
		text = ft_strjoin(text, temp);
	}
	free(temp);
	return (text);
}

t_list	*get_text(int fd, t_list *list)
{
	t_list			*temp;

	temp = list;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
			return ((t_list *)ft_del(list));
		temp->fd = fd;
		temp->content = ft_strdup("");
		temp->next = NULL;
	}
	temp->content = read_line(fd, temp->content);
	if (!list || list == temp)
		return (temp);
	else
		list->next = temp;
	return (list);
}

void	*ft_del(t_list *list)
{
	t_list		*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (NULL);
}

t_list	*next(t_list *list, t_list *temp)
{
	t_list		*pre_temp;

	if (list == temp)
	{
		list = list->next;
		free(temp);
	}
	else
	{
		pre_temp = list;
		while (pre_temp->next != temp)
			pre_temp = pre_temp->next;
		pre_temp->next = temp->next;
		free(temp);
	}
	return (list);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*result;
	t_list			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = get_text(fd, list);
	if (!list)
		return (NULL);
	temp = list;
	while (temp->fd != fd)
		temp = temp->next;
	if (!(temp->content))
	{
		list = next(list, temp);
		return (NULL);		
	}
	result = get_one_line(temp->content);
	temp->content = get_new_text(temp->content, list);
	if (!(temp->content))
		list = next(list, temp);
	return (result);
}

int main()
{
	int	fd[4];
	fd[0] = open("line1.txt", O_RDONLY);
	fd[1] = open("line2.txt", O_RDONLY);
	fd[2] = open("line3.txt", O_RDONLY);
	fd[3] = open("line4.txt", O_RDONLY);
	char	*str1 = get_next_line(fd[0]);
	char	*str2 = get_next_line(fd[1]);
	char	*str3 = get_next_line(fd[2]);
	char	*str4 = get_next_line(fd[3]);
	while (str1 || str2 || str3 || str4)
	{
		if (str1)
		{
			printf("%s", str1);
			free(str1);
			str1 = get_next_line(fd[0]);
		}
		if (str2)
		{
			printf("%s", str2);
			free(str2);
			str2 = get_next_line(fd[1]);
		}
		if (str3)
		{
			printf("%s", str3);
			free(str3);
			str3 = get_next_line(fd[2]);
		}
		if (str4)
		{
			printf("%s", str4);
			free(str4);
			str4 = get_next_line(fd[3]);
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (0);
}