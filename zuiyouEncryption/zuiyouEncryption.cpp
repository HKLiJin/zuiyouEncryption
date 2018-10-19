// zuiyouEncryption.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

#define u_int64_t unsigned long long
#define u_int32_t unsigned int

struct TAG_UINT64
{
	u_int32_t low;
	u_int32_t high;

	void set(u_int32_t _high, u_int32_t _low){
		this->high = _high;
		this->low = _low;
	}
};

u_int64_t qword_101126D90 = 0xEFCDAB8967452301;
u_int64_t qword_101126D98 = 0x1032547698BADCFE;
char a0123456789abcd_0[] = "0123456789abcdef";
unsigned char byte_101209EC8[] =
{
	0x78, 0xA4, 0x6A, 0xD7, 0x56, 0xB7, 0xC7, 0xE8, 0xDB, 0x70, 0x20, 0x24, 0xEE, 0xCE, 0xBD, 0xC1, 0xAF, 0xF,
	0x7C, 0xF5, 0x2A, 0xC6, 0x87, 0x47, 0x13, 0x46, 0x30, 0xA8, 1, 0x95, 0x46, 0xFD, 0xD8, 0x98, 0x80, 0x69, 0xAF, 0xF7, 0x44, 0x8B, 0xB1, 0x5B, 0xFF, 0xFF, 0xBE,
	0xD7, 0x5C, 0x89, 0x22, 0x11, 0x90, 0x6B, 0x93, 0x71, 0x98, 0xFD, 0x8E, 0x43, 0x79, 0xA6, 0x21, 8, 0xB4, 0x49, 0x62, 0x25, 0x1E, 0xF6, 0x40, 0xB3, 0x40, 0xC0,
	0x51, 0x5A, 0x5E, 0x26, 0xAA, 0xC7, 0xB6, 0xE9, 0x5D, 0x10, 0x2F, 0xD6, 0x53, 0x14, 0x44, 2, 0x81, 0xE6, 0xA1, 0xD8, 0xC8, 0xFB, 0xD3, 0xE7, 0xE6, 0xCD, 0xE1,
	0x21, 0xD6, 7, 0x37, 0xC3, 0x87, 0xD, 0xD5, 0xF4, 0xED, 0x14, 0x5A, 0x45, 5, 0xE9, 0xE3, 0xA9, 0xF8, 0xA3, 0xEF, 0xFC, 0xD9, 2, 0x6F, 0x67, 0x8A, 0x4C, 0x2A,
	0x8D, 0x42, 0x39, 0xFA, 0xFF, 0x81, 0xF6, 0x71, 0x87, 0x22, 0x61, 0x9D, 0x6D, 0xC, 0x38, 0xE5, 0xFD, 0x44, 0xEA, 0xBE, 0xA4, 0xA9, 0xCF, 0xDE, 0x4B, 0x60, 0x4B,
	0xBB, 0xF6, 0x70, 0xBC, 0xBF, 0xBE, 0xC6, 0x7E, 0x9B, 0x28, 0xFA, 0x27, 0xA1, 0xEA, 0x85, 0x30, 0xEF, 0xD4, 5, 0x1D, 0x88, 4, 0x39, 0xD0, 0xD4, 0xD9, 0xE5, 0x99,
	0xDB, 0xE6, 0xF8, 0x7C, 0xA2, 0x1F, 0x65, 0x56, 0xAC, 0xC4, 0x44, 0x22, 0x29, 0xF4, 0x97, 0xFF, 0x2A, 0x43, 0xA7, 0x23, 0x94, 0xAB, 0x39, 0xA0, 0x93, 0xFC, 0xC3,
	0x59, 0x5B, 0x65, 0x92, 0xCC, 0xC, 0x8F, 0x7D, 0xF4, 0xEF, 0xFF, 0xD1, 0x5D, 0x84, 0x85, 0x4F, 0x7E, 0xA8, 0x6F, 0xE0, 0xE6, 0x2C, 0xFE, 0x14, 0x43, 1, 0xA3,
	0xA1, 0x11, 8, 0x4E, 0x82, 0x7E, 0x53, 0xF7, 0x35, 0xF2, 0x3A, 0xBD, 0xBB, 0xD2, 0xD7, 0x2A, 0x91, 0xD3, 0x86, 0xEB, 0, 0, 0, 0, 0x80, 0x88, 0xE5, 0x40, 0,
	0, 0, 0, 0, 0x7C, 0xD5, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56,
	0x57, 0x58, 0x59, 0x5A, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
	0x78, 0x79, 0x7A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x2B, 0x2F, 0xA2, 0xB4, 0xB7, 0x3E, 0x8F, 0x53, 0x34, 0x3F, 0x4D, 0x15, 0xC, 0x3E,
	0, 0, 0, 0, 0x87, 0x16, 0x99, 0x3E, 0xA2, 0x45, 0x16, 0x3F, 0xD5, 0x78, 0xE9, 0x3D, 0, 0, 0, 0, 0xD8, 0xF0, 0x74, 0x3E, 0x69, 0x6F, 0xF0, 0x3E, 0, 0, 0, 0, 0,
	0x80, 0x63, 0x40, 0x56, 0x56, 0x56, 0x56, 0x56, 0x56, 0xE6, 0x3F, 0, 0, 0, 0, 0, 0x60, 0x6C, 0xC0, 0x51, 0x46, 0x6F, 0xCB, 0x5A, 0x1D, 0x93, 0x3F, 0xD0, 0xB0,
	0x2B, 0x40, 0xEE, 0x35, 0xD7, 0x3F, 0x39, 0xB4, 0xC8, 0x76, 0xBE, 0x9F, 0xCA, 0x3F, 0, 0, 0, 0, 0, 0xA0, 0x72, 0xC0, 0, 0, 0, 0, 0, 0xC0, 0x76, 0xC0, 0, 0,
	0, 0, 0, 0xA0, 0x72, 0x40, 0, 0, 0, 0, 0, 0x40, 0x72, 0x40, 0, 0, 0, 0, 0, 0, 0x6F, 0x40, 0, 2, 0, 0, 0, 0x20, 0, 0, 0x46, 0x46, 0x49, 0x41, 0x66, 0x61, 0x34,
	0x6D, 0x45, 0x56, 0x41, 0x57, 0, 0, 0, 0, 0, 0, 0, 0, 0xF3, 4, 0x35, 0xBF, 0, 0, 0, 0, 0x3A, 0xCD, 0x13, 0x3F, 0x3A, 0xCD, 0x13, 0xBF, 0, 0, 0, 0
};

u_int32_t _bic_(u_int32_t x,u_int32_t m) {
	return x & (x ^ m);
}

u_int32_t _ror_(u_int32_t x, u_int32_t m) {
	return (x >> m) | (x << (32 - m));
}

void sub_100DB274C(u_int64_t X0/*data*/, u_int64_t X1/*dataLen*/, u_int64_t X2/*outdata*/) {

	u_int64_t X3 = 0;
	u_int64_t X4 = 0;
	u_int64_t X5 = 0;
	u_int64_t X6 = 0;
	u_int64_t X8 = 0;
	u_int64_t X9 = 0;
	u_int64_t X10 = 0;
	u_int64_t X11 = 0;
	u_int64_t i = 0;
	u_int64_t X13 = 0;
	u_int64_t X14 = 0;
	u_int64_t X15 = 0;
	u_int64_t X19 = 0;
	u_int64_t X20 = 0;
	u_int64_t X21 = 0;
	u_int64_t X22 = 0;
	u_int64_t X23 = 0;
	u_int64_t X24 = 0;
	u_int64_t X25 = 0;
	u_int64_t X26 = 0;
	u_int64_t X27 = 0;

	char data[0x512] = {0};

	u_int64_t var_120 = (u_int64_t)(data + 0x10);
	u_int64_t var_118 = (u_int64_t)(data + 0x18);
	u_int64_t var_108 = (u_int64_t)(data + 0x28);
	u_int64_t var_100 = (u_int64_t)(data + 0x30);
	u_int64_t var_FC = (u_int64_t)(data + 0x34);
	u_int64_t var_F8 = (u_int64_t)(data + 0x38);
	u_int64_t var_F4 = (u_int64_t)(data + 0x3C);
	u_int64_t var_F0 = (u_int64_t)(data + 0x40);
	u_int64_t var_E8 = (u_int64_t)(data + 0x48);
	u_int64_t var_B0 = (u_int64_t)(data + 0x80);
	u_int64_t var_AC = (u_int64_t)(data + 0x84);
	u_int64_t var_A8 = (u_int64_t)(data + 0x88);
	u_int64_t var_A0 = (u_int64_t)(data + 0x90);
	u_int64_t var_98 = (u_int64_t)(data + 0x98);

	*(u_int64_t*)var_120 = X2;
	X2 = X1;
	X3 = X0;
	X6 = 0;
	X20 = 0;
	*(u_int64_t*)var_A8 = qword_101126D90;
	*(u_int64_t*)var_100 = X2 << 3;
	*(u_int64_t*)var_108 = X2 >> 0x1d;
	X24 = var_E8;
	X19 = X24 + 4;
	*(u_int64_t*)var_A0 = qword_101126D98;
	X21 = X24 + 0x38;
	X5 = 0x67452301;
	X23 = 0x10325476;
	X22 = 0x98BADCFE;
	X4 = 0xEFCDAB89;
	X26 = (u_int64_t)&byte_101209EC8;
	*(u_int64_t*)(var_118) = X19;
	*(u_int64_t*)(var_118+0x8) = X21;
	do
	{
		X8 = X2 - X20;
		X27 = X8 > 0x3F ? 0x40 : X8;
		X1 = X3 + X20;
		if(X27 > 0x3F) {
			X6 = 0;
		}else {
			((TAG_UINT64*)var_F8)->set((u_int32_t)X22, (u_int32_t)X23);
			*(u_int64_t*)var_F0 = X20;
			((TAG_UINT64*)var_FC)->low = (u_int32_t)X5;
			X26 = X4;
			X25 = X3;
			X19 = X2;
			X22 = var_98;
			X2 = X27;
			X0 = var_98;
			X21 = X6;
			X23 = X27;
			memcpy((void*)X0, (void*)X1, X2);
			X22 += X23;
			X8 = 0x40 - X23;
			X1 = X8;
			X0 = X22;
			memset((void*)X0, 0, (u_int32_t)X1);//BL              _bzero
			if(X21 == 0) {
				((unsigned char*)X22)[0] = 0x80;
			}
			X1 = var_98;
			X6 = 1;
			X2 = X19;
			X3 = X25;
			X4 = X26;
			X5 = (u_int32_t)*(u_int64_t*)var_FC;
			X23 = *(u_int64_t*)var_FC >> 32;
			X19 = *(u_int64_t*)var_118;
			X21 = *(u_int64_t*)(var_118 + 0x8);
			X20 = *(u_int64_t*)var_F0;
			X22 = ((TAG_UINT64*)var_F4)->low;
			X26 = (u_int64_t)&byte_101209EC8;
		}
		i = 0;
		do{
			((TAG_UINT64*)(X24 + i))->low = (u_int32_t)(((unsigned char*)(X1+1+i))[-1] | ((((unsigned char*)(X1+1+i))[0] | ((((unsigned char*)(X1+1+i))[1] | (((unsigned char*)(X1+1+i))[2] << 8)) << 8)) << 8));
		}while((i += 4) != 0x40);
		if(X27 <= 0x37) {
			*(u_int64_t*)var_B0 = (u_int32_t)*(u_int64_t*)var_100;
			*(u_int64_t*)var_AC = (u_int32_t)*(u_int64_t*)var_108;
		}
		i = 0;
		X13 = X26 + 8;
		X14 = X24 + 8;
		X8 = X23;
		X9 = X22;
		X10 = X4;
		X11 = X5;
		do
		{
			X11 = _ror_((u_int32_t)((((_bic_((u_int32_t)X8, (u_int32_t)X10) | (X10 & X9)) + X11) + (u_int32_t)*(u_int64_t*)(X14-8)) + (u_int32_t)*(u_int64_t*)(X13-8)), 0x19) + X10;
			X8 = _ror_((u_int32_t)((*(u_int64_t*)(X14 - 8) >> 32) + X8 + (*(u_int64_t*)(X13-8) >> 32) + ((X11 & X10) | _bic_((u_int32_t)X9, (u_int32_t)X11))), 0x14) + X11;
			X9 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)X14 + X9 + (u_int32_t)*(u_int64_t*)X13 + ((X8 & X11) | _bic_((u_int32_t)X10, (u_int32_t)X8))), 0xF) + X8;
			X10 = _ror_((u_int32_t)((*(u_int64_t*)X14 >> 32) + X10 + (*(u_int64_t*)X13 >> 32) + ((X9 & X8) | _bic_((u_int32_t)X11, (u_int32_t)X9))), 0xA) + X9;
			X14 += 0x10;
			X13 += 0x10;
		}while((i += 4) < 0x10);
		i = 0;
		X13 = X26 + 0x4C;
		X14 = 0xA;
		X15 = X19;
		do
		{
			X11 = _ror_((u_int32_t)((((X10 & X8) | _bic_((u_int32_t)X9, (u_int32_t)X8)) + X11 + (u_int32_t)*(u_int64_t*)X15) + (u_int32_t)*(u_int64_t*)(X13-0xc)), 0x1B) + X10;
			X8 = _ror_((u_int32_t)(X8 + ((u_int32_t)*(u_int64_t*)(X24 + (((X14 - 4) & 0xF) << 2))) + (*(u_int64_t*)(X13-0xc) >> 32) + ((X11 & X9) | _bic_((u_int32_t)X10, (u_int32_t)X9))), 0x17) + X11;
			X9 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)(X24 + (((X14 & 0xE) | 1) << 2)) + X9 + (u_int32_t)*(u_int64_t*)(X13-4) + ((X8 & X10) | _bic_((u_int32_t)X11, (u_int32_t)X10))), 0x12) + X8;
			X10 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)(X15-4) + X10 + (u_int32_t)*(u_int64_t*)X13 + ((X9 & X11) | _bic_((u_int32_t)X8, (u_int32_t)X11))), 0xC) + X9;
			X13 += 0x10;
			X15 += 0x10;
			X14 += 0x14;
		}while((i += 4) < 0x10);
		i = 0;
		X13 = X26 + 0x8C;
		X14 = 5;
		X15 = X21;
		do
		{
			X11 = _ror_((u_int32_t)(((X9  ^ X8) ^ X10) + X11 + (u_int32_t)*(u_int64_t*)(X24 + ((X14 & 0xD) << 2)) + (u_int32_t)*(u_int64_t*)(X13-0xc)), 0x1C) + X10;
			X8 = _ror_((u_int32_t)(X8 + (u_int32_t)*(u_int64_t*)(X24 + (((X14 + 3) & 0xF) << 2)) + (*(u_int64_t*)(X13-0xc) >> 32) + ((X11 ^ X10) ^ X9)), 0x15)+ X11;
			X9 = _ror_((u_int32_t)(((u_int32_t)*(u_int64_t*)(X24 + (((X14 + 6) & 0xF) << 2))) + X9 + (u_int32_t)*(u_int64_t*)(X13-4) + (X8 ^ (X11 ^ X10))), 0x10) + X8;
			X10 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)X15 + X10 + (u_int32_t)*(u_int64_t*)X13 + ((X8 ^ X11) ^ X9)), 0x9) + X9;
			X15 -= 0x10;
			X13 += 0x10;
			X14 += 0xC;
		}while((i += 4) < 0x10);
		i = 0;
		X13 = X26 + 0xCC;
		X14 = X21;
		X15 = 0x15;
		do
		{
			X11 = _ror_((u_int32_t)(((((X10 | (~X8)) ^ X9) + X11) + ((u_int32_t)*(u_int64_t*)(X24 + (((X15 - 0x15) & 0xC) << 2)))) + (u_int32_t)*(u_int64_t*)(X13-0xc)), 0x1A) + X10;
			X8 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)(X24 + (((X15 - 0xE) & 0xF) << 2)) + X8 + (*(u_int64_t*)(X13-0xc) >> 32) + ((X11 | (~X9)) ^ X10)), 0x16) + X11;
			X9 = _ror_((u_int32_t)((u_int32_t)*(u_int64_t*)X14 + X9 + (u_int32_t)*(u_int64_t*)(X13-0x4) + ((X8 | (~X10)) ^ X11)), 0x11) + X8;
			X10 = _ror_((u_int32_t)(((u_int32_t)*(u_int64_t*)(X24 + ((X15 & 0xF) << 2))) + X10 + (u_int32_t)*(u_int64_t*)X13 + ((X9 | (~X11)) ^ X8)), 0xB) + X9;
			X13 += 0x10;
			X14 -= 0x10;
			X15 +=0x1C;
		}while((i += 4) < 0x10);
		X5 += X11;
		X4 += X10;
		X22 += X9;
		X23 += X8;
		((TAG_UINT64*)&X27)->high = 0;
		X20 += X27;
	}while(X27 >= 0x38);
	i = 0;
	((TAG_UINT64*)var_A8)->set((u_int32_t)X4, (u_int32_t)X5);
	((TAG_UINT64*)var_A0)->set((u_int32_t)X23, (u_int32_t)X22);
	X13 = *(u_int64_t*)var_120;
	((unsigned char*)(X13))[0] = X5;
	((unsigned char*)(X13))[1] = X5 >> 8;
	((unsigned char*)(X13))[2] = X5 >> 0x10;
	((unsigned char*)(X13))[3] = X5 >> 0x18;
	((unsigned char*)(X13))[4] = X4;
	((unsigned char*)(X13))[5] = X4 >> 8;
	((unsigned char*)(X13))[6] = X4 >> 0x10;
	((unsigned char*)(X13))[7] = X4 >> 0x18;
	do
	{
		X10 = (u_int32_t)*(u_int64_t*)(((u_int64_t)var_A8 + 8) + i);
		X11 = X13 + i;
		((unsigned char*)(X11))[8] = X10;
		((unsigned char*)(X11))[9] = X10 >> 8;
		((unsigned char*)(X11))[0xA] = X10 >> 0x10;
		((unsigned char*)(X11))[0xB] = X10 >> 0x18;
		X10 = i + 0xC;
		i = i + 4;
	}while(X10 < 0x10);
}

void sub_100FB6004(u_int64_t outData, u_int64_t inData) {
	u_int64_t i = 0;
	do{
		((unsigned char*)(outData))[i*2] = a0123456789abcd_0[(((unsigned char*)(inData))[i]) >> 4];
		((unsigned char*)(outData))[i*2+1] = a0123456789abcd_0[(((unsigned char*)(inData))[i]) & 0xF];
	}while((i += 1) < 0x10);
}

std::string	calcSign(const char* szData) {
	std::string str = szData;
	str.append("ZDY0MTBlODcx");
	std::string strHead = str.substr(0, 10);
	std::string strEnd = str.substr(str.length()-10, str.length());
	str.replace(0, 10, strEnd);
	str.replace(str.length()-10, str.length(), strHead);

	char szBuff[64] = {0};
	char szSign[64] = {0};
	std::string strRet = "";
	sub_100DB274C((u_int64_t)str.c_str(), str.length(), (u_int64_t)szBuff);
	sub_100FB6004((u_int64_t)szSign, (u_int64_t)szBuff);
	strRet = szSign;
	return strRet;
}
int main(int argc, char* argv[])
{
	std::string sign = "";
	const char* data = "{\"h_model\":\"iPhone 7\",\"h_ch\":\"appstore\",\"phone\":\"15600000000\",\"no_hash_code\":1,\"region_code\":86,\"h_app\":\"zuiyou\",\"type\":\"reg\",\"h_ts\":1539152851066,\"h_av\":\"4.6.4\",\"h_nt\":1,\"h_did\":\"32086bc6014d1a8a447100a065a21edc\",\"h_m\":95849495,\"h_os\":1030000,\"token\":\"T4K2Nn_Be6gYozzVxZd0Liea7qDY1cn75TJlGmRz6cH7kwagjSU5JrAW2CmeBiPozxpOf\",\"h_dt\":1}";
	DWORD dwStartTime = GetTickCount();
	sign = calcSign(data);
	printf("sign: %s\r\n", sign.c_str());
	return 0;
}

