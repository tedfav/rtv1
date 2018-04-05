#include "rtv1.h"

int		ft_keyhook(int keycode, void *param)
{
	param = NULL;
	if (keycode == ESC_KEY)
		ft_key_hook_exit(keycode);
	return (keycode);
}
