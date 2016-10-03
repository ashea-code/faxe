package faxe;

@:keep
@:include('linc_faxe.h')
@:build(linc.Linc.touch())
@:build(linc.Linc.xml('faxe'))

extern class Faxe
{

}