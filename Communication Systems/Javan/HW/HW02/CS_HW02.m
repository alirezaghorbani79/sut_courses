clear;clc;close all


%H = @(f) ((f>0)&(f<=150)).*f.*exp(-j.*5.*pi*f.*f) + ((f>150)&(f<=400)).*3.*exp(-j.*10.*pi*f) + ((f>400)&(f<=1000)).*(10./(f)).*exp(-j.*20.*pi*f)...
 %   + ((f>1000)&(f<=1400)).*12.*exp(-j.*30.*pi*f)
 
%AmpH = abs(H(f))
%plot(f, AmpH)


% f = 0:14000;
% H = @(f) ((f>0)&(f<=1500)).*exp(-j.*5.*pi*f) + ((f>1500)&(f<=5000)).*3.*f.*exp(-j.*10.*pi*f) + ((f>5000)&(f<=10000)).*(10./(f)).*exp(-j.*20.*pi*f + 12)...
%     + ((f>10000)&(f<=14000)).*12.*exp(-j.*30.*pi*f)
% 
% AmpH = abs(H(f))
% plot(f, AmpH)


% f = 0:14000;
% H = @(f) ((f>0)&(f<=150)).*(f.*exp(-j*5*pi.*f.*f)) + ((f>150)&(f<=400)).*(3*exp(-j*10*pi.*f))...
%     + ((f>400)&(f<=1000)).*(10*exp(-j.*(20*pi.*f+(pi/10)))) + ((f>1000)&(f<=1400)).*(12*exp(-j*30*pi.*f));
% AmpH = abs(H(f))
% plot(f, AmpH)


w=0:15;
T = 1;
a = 0.01;
H = @(w) exp(-j.*w*T).*(1+2*a*cos(w.*T));
AmpH = abs(H(w))
Ang = angle(H(w))
figure(1);plot(w, AmpH)
figure(2);plot(w, Ang)
