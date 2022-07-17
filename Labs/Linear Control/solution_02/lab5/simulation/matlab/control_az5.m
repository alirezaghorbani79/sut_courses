clc;clear;close all;

s = tf('s');
A = (0.0033*s+1);
B = (0.012*s+1);
G = 1/(A*B);
step(feedback(G,1));
figure;
step(feedback(20*G,1));
figure;
bode(20*G);
%---------------------------
a = 4.2;
T = 5e-4;
C = tf([a*T 1],[T 1]);
figure;
bode(20*G*C);
figure;
step(feedback(20*G*C,1));