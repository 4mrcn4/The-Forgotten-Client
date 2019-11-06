/*
  Tibia CLient
  Copyright (C) 2019 Saiyans King

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef __FILE_TILE_h_
#define __FILE_TILE_h_

#include "position.h"

#define ITEM_MAX_ELEVATION 24

class Thing;
class Item;
class Creature;
class Effect;

class Tile
{
	public:
		Tile(const Position& position);
		~Tile();

		void render(Sint32 posX, Sint32 posY, bool visible_tile);
		void rerenderTile(Sint32 posX, Sint32 posY, bool visible_tile);
		void renderInformations(Sint32 posX, Sint32 posY, Sint32 drawX, Sint32 drawY, float scale, bool visible);

		Uint32 getThingStackPos(Thing* thing);
		Thing* getThingByStackPos(Uint32 index);
		Creature* getTopCreature();
		Thing* getTopLookThing();
		Thing* getTopUseThing();
		Thing* getTopMoveThing();
		Thing* getTopMultiUseThing();

		bool addThing(Thing* thing, bool insertThing = false, bool moveCreature = false);
		bool insertThing(Thing* thing, Uint32 stackpos);
		bool removeThing(Thing* thing, bool moveCreature = false);

		void addWalkCreature(Creature* creature);
		void removeWalkCreature(Creature* creature);

		void checkMagicEffects();
		void addEffect(Effect* effect);

		bool isLookingPossible();
		bool isWalkable();
		bool isPathable();
		bool mustHookEast();
		bool mustHookSouth();
		SDL_FORCE_INLINE bool hasTranslucentLight() {return m_hasTranslucentLight;}
		SDL_FORCE_INLINE bool isCreatureLying() {return m_lyingCorpses;}

		void recacheTranslucentLight();
		void recacheLyingCorpses();

		size_t getThingCount();
		Uint16 getGroundSpeed();
		Uint16 getMinimapSpeed();
		Uint16 getMinimapColor();
		SDL_FORCE_INLINE Sint32 getTileElevation() {return m_tileElevation;}
		SDL_FORCE_INLINE Position& getPosition() {return m_position;}

		bool isFullground();
		bool isLookPossible();
		bool limitsFloorsView(bool isFreeView);

	protected:
		Item* m_ground;
		std::vector<Item*> m_topItems;
		std::vector<Item*> m_downItems;
		std::vector<Creature*> m_creatures;
		std::vector<Creature*> m_walkCreatures;
		std::vector<Effect*> m_effects;

		Position m_position;
		Sint32 m_tileElevation;
		bool m_hasTranslucentLight;
		bool m_lyingCorpses;
};

#endif /* __FILE_TILE_h_ */
