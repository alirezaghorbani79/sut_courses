clc;clear;close all;

sys1 = tf(-1,[0.0033 1]);
sys2 = tf(2,[0.012 1]);
sys = parallel(sys1,sys2);

step(sys2*0.5);
hold on;
step(sys);

figure;
rlocus(sys);

figure;
bode(sys2);
hold on;
bode(sys,'r');
legend('sys2','sys');