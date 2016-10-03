package faxe;

@:keep
@:include('linc_faxe.h')
@:build(linc.Linc.touch())
@:build(linc.Linc.xml('faxe'))

extern class Faxe
{
	@:native("linc::faxe::faxe_init")
	public static function fmod_init(numChannels:Int = 128):Void;
}