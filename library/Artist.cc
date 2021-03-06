/*******************************************************************************

Germ - The infectious music player.
Copyright (C) 2006  Ryan Johns and Stephen McCarthy

This file is part of Germ.
Germ is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

Germ is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with Germ; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*******************************************************************************/

#include "Artist.h"
#include "Album.h"
#include <string>
#include <vector>

Artist::Artist(std::string artistName)
: m_artistName(artistName) {}

Artist::~Artist() {}

std::vector<Album> * Artist::get_album_children() {
	return &m_albumChildren;
}

std::string * Artist::get_artist_name() {
	return &m_artistName;
}
