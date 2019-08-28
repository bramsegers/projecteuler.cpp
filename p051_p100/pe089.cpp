#include "../util/strings.h"

int main(){

    int saved=0;

    for(string n:readFile("../files/pe089.txt")){
        
        string m=n;

        m=replaceAll(m,"IIIIV","I");
        m=replaceAll(m,"IIIV","II");
        m=replaceAll(m,"IIV","III");
        m=replaceAll(m,"IV","IIII");

        m=replaceAll(m,"IIIIX","VI");
        m=replaceAll(m,"IIIX","VII");
        m=replaceAll(m,"IIX","VIII");
        m=replaceAll(m,"IX","VIIII");

        m=replaceAll(m,"XXXXL","X");
        m=replaceAll(m,"XXXL","XX");
        m=replaceAll(m,"XXL","XXX");
        m=replaceAll(m,"XL","XXXX");

        m=replaceAll(m,"XXXXC","LX");
        m=replaceAll(m,"XXXC","LXX");
        m=replaceAll(m,"XXC","LXXX");
        m=replaceAll(m,"XC","LXXXX");

        m=replaceAll(m,"CCCCD","C");
        m=replaceAll(m,"CCCD","CC");
        m=replaceAll(m,"CCD","CCC");
        m=replaceAll(m,"CD","CCCC");

        m=replaceAll(m,"CCCCM","DC");
        m=replaceAll(m,"CCCM","DCC");
        m=replaceAll(m,"CCM","DCCC");
        m=replaceAll(m,"CM","DCCCC");

        m=replaceAll(m,"VIIII","IX");
        m=replaceAll(m,"IIII","IV");
        m=replaceAll(m,"LXXXX","XC");
        m=replaceAll(m,"XXXX","XL");
        m=replaceAll(m,"DCCCC","CM");
        m=replaceAll(m,"CCCC","CD");

        saved+=n.length()-m.length();
        
    }
    cout << saved;
}