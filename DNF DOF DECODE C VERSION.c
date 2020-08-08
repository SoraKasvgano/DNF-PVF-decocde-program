int PvfPlayer::_decryptTreeBlock(unsigned char* buf, unsigned int bufLen, int numberOfFiles, int checkSumCheck, int checksumUse)
{
unsigned int bufLenv5; // ebx@1
unsigned char *bufv6; // esi@1
int result; // eax@2
unsigned char * bufEnd; // edx@3
unsigned int v9; // eax@3
unsigned char * i; // ecx@3
unsigned int v11; // esi@4
unsigned int v12; // eax@4
unsigned int v13; // eax@4
unsigned int v14; // eax@4
unsigned int v15[256]; // [sp+8h] [bp-404h]@3




bufLenv5 = bufLen;
bufv6 = buf;
if (bufLen & 3) // bufLen shall be fold of 4
{
result = 0;
}
else
{
this->_sub_311820(v15);
bufEnd = bufv6 + 4 * (bufLenv5 >> 2); // >>2 then * 4, this is truncation
v9 = ~numberOfFiles;
for (i = bufv6; i != bufEnd; i += 4)
{
v11 = __ROR4__(checksumUse ^ *(unsigned int *)i ^ 0x81A79011, 6);
*(unsigned int *)i = v11;
v12 = v15[(unsigned char)v9 ^ *(unsigned char *)i] ^ (v9 >> 8);
v13 = v15[(unsigned char)v12 ^ *(unsigned char *)(i + 1)] ^ (v12 >> 8);
v14 = v15[(unsigned char)v13 ^ *(unsigned char *)(i + 2)] ^ (v13 >> 8);
v9 = v15[(unsigned char)v14 ^ *(unsigned char *)(i + 3)] ^ (v14 >> 8);
}
result = ~v9 == checkSumCheck;
}
return result;
}


unsigned int PvfPlayer::_sub_311820(unsigned int *a1)
{
unsigned int v1; // ecx@1
unsigned int v2; // esi@1
unsigned int result; // eax@2
unsigned int *v4; // edx@2




v1 = 1;
*a1 = 0;
v2 = 128;
do
{
v1 = ((v1 & 1) != 0 ? 0xEDB88320 : 0) ^ (v1 >> 1);
result = 0;
v4 = &a1[v2];
do
{
*v4 = v1 ^ a1[result];
result += 2 * v2;
v4 += 2 * v2;
} while (result <= 0xFF);
v2 >>= 1;
} while (v2);
return result;
}
}