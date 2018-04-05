#include "libgraph.h"

int			ft_key_hook_exit(int keycode)
{
	if (keycode == ESC_KEY)
		exit(0);
	return (keycode);
}
