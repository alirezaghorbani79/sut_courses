clear;clc;close all;

% transfer function model
s = tf('s');
P_pitch = (1.151*s+0.1774)/(s^3+0.739*s^2+0.921*s)


% state space model
A = [-0.313 56.7 0; -0.0139 -0.426 0; 0 56.7 0];
B = [0.232; 0.0203; 0];
C = [0 0 1];
D = [0];
pitch_ss = ss(A, B, C, D);

% open loop step response
t = [0:0.01:10];
figure(1);step(0.2*P_pitch,t);
axis([0 10 0 0.8]);
ylabel('pitch angle (rad)');
title('Open-loop Step Response');
grid;

% poles of open loop transfer function
openLoopPole = pole(P_pitch)
openLoopZero = zero(P_pitch)

% closed loop response with unit negative feedback
sys_cl = feedback(P_pitch, 1)
figure(2);
step(0.2*sys_cl);
grid;
ylabel('pitch angle (rad)');
title('Closed-loop Step Response');
figure(3);
margin(P_pitch);
grid;


%zeros and poles of closed loop transfer function
closeLoopPoles = pole(sys_cl)
closeLoopZeros = zero(sys_cl)

% create transfer finction with zpk()
R = 0.2/s;
Y = zpk(sys_cl*R)

figure(4);
rlocus(P_pitch);

% P PI PID Controller
controlSystemDesigner(P_pitch)