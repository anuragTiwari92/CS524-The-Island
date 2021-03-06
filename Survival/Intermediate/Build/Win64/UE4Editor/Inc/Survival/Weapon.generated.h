// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SURVIVAL_Weapon_generated_h
#error "Weapon.generated.h already included, missing '#pragma once' in Weapon.h"
#endif
#define SURVIVAL_Weapon_generated_h

#define Survival_Source_Survival_Weapon_h_14_RPC_WRAPPERS
#define Survival_Source_Survival_Weapon_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Survival_Source_Survival_Weapon_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAWeapon(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_AWeapon(); \
	public: \
	DECLARE_CLASS(AWeapon, AItem, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(AWeapon) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_Weapon_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesAWeapon(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_AWeapon(); \
	public: \
	DECLARE_CLASS(AWeapon, AItem, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(AWeapon) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_Weapon_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWeapon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public:


#define Survival_Source_Survival_Weapon_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWeapon() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWeapon)


#define Survival_Source_Survival_Weapon_h_14_PRIVATE_PROPERTY_OFFSET
#define Survival_Source_Survival_Weapon_h_11_PROLOG
#define Survival_Source_Survival_Weapon_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_Weapon_h_14_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_Weapon_h_14_RPC_WRAPPERS \
	Survival_Source_Survival_Weapon_h_14_INCLASS \
	Survival_Source_Survival_Weapon_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Survival_Source_Survival_Weapon_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_Weapon_h_14_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_Weapon_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Survival_Source_Survival_Weapon_h_14_INCLASS_NO_PURE_DECLS \
	Survival_Source_Survival_Weapon_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Survival_Source_Survival_Weapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
