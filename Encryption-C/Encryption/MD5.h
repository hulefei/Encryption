//
//  MD5.h
//  QJRun
//
//  Created by Hanson on 14-4-28.
//
//

#ifndef __QJRun__MD5__
#define __QJRun__MD5__

#include <iostream>
#include <string>
using namespace std;

class MD5
{
public:
    typedef unsigned char uchar8; //make sure it is 8bit
    typedef char char8; //make sure it is 8bit
    MD5();
    
    void init();
    
    void UpdateMd5(const uchar8 input[], const int length);
    void UpdateMd5(const char8 input[], const int length);
    
    void Finalize();
    
    void ComputMd5(const uchar8 input[], const int length);
    void ComputMd5(const char8 input[], const int length);
    
    string GetMd5();
    
    void printMd5();
    
    
private:
    typedef unsigned int uint32;       //make sure it is 32 bit;
    typedef unsigned long long uint64; //make sure it is 64 bit;
    uint32 A, B, C, D;
    const static int blockLen_ = 64;    // 512/8
    //the remain after last updata (because md5 may be computed segment by segment)
    uchar8 remain_[blockLen_];
    int remainNum_ ;         // the number of remain_,  < 64
    uint64 totalInputBits_;
    uchar8 md5Result_[16];   //bit style md5 result,totally 128 bit
    char md5Result_hex_[33]; //hexadecimal style result; md5Result_hex_[32]='\0'
    bool isDone_;            // indicate the comput is finished;
    
    inline uint32 RotateLeft(const uint32 x, int n);
    inline uint32 F(const uint32 x, const uint32 y, const uint32 z);
    inline uint32 G(const uint32 x, const uint32 y, const uint32 z);
    inline uint32 H(const uint32 x, const uint32 y, const uint32 z);
    inline uint32 I(const uint32 x, const uint32 y, const uint32 z);
    inline void FF(uint32 &a, const uint32 b, const uint32 c, const uint32 d,
                   const uint32 Mj, const int s, const uint32 ti);
    inline void GG(uint32 &a, const uint32 b, const uint32 c, const uint32 d,
                   const uint32 Mj, const int s, const uint32 ti);
    inline void HH(uint32 &a, const uint32 b, const uint32 c, const uint32 d,
                   const uint32 Mj, const int s, const uint32 ti);
    inline void II(uint32 &a, const uint32 b, const uint32 c, const uint32 d,
                   const uint32 Mj, const int s, const uint32 ti);
    
    
    void UcharToUint(uint32 output[], const uchar8 input[], const unsigned int transLength);
    
    void FourRound(const uchar8 block[]);
    
    void LinkResult();
    
};

/*使用方法
 MD5 m;
 MD5::char8 str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 m.ComputMd5(str,sizeof(str) - 1);
 m.printMd5();
 
 MD5* md5 = new MD5();
 md5->init();
 md5->ComputMd5(str, sizeof(str) - 1);
 std::string md5string = md5->GetMd5();
 std::cout << "MD5 Value: " << md5string << endl;
 delete(md5);
 
 MD5 M;
 m.init();
 MD5::uchar8 str1[] = "ABCDEFGHIJKLMN";
 MD5::uchar8 str2[] = "OPQRSTUVWXYZabcdefghijk";
 MD5::uchar8 str3[] = "lmnopqrstuvwxyz";
 m.UpdateMd5(str1,sizeof(str1) - 1);
 m.UpdateMd5(str2,sizeof(str2) - 1);
 m.UpdateMd5(str3,sizeof(str3) - 1);
 m.Finalize();
 m.printMd5();
 */

/*java 验证
 String original = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 MessageDigest md = MessageDigest.getInstance("MD5");
 md.update(original.getBytes());
 byte[] digest = md.digest();
 StringBuffer sb = new StringBuffer();
 for (byte b : digest) {
 sb.append(String.format("%02x", b & 0xff));
 }
 
 System.out.println("original:" + original);
 System.out.println("digested(hex):" + sb.toString());
 */

#endif /* defined(__QJRun__MD5__) */
