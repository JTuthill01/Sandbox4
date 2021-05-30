#pragma once

UENUM(BlueprintType)
enum class EHasWeapon : uint8 { NoWeapon, HasWeapon };

UENUM(BlueprintType)
enum class EWeaponSlot : uint8 { First_Slot, Second_Slot, Third_Slot };

UENUM(BlueprintType)
enum class EWeaponType : uint8 { TT38, ShortStrokeAR, AmericanShotgun, Bulldog, L86, HandCannon, AK47, SMG, BelgianAR, SKS, XM82, AK74, M4A1, NavySMG, ItalianShotgun, MicroSMG, SVD };

UENUM(BlueprintType)
enum class EWeaponClass : uint8 { Pistol, Rifle, Shotgun };

UENUM(BlueprintType)
enum class EFireType : uint8 { Hitscan, Projectile };

UENUM(BlueprintType)
enum class EPropType : uint8 { PlainBarrel, RedBarrel, OrangeBarrel };

enum EShotgunReloadIndex : uint8 { Start, Loop, End };

