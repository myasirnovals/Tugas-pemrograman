#include <stdio.h>
#include <stdlib.h>
#include "jam.h"

void CreateJam(JAM *J, int HH, int MM, int SS) {
    (*J).Hour = HH;
    (*J).Minute = MM;
    (*J).Second = SS;
}

int GetHour(JAM J) {
    return (J.Hour);
}
int GetMinute(JAM J) {
    return (J.Minute);
}
int GetSecond(JAM J) {
    return (J.Second);
}

void SetHour(JAM *J, int newHour) {
    (*J).Hour = newHour;
}

void SetMinute(JAM *J, int newMinute) {
    (*J).Minute = newMinute;
}

void SetSecond(JAM *J, int newSecond) {
    (*J).Second = newSecond;
}

void ReadJam(JAM *J) {
    int hh,mm,ss;

    do {
        printf("Masukan nilai Jam: ");
        scanf("%d", &hh);
        printf("Masukan nilai Menit: ");
        scanf("%d", &mm);
        printf("Masukan nilai Detik: ");
        scanf("%d", &ss);
        printf("\n");
    } while (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59);

    CreateJam(&(*J), hh, mm, ss);
    
}

void PrintJam(JAM J) {
    printf("%d : %d : %d", J.Hour, J.Minute, J.Second);
}

boolean isValid(int H, int M, int S) {
    if(H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59) {
        return (true);
    } else {
        return (false);
    }
}

boolean JEQ(JAM J1, JAM J2) {
    if(J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second && J2.Second) {
        return (true);
    } else {
        return (false);
    }
}

boolean JLT(JAM J1, JAM J2) {
    if(J1.Hour < J2.Hour || J1.Minute < J2.Minute || J1.Second < J2.Second) {
        return (true);
    } else {
        return (false);
    }
}

boolean JGT(JAM J1, JAM J2) {
    if(J1.Hour > J2.Hour || J1.Minute > J2.Minute || J1.Second > J2.Second) {
        return (true);
    } else {
        return (false);
    }
}

void Reset(JAM *J) {
    (*J).Hour = 0;
    (*J).Minute = 0;
    (*J).Second = 0;
}

JAM NextDetik(JAM J) {
    JAM jamBaru;

    jamBaru = J;
    jamBaru.Second = jamBaru.Second + 1;
    if (jamBaru.Second > 59) {
        jamBaru.Second = 0;
        jamBaru.Minute = jamBaru.Minute + 1;
        if (jamBaru.Minute > 59) {
            jamBaru.Minute = 0;
            jamBaru.Hour = jamBaru.Hour + 1;
            if (jamBaru.Hour > 23) {
                jamBaru.Hour = 0;
            }
            
        }
        
    }

    return (jamBaru);
    
}

JAM NextNDetik(JAM J, int N) {
    int i;
    JAM jamBaru;

    jamBaru = J;
    if (N > 0 && N <= 86400) {
        for(i=1; i<=N; i++) {
            jamBaru = NextDetik(jamBaru);
        }
        
        return (jamBaru);
    }
    
}
long int Durasi(JAM Jaw, JAM Jakh) {
    long int detikAwl, detikAkh, result;

    detikAwl = JamToDetik(Jaw);
    detikAkh = JamToDetik(Jakh);
    result = detikAwl - detikAkh;

    if (result < 0) {
        result = result * (-1);
    }

    return (result);
}

long int JamToDetik(JAM J) {
    long int detik;

    detik = (J.Hour * 3600) + (J.Minute * 60) + J.Second;
    return (detik);
}