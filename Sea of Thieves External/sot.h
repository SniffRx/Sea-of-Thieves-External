#pragma once
#include <cmath>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "hacklib.h"
#include "offsets.h"
#include "sdk.h"

namespace cheat
{
	class SOT
	{
	public:
		enum class ActorType
		{
			//Players
			PLAYER_PIRATE = 0,

			//NPCs
			OOS_OPRAH, OOS_OLIVE, OOS_MADAME_OLWEN, OOS_OLIVIA, OOS_OKSANA, OOS_OLGA, OOS_OYA,
			GHD_HORACE, GHD_HUMPHREY, GHD_HERBERT, GHD_HARRY, GHD_HENRY, GHD_HUGH, GHD_HYDE,
			MCH_MANDY, MCH_MOLLIE, MCH_MILDRED, MCH_MEG, MCH_MAVIS, MCH_MAUREEN, MCH_MATILDA,
			CGR_CHARLOTTE,
			GHOST_SHIP_CAPTAIN,

			//Ships
			S_SHIP_TEMPLATE, M_SHIP_TEMPLATE, L_SHIP_TEMPLATE,
			
			//Creatures
			MERMAID, PIG, CHICKEN, SNAKE, SHARK, SKELETON, PHANTOM, OCEAN_CRAWLER_HERMIT,
			OCEAN_CRAWLER_CRAB, OCEAN_CRAWLER_EELECTRIC, GIANT_SKELETON, TINY_SHARK, SIREN,

			//Treasure chests
			COLLECTORS_CHEST, MY_TREASURE_CHEST, RA_TREASURE_CHEST, TREASURE_CHEST_FORT, ANCIENT_COLLECTORS_CHEST, ASHEN_CHEST_COLLECTORS_CHEST,


			//Treasure items
			SIREN_TRIDENT, B_GUNPOWDER_BARREL, LOW_VALUE_GIFT, HIGH_VALUE_GIFT, RITUAL_SKULL, SKELETON_ORDERS,
			MY_BOUNTY_REWARD_SKULL, GOLD_POUCH, ASHEN_KEY,
			MERMAID_GEM_RUBY, MERMAID_GEM_EMERALD, MERMAID_GEM_SAPPHIRE, SUNKEN_CURSE_RUBY, SUNKEN_CURSE_EMERALD, SUNKEN_CURSE_SAPPHIRE, 
			AMMO_POUCH, RA_BOUNTY_REWARD_SKULL, MESSAGE_IN_A_BOTTLE, CORAL_MESSAGE_IN_A_BOTTLE, BANANA_CRATE, TREASURE_ARTIFACT_VASE_01,
			TREASURE_ARTIFACT_VASE_02, TREASURE_ARTIFACT_DVR_COMMON, TREASURE_ARTIFACT_BOX_01,

			UNKNOWN
		};

		bool init();
		hacklib::Process *process();

		sdk::UWorld world();
		void *names();
		std::string get_actor_name(int id);
		ActorType get_actor_type(int id);

		//https://github.com/DougTheDruid/SoT-ESP-Framework/blob/main/helpers.py#L71-L161
		bool world_to_screen(const sdk::FMinimalViewInfo &camera_pov, sdk::Vector3 &position, sdk::Vector2 *out);

	private:
		hacklib::Process _process{ "SoTGame.exe" };
		char *_process_base = nullptr;
		std::unordered_map<int, SOT::ActorType> _actor_id_map{ };
	};

	SOT *game();
}