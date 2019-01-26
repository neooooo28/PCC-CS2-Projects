#ifndef CONVERT_H
#define CONVERT_H

void FtIn_to_MetersCm(int feet, double inches, int& meters, double& cm);
void MetersCm_to_FtIn(int meters, double cm, int& feet, double& inches);
void LitersMl_to_GalOz(int liters, double ml,  int& gal, double& oz);
void GalOz_to_LitersMl(int gal, double oz, int& liters, double& ml);
void LbsOz_to_KgGrams(int lbs, double oz,      int& kg, double& grams);
void KgGrams_to_LbsOz(int kg, double grams, int& lbs, double& oz);

void Convert(int A, double a,           // Input  : LHS Conversion
             int &B, double &b,         // Output : RHS Result
             int aInA,                  // LHS    : amt of smaller unit into bigger
             double bPERa,              // Process: Convert
             int bInB);                 // RHS    : amt of smaller unit into bigger


#endif // CONVERT_H
