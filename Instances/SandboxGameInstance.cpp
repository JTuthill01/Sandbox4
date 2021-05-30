#include "SandboxGameInstance.h"

USandboxGameInstance::USandboxGameInstance() = default;

void USandboxGameInstance::Init()
{
	
}

FAmmoData USandboxGameInstance::AK47Data()
{
	AK47AmmoData.Damage = 50.F;
	AK47AmmoData.CriticalHit = 10.F;
	AK47AmmoData.DamageRadius = 0.F;

	return AK47AmmoData;
}

FAmmoData USandboxGameInstance::AmericanShotgunData()
{
	AmericanShotgunAmmoData.Damage = 25.F;
	AmericanShotgunAmmoData.CriticalHit = 5.F;
	AmericanShotgunAmmoData.DamageRadius = 0.F;

	return AmericanShotgunAmmoData;
}

FAmmoData USandboxGameInstance::BelgianARData()
{
	BelgianARAmmoData.Damage = 65.F;
	BelgianARAmmoData.CriticalHit = 15.F;
	BelgianARAmmoData.DamageRadius = 0.F;

	return BelgianARAmmoData;
}

FAmmoData USandboxGameInstance::BulldogData()
{
	BulldogAmmoData.Damage = 35.F;
	BulldogAmmoData.CriticalHit = 5.F;
	BulldogAmmoData.DamageRadius = 0.F;

	return BulldogAmmoData;
}

FAmmoData USandboxGameInstance::HandCannonData()
{
	HandCannonAmmoData.Damage = 70.F;
	HandCannonAmmoData.CriticalHit = 5.F;
	HandCannonAmmoData.DamageRadius = 0.F;

	return HandCannonAmmoData;
}

FAmmoData USandboxGameInstance::L86Data()
{
	L86AmmoData.Damage = 60.F;
	L86AmmoData.CriticalHit = 8.F;
	L86AmmoData.DamageRadius = 0.F;

	return L86AmmoData;
}

FAmmoData USandboxGameInstance::ShortStrokeARData()
{
	ShortStrokeARAmmoData.Damage = 55.F;
	ShortStrokeARAmmoData.CriticalHit = 10.F;
	ShortStrokeARAmmoData.DamageRadius = 0.F;

	return ShortStrokeARAmmoData;
}

FAmmoData USandboxGameInstance::SKSData()
{
	SKSAmmoData.Damage = 70.F;
	SKSAmmoData.CriticalHit = 90.F;
	SKSAmmoData.DamageRadius = 0.F;

	return SKSAmmoData;
}

FAmmoData USandboxGameInstance::SMGData()
{
	SMGAmmoData.Damage = 52.F;
	SMGAmmoData.CriticalHit = 6.F;
	SMGAmmoData.DamageRadius = 0.F;

	return SMGAmmoData;
}

FAmmoData USandboxGameInstance::T38Data()
{
	T38AmmoData.Damage = 59.F;
	T38AmmoData.CriticalHit = 15.F;
	T38AmmoData.DamageRadius = 0.F;

	return T38AmmoData;
}

FAmmoData USandboxGameInstance::XM82Data()
{
	XM82AmmoData.Damage = 59.F;
	XM82AmmoData.CriticalHit = 10.F;
	XM82AmmoData.DamageRadius = 0.F;

	return XM82AmmoData;
}

FAmmoData USandboxGameInstance::SVDData()
{
	SVDAmmoData.Damage = 78.F;
	SVDAmmoData.CriticalHit = 20.F;
	SVDAmmoData.DamageRadius = 0.F;

	return SVDAmmoData;
}

FAmmoData USandboxGameInstance::NavySMGData()
{
	NavySMGAmmoData.Damage = 56.F;
	NavySMGAmmoData.CriticalHit = 15.F;
	NavySMGAmmoData.DamageRadius = 0.F;

	return NavySMGAmmoData;
}

FAmmoData USandboxGameInstance::MicroSMGData()
{
	MicroSMGAmmoData.Damage = 42.F;
	MicroSMGAmmoData.CriticalHit = 19.F;
	MicroSMGAmmoData.DamageRadius = 0.F;

	return MicroSMGAmmoData;
}

FAmmoData USandboxGameInstance::M4A1Data()
{
	M4A1AmmoData.Damage = 50.F;
	M4A1AmmoData.CriticalHit = 14.F;
	M4A1AmmoData.DamageRadius = 0.F;

	return M4A1AmmoData;
}

FAmmoData USandboxGameInstance::ItalianShotgunData()
{
	ItalianShotgunAmmoData.Damage = 24.F;
	ItalianShotgunAmmoData.CriticalHit = 10.F;
	ItalianShotgunAmmoData.DamageRadius = 0.F;

	return ItalianShotgunAmmoData;
}

FAmmoData USandboxGameInstance::AK74Data()
{
	AK74AmmoData.Damage = 65.F;
	AK74AmmoData.CriticalHit = 14.F;
	AK74AmmoData.DamageRadius = 0.F;

	return AK74AmmoData;
}

FPropData USandboxGameInstance::RedBarrelData()
{
	RedBarrelPropData.Health = 20.F;
	RedBarrelPropData.DamageRadius = 550.F;
	RedBarrelPropData.DamageToDeal = 100;

	return RedBarrelPropData;
}

FPropData USandboxGameInstance::OrangeBarrelData()
{
	OrangeBarrelPropData.Health = 10.F;
	OrangeBarrelPropData.DamageRadius = 450.F;
	OrangeBarrelPropData.DamageToDeal = 95;

	return OrangeBarrelPropData;
}

FPropData USandboxGameInstance::PlainBarrelData()
{
	PlainBarrelPropData.DamageRadius = 400.F;
	PlainBarrelPropData.Health = 40.F;
	PlainBarrelPropData.DamageToDeal = 90;

	return PlainBarrelPropData;
}

FPropData USandboxGameInstance::PlainJerryCanData()
{
	PlainJerryCanPropData.DamageRadius = 35.F;
	PlainJerryCanPropData.DamageToDeal = 30;
	PlainJerryCanPropData.Health = 10;

	return PlainJerryCanPropData;
}

FPropData USandboxGameInstance::RedJerryCanData()
{
	RedJerryCanPropData.DamageRadius = 40.F;
	RedJerryCanPropData.DamageToDeal = 25;
	RedJerryCanPropData.Health = 10;

	return RedJerryCanPropData;
}

FPropData USandboxGameInstance::GreenJerryCanData()
{
	GreenJerryCanPropData.DamageRadius = 25.F;
	GreenJerryCanPropData.DamageToDeal = 35;
	GreenJerryCanPropData.Health = 10;

	return GreenJerryCanPropData;
}

FPropData USandboxGameInstance::PropaneGasCylinderYellowData()
{
	PropaneGasCylinderYellowPropData.DamageRadius = 90.F;
	PropaneGasCylinderYellowPropData.DamageToDeal = 90;
	PropaneGasCylinderYellowPropData.Health = 10;

	return PropaneGasCylinderYellowPropData;
}

FPropData USandboxGameInstance::PropaneGasCylinderRedData()
{
	PropaneGasCylinderRedPropData.DamageRadius = 65.F;
	PropaneGasCylinderRedPropData.DamageToDeal = 70;
	PropaneGasCylinderRedPropData.Health = 10;

	return PropaneGasCylinderRedPropData;
}

FPropData USandboxGameInstance::PropaneGasCylinderPlainData()
{
	PropaneGasCylinderPlainPropData.DamageRadius = 75.F;
	PropaneGasCylinderPlainPropData.DamageToDeal = 55;
	PropaneGasCylinderPlainPropData.Health = 10;

	return PropaneGasCylinderPlainPropData;
}

FPropData USandboxGameInstance::PropaneCylinderTallYellowData()
{
	PropaneCylinderTallYellowPropData.DamageRadius = 100.F;
	PropaneCylinderTallYellowPropData.DamageToDeal = 50;
	PropaneCylinderTallYellowPropData.Health = 10;

	return PropaneCylinderTallYellowPropData;
}

FPropData USandboxGameInstance::PropaneCylinderTallRedData()
{
	PropaneCylinderTallRedPropData.DamageRadius = 110.F;
	PropaneCylinderTallRedPropData.DamageToDeal = 70;
	PropaneCylinderTallRedPropData.Health = 10;

	return PropaneCylinderTallRedPropData;
}

FPropData USandboxGameInstance::PropaneCylinderTallPlainData()
{
	PropaneCylinderTallPlainPropData.DamageRadius = 100.F;
	PropaneCylinderTallPlainPropData.DamageToDeal = 70;
	PropaneCylinderTallPlainPropData.Health = 10;

	return PropaneCylinderTallPlainPropData;
}

FPropData USandboxGameInstance::PortaPottyData()
{
	ProtaPottyPropData.DamageRadius = 450.F;
	ProtaPottyPropData.DamageToDeal = 70;
	ProtaPottyPropData.Health = 10;

	return ProtaPottyPropData;
}

