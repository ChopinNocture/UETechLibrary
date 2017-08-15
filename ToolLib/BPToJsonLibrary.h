// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPToJsonLibrary.generated.h"



/*===========================================
�ۿ����ݽṹ ���豸SDK��ȡ��
============================================*/
USTRUCT(BlueprintType)
struct FEyeInfoData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		float EyePosX;						// ͫ������������ͼ���ϵ�λ��X

	UPROPERTY(BlueprintReadWrite)
		float EyePosY;						// ͫ������������ͼ���ϵ�λ��Y	

	UPROPERTY(BlueprintReadWrite)
		float EyeArea;						// ͫ����������ص�λ)

public:
	FEyeInfoData()
	{
		FMemory::Memzero(this, sizeof(*this));
	}
	//bool ParseFromJSON(TSharedPtr<FJsonObject> Tree, const FString& NameForErrors, bool bSilent);
};


// ��Ϸ�е����ݲɼ���Ϣ
USTRUCT(BlueprintType)
struct FEyeCaptureStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		int32 iSceneID = -1;			// ����ID

	UPROPERTY(BlueprintReadWrite)
		int32 iDiamondID = -1;			// ��ʯID

	UPROPERTY(BlueprintReadWrite)
		int32 iPickTimes = -1;			// ��ʯ�۲����

	UPROPERTY(BlueprintReadWrite)
		float fSampleDuration;					// ��Ϣ�������

	UPROPERTY(BlueprintReadWrite)
		int32 length = 0;						// ���鳤��

	UPROPERTY(BlueprintReadWrite)
		TArray<FEyeInfoData> arrEyeInfo;					// ����ʯ���۶���������

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

