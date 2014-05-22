//
//  main.cpp
//  Encryption
//
//  Created by Hanson on 14-5-14.
//  Copyright (c) 2014年 Hanson. All rights reserved.
//

#include <iostream>
#include "MD5.h"
#include "sha1.h"

void md5test();
void sha1test();

int main(int argc, const char * argv[]) {
    
    md5test();
    sha1test();
    
    return 0;
}

void sha1test() {
#define BYTES "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	SHA1* sha1 = new SHA1();
	sha1->addBytes( BYTES, strlen( BYTES ) );
	unsigned char* digest = sha1->getDigest();
	sha1->hexPrinter( digest, 20 );
    std::cout << std::endl;
	delete sha1;
	free( digest );
}

void md5test() {
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
}

