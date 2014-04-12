#ifndef __PIN_SKETCH_H
#define __PIN_SKETCH_H
#include <cstring>
#include <fstream>
#include <NTL/vec_ZZ.h>
#include <NTL/GF2XFactoring.h>
#include <NTL/GF2EXFactoring.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <NTL/ZZ.h>

using namespace std; // may be needed to compile on some platforms; may need to be removed on others
NTL_CLIENT

/************************ I/O ************************************/
void ReadSetParams(long &m, long &d, istream &infile);
void ReadSet(vec_GF2E & set, istream &infile, long m);

void ReadSSParams(long &m, long &d, GF2X &irrP, istream &infile) ;
void ReadSS(vec_GF2E & ss, istream &infile, long d);

void OutputSS(ostream &outfile, const vec_GF2E & syn, long d, const GF2X & irrP);
void OutputSetDifference(ostream &outfile, const vec_GF2E & setDifference);

/************************ BCH Syndrome Encoding/Decoding ***************/
void BCHSyndromeCompute(vec_GF2E &answer, const vec_GF2E & set, long d);
bool BCHSyndromeDecode(vec_GF2E &answer, const vec_GF2E & syndrome, long d);

/************************** 计算集合差并输出 *************************/
int DifferSet(string sketch, string testSet);

/************************ 从集合差恢复原始数据 *************************/
int ReadDiffer(std::vector<ZZ> *set ,ifstream& infile );
int ReadTestSet(std::vector<ZZ> *set, ifstream& infile );
void SetSymmetricDifference(ifstream& infile1,ifstream& infile2);
int RecSet(string differ, string testSet);

#endif
