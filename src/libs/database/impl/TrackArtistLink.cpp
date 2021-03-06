/*
 * Copyright (C) 2013-2016 Emeric Poupon
 *
 * This file is part of LMS.
 *
 * LMS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LMS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "database/TrackArtistLink.hpp"

#include "database/Artist.hpp"
#include "database/Session.hpp"
#include "database/Track.hpp"

namespace Database {

TrackArtistLink::TrackArtistLink(Wt::Dbo::ptr<Track> track, Wt::Dbo::ptr<Artist> artist, Type type)
: _type {type},
_track {track},
_artist {artist}
{
}

TrackArtistLink::pointer
TrackArtistLink::create(Session& session, Wt::Dbo::ptr<Track> track, Wt::Dbo::ptr<Artist> artist,Type type)
{
	session.checkUniqueLocked();

	TrackArtistLink::pointer res {session.getDboSession().add(std::make_unique<TrackArtistLink>(track, artist, type))};
	session.getDboSession().flush();

	return res;
}

}

