// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EncoderConverterLib.generated.h"

/**
 * 
 */
UCLASS()
class SQLTEST_API UEncoderConverterLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void FuckUTF8Converter(TCHAR* dest, const TCHAR* source, int len);

	UFUNCTION(BlueprintPure, Category = "Sql Server|FuckConverter")
	static FString UTF8String2String(const FString fuckingUTF8String);
	
};
