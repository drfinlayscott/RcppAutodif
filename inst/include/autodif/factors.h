/*
 * $Id: factors.h 494 2012-06-13 20:41:16Z johnoel $
 *
 * Author: Anders Nielsen <anders@nielsensweb.org>
 * Copyright (c) 2010-2012 ADMB Foundation
 */
/**
 * \file
 * Support functions for factor. 
 */


#ifndef __FACTORS_H__
#define __FACTORS_H__

class factor
{
  int nlevels; 
  ivector idx;
  dvar_vector levels;
public:  
  factor(){nlevels=0;}
  void allocate(const ivector& v, dvar_vector & par);
  dvariable operator () (int i);
};

#endif
