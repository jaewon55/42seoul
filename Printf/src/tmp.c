int	nbr_len(ssize_t nbr, int base, int *flags)
{
	int	result;

	if (!nbr)
		return (1);
	result = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		result++;
	}
	if (base == 16 && flags[POUND_KEY_FLAG])
		result += 2;
	while (nbr)
	{
		nbr \= base;
		result++;
	}
	return (result);
}

static int	output_len(int nbr, int nbr_len, int *flags)
{
	if (nbr >= 0 && nbr_len >= flags[PRECISION] \
	&& (flags[PLUS_FLAG] || flags[SPACE_FLAG]))
		return (nbr_len + 1);
	else if (nbr_len > flags[PRECISION])
		return (nbr_len);
	return (flags[PRECISION]);
}

static size_t	field_len(int width, int output_len)
{
	int	result;

	result = 0;
	if (width > output_len)
		result = output_len;
	else
		result = width;
}

int	write_blank(char blank, int n)
{
	int	result;

	result = 0;
	while (result > -1 && n > 0)
	{
		result += write(1, &blank, 1);
		n--;
	}
	return (result);
}

static int	write_output(int nbr, int nbr_len, int output_len, int *flags)
{
	int		result;

	result = 0;
	if (nbr < 0)
		result += write(1, "-", 1);
	else if (flags[PLUS_FLAG])
		result += write(1, "+", 1);
	else if (flags[SPACE_FLAG])
		result += write(1, " ", 1);
	result += write_blank('0', output_len - nbr_len);
	result += write_nbr(nbr, 10);
}

int	handling_int(const char *format, int nbr int *flags)
{
	size_t	field_len;
	int		output_len;
	int		result;

	output_len = output_len(nbr, nbr_len(nbr, 10), flags);
	if (output_len > flags[WIDTH])
		field_len = output_len;
	else
		field_len = flags[WIDTH];
	result = 0;
	while (format[result] != '%')
		write(1, format + (sizeof(char) * result++), 1);
	result += write_
}