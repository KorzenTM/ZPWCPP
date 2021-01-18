//
// Created by mateu on 16.01.2021.
//

#include "ZbiornikPaliwa.h"

unsigned int ZbiornikPaliwa::pobierz(unsigned int fuelForDownload)
{
   if (mFuel < fuelForDownload)
   {
       return 0;
   }
   mFuel -= fuelForDownload;
   return mFuel;
}
