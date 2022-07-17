clc;clear;close all;

s = tf('s');
A = (0.0033*s+1);
B = (0.012*s+1);
G = 1/(A*B);

%k = 20;
step(feedback(20*G,1));
figure;
bode(20*G);

a = 0.232;
T = 0.1567;
C = tf([a*T 1],[T 1]);

figure;
step(feedback(20*C*G,1));
figure;
bode(20*C*G);