// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SURVIVAL_BasePlayerController_generated_h
#error "BasePlayerController.generated.h already included, missing '#pragma once' in BasePlayerController.h"
#endif
#define SURVIVAL_BasePlayerController_generated_h

#define Survival_Source_Survival_BasePlayerController_h_16_RPC_WRAPPERS
#define Survival_Source_Survival_BasePlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Survival_Source_Survival_BasePlayerController_h_16_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABasePlayerController(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_ABasePlayerController(); \
	public: \
	DECLARE_CLASS(ABasePlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(ABasePlayerController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ABasePlayerController*>(this); }


#define Survival_Source_Survival_BasePlayerController_h_16_INCLASS \
	private: \
	static void StaticRegisterNativesABasePlayerController(); \
	friend SURVIVAL_API class UClass* Z_Construct_UClass_ABasePlayerController(); \
	public: \
	DECLARE_CLASS(ABasePlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Survival"), NO_API) \
	DECLARE_SERIALIZER(ABasePlayerController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ABasePlayerController*>(this); }


#define Survival_Source_Survival_BasePlayerController_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABasePlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABasePlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasePlayerController(ABasePlayerController&&); \
	NO_API ABasePlayerController(const ABasePlayerController&); \
public:


#define Survival_Source_Survival_BasePlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasePlayerController(ABasePlayerController&&); \
	NO_API ABasePlayerController(const ABasePlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasePlayerController)


#define Survival_Source_Survival_BasePlayerController_h_16_PRIVATE_PROPERTY_OFFSET
#define Survival_Source_Survival_BasePlayerController_h_12_PROLOG
#define Survival_Source_Survival_BasePlayerController_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_BasePlayerController_h_16_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_BasePlayerController_h_16_RPC_WRAPPERS \
	Survival_Source_Survival_BasePlayerController_h_16_INCLASS \
	Survival_Source_Survival_BasePlayerController_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Survival_Source_Survival_BasePlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Survival_Source_Survival_BasePlayerController_h_16_PRIVATE_PROPERTY_OFFSET \
	Survival_Source_Survival_BasePlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Survival_Source_Survival_BasePlayerController_h_16_INCLASS_NO_PURE_DECLS \
	Survival_Source_Survival_BasePlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Survival_Source_Survival_BasePlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
