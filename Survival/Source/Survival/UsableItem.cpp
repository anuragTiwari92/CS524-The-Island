// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "UsableItem.h"





bool AUsableItem::UseItem()
{
	check(GetInventoryOwner());

	return true;
}