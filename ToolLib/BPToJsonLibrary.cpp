// Fill out your copyright notice in the Description page of Project Settings.

#include "DIamondProj.h"
#include "BPToJsonLibrary.h"
#include "JsonObjectConverter.h"





FString UBPToJsonLibrary::ConvertEyeCapStructToJsonString(FEyeCaptureStruct eyeCapInfo)
{
	FString OutContentString;

	eyeCapInfo.length = eyeCapInfo.arrEyeInfo.Num();
	FJsonObjectConverter::UStructToJsonObjectString<FEyeCaptureStruct>(eyeCapInfo, OutContentString, 0, 0);

	return OutContentString;
}

bool UBPToJsonLibrary::WriteEyeCapStructToFile(FEyeCaptureStruct eyeCapInfo, FString fileName)
{
	FString OutContentString;

	OutContentString = ConvertEyeCapStructToJsonString(eyeCapInfo);

	FFileHelper::SaveStringToFile(OutContentString, *fileName);

	return true;
}



FString UBPToJsonLibrary::ConvertEyeCapInfoListToJsonString(TArray<FEyeCaptureStruct> arrEyeCapInfo)
{
	FString OutContentString = "";

	for(TArray<FEyeCaptureStruct>::TIterator iter(arrEyeCapInfo); iter; iter++)
	{
		OutContentString += ConvertEyeCapStructToJsonString(*iter) + ", \n";
	}

	return OutContentString;
}

bool UBPToJsonLibrary::WriteEyeCapInfoListToFile(TArray<FEyeCaptureStruct> arrEyeCapInfo, FString fileName)
{
	FFileHelper::SaveStringToFile(ConvertEyeCapInfoListToJsonString(arrEyeCapInfo), *fileName);
	return true;
}