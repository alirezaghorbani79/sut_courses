clc;clear;close all;

s = tf('s');
G1 = tf([1],[0.0033 1]);
G2 = tf([1],[0.012 1]);
G = G1*G1*G2; %open loop

rlocus(G);
k_cr = 11.8;
w = 377;
T_cr = (2*pi)/w;
%---------------------------------------------
%Routh-Hurwitz
G3 = 1/G;
k_cr1 = ((0.0186*(9e-5))-(1.3e-7))/(1.3e-7);
w1 = sqrt((-(1+k_cr1))/(9e-5));
T_cr1 = (2*pi)/w1;