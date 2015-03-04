/*
 * Copyright (C) 2015 Emeric Poupon
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

#ifndef UI_MOBILE_TRACK_SEARCH_HPP
#define UI_MOBILE_TRACK_SEARCH_HPP

#include <boost/algorithm/string/split.hpp>

#include <Wt/WContainerWidget>
#include <Wt/WSignal>

#include "resource/CoverResource.hpp"

#include "database/DatabaseHandler.hpp"

namespace UserInterface {
namespace Mobile {

class TrackSearch : public Wt::WContainerWidget
{
	public:

		TrackSearch(Database::Handler& db, Wt::WContainerWidget *parent = 0);

		void search(Database::SearchFilter filter, size_t nb);

		// Slots
		Wt::Signal<Database::Track::id_type>&	trackPlay() { return _sigTrackPlay;}
		Wt::Signal<void>&		moreTracksSelected() { return _sigMoreTracksSelected;}

	private:

		Wt::Signal<Database::Track::id_type> _sigTrackPlay;
		Wt::Signal<void>	_sigMoreTracksSelected;

		void clear(void);
		void addResults(Database::SearchFilter filter, size_t nb);

		Database::Handler&	_db;

		CoverResource*		_coverResource;

		std::size_t		_resCount;
};

} // namespace Mobile
} // namespace UserInterface

#endif
