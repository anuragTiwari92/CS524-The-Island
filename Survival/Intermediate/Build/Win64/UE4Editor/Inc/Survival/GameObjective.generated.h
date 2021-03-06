// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SURVIVAL_GameObjective_generated_h
#error "GameObjective.generated.h already included, missing '#pragma once' in GameObjective.h"
#endif
#define SURVIVAL_GameObjective_generated_h

#define Survival_Source_Survival_GameObjective_h_11_RPC_WRAPPERS
#define Survival_Source_Survival_GameObjective_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define Survival_Source_Survival_GameObjective_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAGameObjective(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_AGameObjective(); \
	public: \
	DECLARE_CLASS(AGameObjective, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(AGameObjective) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_GameObjective_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAGameObjective(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_AGameObjective(); \
	public: \
	DECLARE_CLASS(AGameObjective, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(AGameObjective) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_GameObjective_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameObjective(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameObjective) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameObjective); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameObjective); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameObjective(AGameObjective&&); \
	NO_API AGameObjective(const AGameObjective&); \
public:


#define Survival_Source_Survival_GameObjective_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameObjective(AGameObjective&&); \
	NO_API AGameObjective(const AGameObjective&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameObjective); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameObjective); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameObjective)


#define Survival_Source_Survival_GameObjective_h_11_PRIVATE_PROPERTY_OFFSET
#define Survival_Source_Survival_GameObjective_h_8_PROLOG
#define Survival_Source_Survival_GameObjective_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_GameObjective_h_11_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_GameObjective_h_11_RPC_WRAPPERS \
	Survival_Source_Survival_GameObjective_h_11_INCLASS \
	Survival_Source_Survival_GameObjective_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Survival_Source_Survival_GameObjective_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_GameObjective_h_11_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_GameObjective_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Survival_Source_Survival_GameObjective_h_11_INCLASS_NO_PURE_DECLS \
	Survival_Source_Survival_GameObjective_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Survival_Source_Survival_GameObjective_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
