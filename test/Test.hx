import faxe.Faxe;

class Test
{
	static function main()
	{
		Faxe.fmod_init(36);
		Faxe.fmod_load_bank("test.bank");
	}
}