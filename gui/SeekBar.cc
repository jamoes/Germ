#include "SeekBar.h"
#include <sstream>
#include <iostream>

SeekBar::SeekBar(Player * player)
: m_player(player) {
	m_length = 0;

	set_range(0.0, 1.0);
	set_increments(0.0001, 0.0);
	set_digits(4);
	set_update_policy(Gtk::UPDATE_DISCONTINUOUS);
	set_value_pos(Gtk::POS_RIGHT);

	m_seekBarConnection = m_player->signal_update_seek_bar.connect(
		sigc::mem_fun(*this, &SeekBar::on_update_seek_bar)
	);
}

SeekBar::~SeekBar() {}

void SeekBar::on_move_slider(Gtk::ScrollType) {
	std::cout << "foo" << std::endl;
/*	m_seekBarConnection.disconnect();
	m_seekBarConnection = m_player->m_signal_update_seek_bar.connect(
		sigc::mem_fun(*this, &SeekBar::on_update_seek_bar)
	);*/
}

Glib::ustring SeekBar::on_format_value(double val) {
	Glib::ustring str_value;
	str_value = format_time(gint64(m_length * val));
	str_value += "/";
	str_value += format_time(m_length);
	return str_value;
}

void SeekBar::on_update_seek_bar(gint64 pos, gint64 len) {
	m_length = len;
	double dpos = pos;
	double dlen = len;
	if (pos == 0 && len == 0)
		set_value(0);
	else
		set_value(dpos/dlen);
}

Glib::ustring SeekBar::format_time(gint64 len) {
	if (len == 0)
		return "0:00";
	std::ostringstream oss;
	int secs = len / 1000000000;
	int minutes = secs / 60;
	int seconds = secs - minutes * 60;
	oss << minutes << ":";
	if (seconds < 10) {
		oss << 0 << seconds;
	}
	else {
		oss << seconds;
	}
	return oss.str();
}