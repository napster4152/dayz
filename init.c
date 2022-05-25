void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    obj.SetOrientation( obj.GetOrientation() ); //Collision fix
    obj.Update();
    obj.SetAffectPathgraph( true, false );
    if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
}

void main()  
{
SpawnObject( "Land_Mil_ATC_Small", "3236.320068 12.921500 1743.829956", "175.999619 0.000000 -0.000000" );
SpawnObject( "bldr_Decal_Heli_Army", "3247.159912 2.740000 1716.800049", "0.000000 0.000000 -0.000000" ); //heli Trader
SpawnObject( "BOC_Banking_Atm", "3238.090088 2.600000 1742.069946", "-07.000000 0.000000 -0.000000" ); //heli Atm
SpawnObject( "BOC_Banking_Atm", "6902.250000 37.476601 6050.250000", "200.000000 -0.716078 -0.572997" ); //weapons Atm
SpawnObject( "Land_Mil_GuardShed", "3568.419922 13.060000 8908.990234", "-62.998096 0.000000 0.000000" ); //drugdealer trader
SpawnObject( "BOC_Banking_Atm", "3569.280029 12.250000 8911.019531", "30.000000 0.000000 0.000000" );  //drugdealer Atm
SpawnObject( "bldr_mil_camonet_tent2", "14522.400391 6.555860 5255.270020", "0.000000 0.000000 -0.000000" );
SpawnObject( "BOC_Banking_Atm", "14537.200195 4.900000 5256.790039", "156.000435 0.000000 -0.000000" ); //blackmarket Atm
SpawnObject( "vbldr_teacher_desk", "14521.700195 4.950000 5255.580078", "-95.000000 0.000000 0.000000" );
SpawnObject( "BOC_Banking_Atm", "6648.129883 15.090000 6435.520020", "178.000000 0.000000 -0.000000" ); // car atm
SpawnObject( "BOC_Banking_Atm", "6664.970215 16.200001 6415.609863", "178.000000 0.000000 -0.000000" ); //right
SpawnObject( "BOC_Banking_Atm", "6665.009766 16.200001 6416.770235", "178.000000 0.000000 -0.000000" ); //middle
SpawnObject( "BOC_Banking_Atm", "6664.970215 16.200001 6417.900835", "178.000000 0.000000 -0.000000" ); //left
SpawnObject( "Land_RoadCone", "6643.490234 15.088900 6435.879883", "0.000000 0.000000 -0.000000" );
SpawnObject( "Land_RoadCone", "6643.660156 15.088900 6431.839844", "0.000000 0.000000 -0.000000" );
SpawnObject( "Land_RoadCone", "6643.549805 15.088900 6428.379883", "0.000000 0.000000 -0.000000" );
SpawnObject( "Land_RoadCone", "6639.600098 15.088900 6435.870117", "0.000000 0.000000 -0.000000" );
SpawnObject( "Land_RoadCone", "6639.470215 15.088900 6431.709961", "0.000000 0.000000 -0.000000" );
SpawnObject( "Land_RoadCone", "6639.430176 15.088900 6428.120117", "0.000000 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6669.220215 15.834000 6409.729980", "92.001938 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6668.930176 15.834000 6401.930176", "92.001938 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6668.620117 15.834000 6394.120117", "92.001938 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6661.479980 15.834000 6389.629883", "-2.998346 0.000000 0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6645.520020 15.834000 6388.640137", "-4.000385 0.000000 0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6617.109863 15.834000 6394.009766", "73.996048 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6613.189941 15.834000 6411.290039", "87.998047 0.000000 -0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6613.729980 15.834000 6452.689941", "-87.030457 0.000000 0.000000" );
SpawnObject( "vbldr_wall_pipefencewall_8", "6614.180176 15.834000 6460.540039", "-87.030457 0.000000 0.000000" );
SpawnObject( "Land_Wall_Gate_IndCnc4", "6614.720215 15.984900 6469.169922", "-87.030457 0.000000 0.000000" );  
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	// Weather weather = g_Game.GetWeather();
	// weather.MissionWeather(false);    // false = use weather controller from Weather.c
	// weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	// weather.GetRain().Set( 0, 0, 1);
	// weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
	
    //CEApi TestHive = GetCEApi();
    //TestHive.ExportProxyProto();
    //TestHive.ExportProxyData( "8096 0 8096", 16384 );
    //TestHive.ExportClusterData() ;	  	
}
class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemTop;
		EntityAI itemEnt;
		ItemBase itemBs;

		float rand;

		itemTop = player.FindAttachmentBySlotName("Body");

		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");

			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(4);

			SetRandomHealth(itemEnt);

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt(0, 4);
			itemEnt = itemTop.GetInventory().CreateInInventory(chemlightArray[rndIndex]);
			
			SetRandomHealth(itemEnt);

			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("Apple");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("Pear");
			else
				itemEnt = player.GetInventory().CreateInInventory("Plum");

			SetRandomHealth(itemEnt);
			
			itemEnt = player.GetInventory().CreateInInventory("Rag");
            itemEnt = player.GetInventory().CreateInInventory("BOC_Banking_ATMCard");
		}
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}