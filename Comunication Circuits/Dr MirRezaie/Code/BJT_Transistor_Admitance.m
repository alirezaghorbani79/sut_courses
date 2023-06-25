clear;clc;close all;

Ytr = zeros(2, 2);
rPi = input('enter r_pi(ohm): ');
rO = input('enter r_o(ohm): ');
gm = input('enter gm(mS): ') * 10^-3;
cPi = input('enter c_pi(PF): ') * 10^-12;
cU = input('enter c_u(PF): ') * 10^-12;
cO = input('enter c_o(PF): ') * 10^-12;
freqin = input('enter f(MHz) or w: ');
freqCheack = input('is this hertz or radian? ');
if(lower(freqCheack) == 'h' || lower(freqCheack) == "hertz")
    f = freqin * 10^6;
    w = 2*pi*f;
elseif(lower(freqCheack) == 'r' || lower(freqCheack) == "radian")
    w = freqin;
    f = w/(2*pi);
end

Ytr(1, 1) = (1/rPi) + j * w * (cPi + cU);
Ytr(1, 2) = -j * w * cU;
Ytr(2, 1) = gm-j * w * cU;
Ytr(2, 2) = (1/rO) + j * w * (cO + cU);

disp(' ');
disp('Ytr: ');
disp(Ytr);
