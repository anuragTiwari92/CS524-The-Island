// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SURVIVAL_BTTask_FindNextPatrolPoint_generated_h
#error "BTTask_FindNextPatrolPoint.generated.h already included, missing '#pragma once' in BTTask_FindNextPatrolPoint.h"
#endif
#define SURVIVAL_BTTask_FindNextPatrolPoint_generated_h

#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_RPC_WRAPPERS
#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUBTTask_FindNextPatrolPoint(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_UBTTask_FindNextPatrolPoint(); \
	public: \
	DECLARE_CLASS(UBTTask_FindNextPatrolPoint, UBTTask_BlackboardBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(UBTTask_FindNextPatrolPoint) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_INCLASS \
	private: \
	static void StaticRegisterNativesUBTTask_FindNextPatrolPoint(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_UBTTask_FindNextPatrolPoint(); \
	public: \
	DECLARE_CLASS(UBTTask_FindNextPatrolPoint, UBTTask_BlackboardBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(UBTTask_FindNextPatrolPoint) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBTTask_FindNextPatrolPoint(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBTTask_FindNextPatrolPoint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTTask_FindNextPatrolPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTTask_FindNextPatrolPoint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBTTask_FindNextPatrolPoint(UBTTask_FindNextPatrolPoint&&); \
	NO_API UBTTask_FindNextPatrolPoint(const UBTTask_FindNextPatrolPoint&); \
public:


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBTTask_FindNextPatrolPoint(UBTTask_FindNextPatrolPoint&&); \
	NO_API UBTTask_FindNextPatrolPoint(const UBTTask_FindNextPatrolPoint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTTask_FindNextPatrolPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTTask_FindNextPatrolPoint); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBTTask_FindNextPatrolPoint)


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetLocation() { return STRUCT_OFFSET(UBTTask_FindNextPatrolPoint, TargetLocation); } \
	FORCEINLINE static uint32 __PPO__PatrolRoute() { return STRUCT_OFFSET(UBTTask_FindNextPatrolPoint, PatrolRoute); }


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_17_PROLOG
#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_RPC_WRAPPERS \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_INCLASS \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_INCLASS_NO_PURE_DECLS \
	Survival_Source_Survival_BTTask_FindNextPatrolPoint_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Survival_Source_Survival_BTTask_FindNextPatrolPoint_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
