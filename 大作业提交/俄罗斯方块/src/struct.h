/*************************************************************************
    > File Name: struct.h
	> Orgnization:Tsinghua University
    > Author: 钟凯 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.7 星期四
 ************************************************************************/
#pragma once
using namespace std;

enum Direction//运动方向枚举
{
	LEFT =0,
	RIGHT =1,
	DOWN =2
};

enum State//朝向枚举
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3
};

struct Position//坐标数据
{
	int row;
	int column;
};
