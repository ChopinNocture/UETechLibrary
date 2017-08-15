// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPToJsonLibrary.generated.h"



/*===========================================
眼控数据结构 从设备SDK中取得
============================================*/
USTRUCT(BlueprintType)
struct FEyeInfoData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		float EyePosX;						// 瞳孔中心在拍摄图像上的位置X

	UPROPERTY(BlueprintReadWrite)
		float EyePosY;						// 瞳孔中心在拍摄图像上的位置Y	

	UPROPERTY(BlueprintReadWrite)
		float EyeArea;						// 瞳孔面积（像素单位)

public:
	FEyeInfoData()
	{
		FMemory::Memzero(this, sizeof(*this));
	}
	//bool ParseFromJSON(TSharedPtr<FJsonObject> Tree, const FString& NameForErrors, bool bSilent);
};


// 游戏中的数据采集信息
USTRUCT(BlueprintType)
struct FEyeCaptureStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		int32 iSceneID = -1;			// 场景ID

	UPROPERTY(BlueprintReadWrite)
		int32 iDiamondID = -1;			// 钻石ID

	UPROPERTY(BlueprintReadWrite)
		int32 iPickTimes = -1;			// 钻石观察次数

	UPROPERTY(BlueprintReadWrite)
		float fSampleDuration;					// 信息采样间隔

	UPROPERTY(BlueprintReadWrite)
		int32 length = 0;						// 数组长度

	UPROPERTY(BlueprintReadWrite)
		TArray<FEyeInfoData> arrEyeInfo;					// 该钻石的眼动采样数据

public:
	FEyeCaptureStruct()
	{
		FMemory::Memzero(this, sizeof(*this));

	}
};


/**
 * 
 */
UCLASS()
class DIAMONDPROJ_API UBPToJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	static FString ConvertEyeCapStructToJsonString(FEyeCaptureStruct eyeCapInfo);

	UFUNCTION(BlueprintCallable)
	static bool WriteEyeCapStructToFile(FEyeCaptureStruct eyeCapInfo, FString fileName);

	UFUNCTION(BlueprintPure)
	static FString ConvertEyeCapInfoListToJsonString(TArray<FEyeCaptureStruct> arrEyeCapInfo);

	UFUNCTION(BlueprintCallable)
	static bool WriteEyeCapInfoListToFile(TArray<FEyeCaptureStruct> arrEyeCapInfo, FString fileName);
};

