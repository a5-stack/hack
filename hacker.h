#pragma once

#include <iostream>
#define MAXSIZE 4096

//不指定编码，使用时可能导致乱码
//#pragma execution_character_set("utf-8")  

//id指对应网站的端口号
// 服务器返回的结果是utf-8编码格式
int hk_404(char *id, char *response) ;

//恢复网站
int hk_restore(char *id, char *response);

//网页篡改攻击，para表示填充内容
int hk_tamper(char *id, char *para, char *response);

//查看攻击记录
int hk_record(char *id, char *response);

// 检查攻击是否成功
bool check_response(const char *response);

std::string UTF8ToGBK(const char* strUTF8);
void GBKToUTF8(std::string &strGBK);