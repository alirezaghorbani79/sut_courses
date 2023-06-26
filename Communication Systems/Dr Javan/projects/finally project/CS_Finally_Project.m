clear;clc;close all;

% ====== Names of group members ======
% ====== Matin Golpaygani ============
% ====== Alireza Ghorbani ============
% ====== Reza Adinepour   ============


%% Frequency MODULATION of Triangular Signal
t = -0.04:1.e-4:0.04;
Ta = 0.01;
fc = 100; % Frequency of carrier (Hz)
fs = 1100; % Sampling Rate (Hz)    best choise: fs = 1000, fc = 200;
x = msg1(t, Ta); % Calling Function to Generate Message Signal
%plot(t, msg);


%% Add Noise
snr = 15;
x_n = awgn(x, snr, 'measured');


%% MODULATION   
fDev = 90; % is the frequency deviation of the modulated signal.
y = fmmod(x, fc, fs, fDev);
y_n = fmmod(x_n, fc, fs, fDev);
% plot(t, fm)


%% De-MODULATION
z = fmdemod(y, fc, fs, fDev);
z_n = fmdemod(y_n, fc, fs, fDev);
% plot(z)

%% Filter Noise
wPass = 0.08;
% x_f = lowpass(x_n, wPass, fs);
z_f = lowpass(z_n, wPass, fs);
% plot(t, x_f)

%% Plot Result
figure(1);
subplot(4, 2, 1);
plot(t, x);
title('Message Signal');
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, 2);
plot(t, x_n, 'r');
title(['Message Signal With Noise - SNR=', num2str(snr)]);
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, 3);
plot(t, y);
title('FM-Signal');
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, 4);
plot(t, y_n, 'r');
title('FM-Signal with noise');
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, 5);
plot(t, z);
title('Demodulated Mesage Signal With Zero Crosing Detector');
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, 6);
plot(t, z_n, 'r');
title('Demodulated noisy Mesage Signal With Zero Crosing Detector');
xlabel('time');
ylabel('Magnitude');
subplot(4, 2, [7 8]);
plot(t, z_f, 'k');
title('Detect Noise With LowPass Filter');
xlabel('time');
ylabel('Magnitude');