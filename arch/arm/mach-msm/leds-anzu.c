/* arch/arm/mach-msm/leds-anzu.c
 *
 * Copyright (C) [2010] Sony Ericsson Mobile Communications AB.
 * Copyright 2013 Vassilis Tsogkas (tsogkas@ceid.upatras.gr)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#ifdef CONFIG_LEDS_AS3676_SEMC
#include <linux/bug.h>
#include <linux/leds.h>
#include <linux/leds-as3676_semc.h>

static struct as3676_platform_led as3676_leds_mapping[] = {
	{
		.name = "lcd-backlight",
		.sinks = BIT(AS3676_SINK_01),
		.flags = AS3676_FLAG_PWM_CTRL | AS3676_FLAG_PWM_INIT
			| AS3676_FLAG_WAIT_RESUME,
		.max_current = 20000,
		.hw_max_current = 25000,
		.default_brightness = LED_FULL,
	},
	{
		.name = "button-backlight",
		.sinks = BIT(AS3676_SINK_RGB1) | BIT(AS3676_SINK_RGB2),
		.max_current = 450,
		.hw_max_current = 25000,
	},
	{
		.name = "red",
		.sinks = BIT(AS3676_SINK_41),
		.flags = AS3676_FLAG_RGB | AS3676_FLAG_BLINK,
		.max_current = 1000,
		.hw_max_current = 25000,
	},
	{
		.name = "green",
		.sinks = BIT(AS3676_SINK_42),
		.flags = AS3676_FLAG_RGB | AS3676_FLAG_BLINK,
		.max_current = 1000,
		.hw_max_current = 25000,
	},
	{
		.name = "blue",
		.sinks = BIT(AS3676_SINK_43),
		.flags = AS3676_FLAG_RGB | AS3676_FLAG_BLINK,
		.max_current = 1000,
		.hw_max_current = 25000,
	},
};

struct as3676_platform_data as3676_platform_data = {
	.leds = as3676_leds_mapping,
	.num_leds = ARRAY_SIZE(as3676_leds_mapping),
	.als_connected = 1,
	.als_wait = 100,
	.dls_connected = false,
	.ldo_mV = 3300,
};
#endif
