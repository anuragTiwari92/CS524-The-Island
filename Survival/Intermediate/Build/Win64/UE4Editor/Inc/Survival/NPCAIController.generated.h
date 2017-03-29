// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SURVIVAL_NPCAIController_generated_h
#error "NPCAIController.generated.h already included, missing '#pragma once' in NPCAIController.h"
#endif
#define SURVIVAL_NPCAIController_generated_h

#define Survival_Source_Survival_NPCAIController_h_11_GENERATED_BODY \
	friend SURVIVAL_API class UScriptStruct* Z_Construct_UScriptStruct_FNPCEnemyPerceptionInfo(); \
	SURVIVAL_API static class UScriptStruct* StaticStruct();


#define Survival_Source_Survival_NPCAIController_h_35_RPC_WRAPPERS
#define Survival_Source_Survival_NPCAIController_h_35_RPC_WRAPPERS_NO_PURE_DECLS
#define Survival_Source_Survival_NPCAIController_h_35_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesANPCAIController(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_ANPCAIController(); \
	public: \
	DECLARE_CLASS(ANPCAIController, ABaseAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(ANPCAIController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_NPCAIController_h_35_INCLASS \
	private: \
	static void StaticRegisterNativesANPCAIController(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_ANPCAIController(); \
	public: \
	DECLARE_CLASS(ANPCAIController, ABaseAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(ANPCAIController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Survival_Source_Survival_NPCAIController_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANPCAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANPCAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPCAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPCAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPCAIController(ANPCAIController&&); \
	NO_API ANPCAIController(const ANPCAIController&); \
public:


#define Survival_Source_Survival_NPCAIController_h_35_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANPCAIController() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPCAIController(ANPCAIController&&); \
	NO_API ANPCAIController(const ANPCAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPCAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPCAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANPCAIController)


#define Survival_Source_Survival_NPCAIController_h_35_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__KnownEnemies() { return STRUCT_OFFSET(ANPCAIController, KnownEnemies); }


#define Survival_Source_Survival_NPCAIController_h_32_PROLOG
#define Survival_Source_Survival_NPCAIController_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_NPCAIController_h_35_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_NPCAIController_h_35_RPC_WRAPPERS \
	Survival_Source_Survival_NPCAIController_h_35_INCLASS \
	Survival_Source_Survival_NPCAIController_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Survival_Source_Survival_NPCAIController_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_NPCAIController_h_35_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_NPCAIController_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	Survival_Source_Survival_NPCAIController_h_35_INCLASS_NO_PURE_DECLS \
	Survival_Source_Survival_NPCAIController_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Survival_Source_Survival_NPCAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
