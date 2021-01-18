//
// Created by mateu on 16.01.2021.
//

#ifndef LABORATORIUM_ZBIORNIKPALIWA_H
#define LABORATORIUM_ZBIORNIKPALIWA_H


class ZbiornikPaliwa
{
private:
    unsigned int mFuel;
public:
    ZbiornikPaliwa(unsigned int AvailableFuel) : mFuel(AvailableFuel) {};
    unsigned int pobierz(unsigned int fuelForDownload);

};


#endif //LABORATORIUM_ZBIORNIKPALIWA_H
