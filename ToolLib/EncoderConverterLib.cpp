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
	const TCHAR keyKey = 0x0080, keyB = 0x3F;
	

	int i = 0, j = 0;

	TCHAR combKey = 0;
	int keyNum = 0;
	uint32 helpVar = 0;

	while (i < len)
	{
		helpVar = (uint32)source[i];
		combKey = 0;
		keyNum = 0;

		while ((helpVar & keyKey) > 0)
		{
			combKey = keyKey | (combKey>>1);
			helpVar = helpVar << 1;
			++keyNum;
		}

		if (keyNum > 0)
		{
			TCHAR convValue = ~combKey & source[i++];
			while (--keyNum > 0)
			{
				convValue = (convValue << 6) | (source[i++] & keyB);
			}
			dest[j++] = convValue;
		}
		else
		{
			dest[j++] = source[i++];
		}
	}
	dest[j] = '\0';
}

