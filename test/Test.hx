import faxe.Faxe;

class Test
{
	static function main()
	{
		Faxe.fmod_init(36);

		// Load a sound bank
		Faxe.fmod_load_bank("./MasterBank.bank");

		// Make sure to load the STRINGS file to enable loading 
		// stuff by FMOD Path
		Faxe.fmod_load_bank("./MasterBank.strings.bank");

		// Load a test event
		Faxe.fmod_load_event("event:/testEvent");
		Faxe.fmod_play_event("event:/testEvent");

		// Bad little forever loop to pump FMOD commands
		while (true)
		{
			Faxe.fmod_update();
		}
	}
}
