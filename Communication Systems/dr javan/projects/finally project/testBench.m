clear;clc;close all;
% 
fs = 1000; 
fc = 200;  
% t = -0.04:1.e-4:0.04;
% Ta = 0.01;
% x = msg1(t, Ta);
snr = 20;

t = (0:0.01:15)';
x = sawtooth(t);

x_n = awgn(x, snr, 'measured');
plot(t, x_n, 'r');
hold on;
plot(t, x, 'b');
title(['SNR = ', num2str(snr)])




fDev = 100;
y = fmmod(x_n, fc, fs, fDev);
z = fmdemod(y, fc, fs, fDev);

plot(t, x,'b');
hold on;
plot(t, z, 'r');
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal','Demodulated Signal')








