#pragma once
#ifndef DEBUG_H
#define DEBUG_H

class DEBUG_Stuff
{
public:
	DEBUG_Stuff();
	~DEBUG_Stuff();
	static void animations(int x_pos, int y_pos, int x_pos_change, int y_pos_change, bool f_enabled);
	static void console_enabled(bool f_enabled);
	static void init_info(bool b_success, bool f_enabled);
	static void renderer_info(bool b_success, bool f_enabled);
	static void window_info(bool b_success, bool f_enabled);
	static void everything_is_fine(bool b_success, bool f_enabled);
	
};

#endif
