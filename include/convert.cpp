#include <iostream>
#include "convert.h"

using namespace std;

//Length
void FtIn_to_MetersCm(int feet, double inches, int& meters, double& cm){
    //1ft = 12in --> 1in = 2.54cm --> 100cm = 1m
    const int FEET_TO_IN = 12;      //a in A
    const double IN_TO_CM = 2.54;   //b per a
    const int M_TO_CM = 100;        //b in B
    Convert(feet, inches, meters, cm, FEET_TO_IN, IN_TO_CM, M_TO_CM);
    cout<<meters<<" meters and "<<cm<<" centimeters."<<endl;
}
void MetersCm_to_FtIn(int meters, double cm, int &feet, double &inches) {
    //1m = 100cm --> 1cm = 0.3937007874in --> 1 ft = 12in
    const int M_TO_CM = 100;        //a in A
    const double CM_TO_IN = 0.3937007874; //b per a
    const int FEET_TO_IN = 12;      //b in B
    Convert(meters, cm, feet, inches, M_TO_CM, CM_TO_IN, FEET_TO_IN);
    cout<<feet<<" feet and "<<inches<<" inches."<<endl;
}
//Volume
void LitersMl_to_GalOz(int liters, double ml, int &gal, double &oz){
    //1l = 1000ml --> 1ml = 0.033814oz --> 128oz = 1gal
    const int L_TO_ML = 1000;           //a in A
    const double ML_TO_OZ = 0.033814;   //b per a
    const int GAL_TO_OZ = 128;          //b in B
    Convert(liters, ml, gal, oz, L_TO_ML, ML_TO_OZ, GAL_TO_OZ);
    cout<<gal<<" gallons and "<<oz<<" ounces."<<endl;
}
void GalOz_to_LitersMl(int gal, double oz, int &liters, double &ml) {
    //1gal = 128oz --> 1oz = 29.57355ml --> 1000ml = 1l
    const int GAL_TO_OZ = 128;          //a in A
    const double OZ_TO_ML = 29.57355;   //b per a
    const int L_TO_ML = 1000;           //b in B
    Convert(gal, oz, liters, ml, GAL_TO_OZ, OZ_TO_ML, L_TO_ML);
    cout<<liters<<" liters and "<<ml<<" milliliters."<<endl;
}
//Mass
void LbsOz_to_KgGrams(int lbs, double oz, int &kg, double &grams) {
    //1lb = 16oz --> 1oz = 28.3495g --> 1000g = 1kg
    const int LB_TO_OZ = 16;            //a in A
    const double OZ_TO_G = 28.3495;     //b per a
    const int KG_TO_G = 1000;           //b in B
    Convert(lbs, oz, kg, grams, LB_TO_OZ, OZ_TO_G, KG_TO_G);
    cout<<kg<<" kilograms and "<<grams<<" grams."<<endl;
}
void KgGrams_to_LbsOz(int kg, double grams, int& lbs, double& oz) {
    //1kg = 1000g --> 1g = 0.03527oz --> 16oz = 1lb
    const int KG_TO_G = 1000;           //a in A
    const double G_TO_OZ = 0.03527;     //b per a
    const int LB_TO_OZ = 16;            //b in B
    Convert(lbs, oz, kg, grams, KG_TO_G, G_TO_OZ, LB_TO_OZ);
    cout<<lbs<<" pounds and "<<oz<<" ounces."<<endl;
}

void Convert(int A, double a,           // Input  : LHS Conversion
             int &B, double &b,         // Output : RHS Result
             int aInA,                  // LHS    : amt of smaller unit into bigger
             double bPERa,              // Process: Convert
             int bInB)                  // RHS    : amt of smaller unit into bigger
{
    a = a + (A*aInA);
    b = a * bPERa;
    B = b / bInB;
    b = ((b/bInB) - B)*bInB;

    //    DEBUG for individual components
    //    cout<<"A = "<<A<<endl;
    //    cout<<"a = "<<a<<endl;
    //    cout<<"aInA = "<<aInA<<endl;
    //    cout<<"bPERa = "<<bPERa<<endl;
    //    cout<<"bInB = "<<bInB<<endl;
    //    cout<<"B = "<<B<<endl;
    //    cout<<"b = "<<b<<endl;
}
