clear;clc;close all;

% ====== Names of group members ======
% ====== Matin Golpaygani ============
% ====== Alireza Ghorbani ============
% ====== Reza Adinepour   ============
    

% Inputs of AM_Modulation Function (m, fm, Am, fc, Ac) for Example: AM_Modulation(1, 2000, 5, 30000, 5)
% m = AM modulation Scale. (0 < m < 1 (for example: m = 1 means 100% modulation))
% fm = Message Signal Frequency
% Am = Amplitude of Message signal
% fc = Carrier Frequency
% Am = Amplitude of Carrier signal


% Inputs of EnvelopeDetection Function (fm, fc, ka) for Example: EnvelopeDetection(2000, 30000, 1)
% fm = Message Signal Frequency
% fc = Carrier Frequency
% ka = Sensitivity Factor

m = 1;
Ka = 1;
Fm = 2000;
Am = 5;
Fc = 15*Fm;
Ac = Am/m;

AM_Modulation(m, Fm, Am, Fc, Ac);
EnvelopeDetection(Fm, Fc, Ka);