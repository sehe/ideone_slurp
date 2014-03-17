// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-09 21:34:07
// status:	0
// result:	15
// memory:	2720
// signal:	0
// public:	false
// ------------------------------------------------
enum AttackFlags
{
	Contact                     = 1,                                // Move connects with target
	Projectile                  = Contact << 1,                     // Attack is projectile based
	Unblockable                 = Projectile << 1,                  // Attack can not be blocked
	UncounterableLv1            = Unblockable << 1,                 // Attack can't be countered except by extreme counter attack skills/status effects
	UncounterableLv2            = UncounterableLv1 << 1,            // Attack can not be countered
	Flinches                    = UncounterableLv2 << 1,            // Has a chance to stun the enemy, pushing back their next turn
	Unreflectable               = Flinches << 1,                    // Attack penetrates reflect. Only checked for Magic attacks
	IgnoreDefenderStatusEffects = Unreflectable << 1,               // Ignores active status effects on the defender
	IgnoreAttackerStatusEffects = IgnoreDefenderStatusEffects << 1, // Ignores active status effects on the attacker
	IgnoreDefenderAbilities     = IgnoreAttackerStatusEffects << 1, // Ignore the defenders abilities
	IgnoreAttackerAbilities     = IgnoreDefenderAbilities << 1,     // Ignore the attackers abilities
	IgnoreArmorRating           = IgnoreAttackerAbilities << 1,     // Ignore the defensive boosts of armor
	IgnoreWeaponRating          = IgnoreArmorRating << 1,           // Ignore the attack boost from weapons
	HighCritical                = IgnoreWeaponRating << 1,          // The move has an increased chance to crit
	CausesStatus                = HighCritical << 1,                // Can the move cause status effects?
	Elemental                   = CausesStatus << 1,                // Is the move elemental based?
	Unimplemented               = Elemental << 1,                   // has the move been implemented yet?
	ModsTimer                   = Unimplemented << 1,               // Does it have an effect on the target or users timer?
	Heals                       = ModsTimer << 1,                   // Does the move heal?
	SecondaryEffects            = Heals << 1,                       // Attack has additional effects besides basic attack
	PhysicalAttackFlag          = SecondaryEffects << 1,            // Is the Class Physically based? I.E. blocked by Protect and Shield
	MagicAttackFlag             = PhysicalAttackFlag << 1,          // Is the move Magically Based? I.E. is it affected by things like Shell
	MultiHit                    = MagicAttackFlag << 1,             // Does it enxcapsulate more then 1 hit
	SingleUse                   = MultiHit << 1,                    // Attack can only be used once per battle
	DoesNotCauseDamage          = SingleUse << 1,

	MaskAttack		= MagicAttackFlag | PhysicalAttackFlag,
	MaskIgnore      = IgnoreWeaponRating | IgnoreArmorRating | IgnoreAttackerAbilities | IgnoreDefenderAbilities | IgnoreAttackerStatusEffects,
	// etc
};

static bool HasAttackFlag(AttackFlags flags)
{
	return flags & MaskAttack;
}

static bool HasIgnoreFlag(AttackFlags flags)
{
	return flags & MaskIgnore;
}

static AttackFlags MiscFlags(AttackFlags flags)
{
	return (AttackFlags) (flags & ~(MaskAttack | MaskIgnore));
}

int main()
{
}
// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:34: warning: ‘bool HasAttackFlag(AttackFlags)’ defined but not used
prog.cpp:39: warning: ‘bool HasIgnoreFlag(AttackFlags)’ defined but not used
prog.cpp:44: warning: ‘AttackFlags MiscFlags(AttackFlags)’ defined but not used

#endif
