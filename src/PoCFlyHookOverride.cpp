/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"

enum {
    HellFirePeninsula = 3483
};

// Add player scripts
class PoCFlyHookOverride : public PlayerScript
{
public:
    PoCFlyHookOverride() : PlayerScript("PoCFlyHookOverride") { }

    //Close the sky above Hellfire Peninsula
    bool OnCanPlayerFlyInZone(const Player* player, uint32 mapId, uint32 zoneId, SpellInfo const* bySpell) override
    {
        return zoneId != HellFirePeninsula;
    }
};

// Add all scripts in one
void AddPoCFlyHookOverride()
{
    new PoCFlyHookOverride();
}
