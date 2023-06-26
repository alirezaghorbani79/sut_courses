clear;clc;close all;

A = input('enter amplitude: ');
w = input('enter frequency: ');
R = input('enter input impedance (ohm): ');
e = input('enter coefficients of e as a vector: ');
k1 = e(1);
k2 = e(2);
k3 = e(3);
cheak = input('mono frequency(1) or two frequency(2): ');

if(cheak == 1)
    G = 20 * log10(k1 + (3/4)*k3*(A^2));
    G0 = 20 * log10(k1);
    G1dB = G0 - 1;
    if(A == 0 && k3 <= 0)
       A = sqrt(0.145 * (k1/abs(k3))); 
    end
    Pi = 10*log10(((A/sqrt(2))^2) * ((10e3)/R) );
    Po = 10*log10( (((k1*A+(3/4)*k3*A^3)/(sqrt(2)))^2) * ((10e3)/(R)) );
    P1dB = G0 - 1 + 10*log10(((0.145*k1)/(2*abs(k3)))*((10e3)/(R)));
    
else
    Po = 10*log10((((k1*A)/(sqrt(2)))^2) * ((10e3)/R));
    Pw1 = 10*log10( (((k1*A+(9/4)*k3*A^3)/(sqrt(2)))^2) * ((10e3)/(R)) );
    P2w1w2 = 10*log10( ((((3/4)*k3*A^3)/(sqrt(2)))^2) * ((10e3)/(R)) );
    Pip = 10*log10((2/3)*((k1^3)/(abs(k3)))*((10e3)/R));
    Ppip = Pip - 9;
    P1db = Pip - 1063;
    AinPip = sqrt((4/3)*(k1/abs(k3)));
    AinPpip = sqrt((2/3)*(k1/abs(k3)));
end

