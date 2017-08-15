// Fill out your copyright notice in the Description page of Project Settings.

#include "EncoderConverterLib.h"

FString UEncoderConverterLib::UTF8String2String(const FString fuckingUTF8String)
{

	TCHAR* outTchar = new TCHAR[fuckingUTF8String.Len() + 1];
	FuckUTF8Converter(outTchar, *fuckingUTF8String, fuckingUTF8String.Len());
	FString dest = outTchar;

	return dest;
}

void UEncoderConverterLib::FuckUTF8Converter(TCHAR* dest, const TCHAR* source, int len)
{
	const TCHAR key = 0xE0, keyA = 0x0F, keyB = 0x3F;

	int i = 0, j = 0;

	while (i < len)
	{
		if ((uint32)source[i] > (uint32)key)
		{
			TCHAR A = (source[i++] & keyA) << 12;
			TCHAR B = (source[i++] & keyB) << 6;
			TCHAR C = (source[i++] & keyB);
			TCHAR D = A | B | C;
			dest[j++] = D;
		}
		else
		{
			dest[j++] = source[i++];
		}
	}
	dest[j] = '\0';
}

