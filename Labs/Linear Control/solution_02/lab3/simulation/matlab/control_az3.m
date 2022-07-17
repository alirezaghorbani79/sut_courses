clc;
clear;
close all;

g1 = tf(1,[0.0033 1]);
g2 = tf(1,[0.012 1]);
G = g1*g2;
rlocus(G);
figure;

gfeedback = feedback(G,0.1);
step(gfeedback,'b');
hold on;

gfeedback = feedback(G,0.2);
step(gfeedback,'g');
hold on;

gfeedback = feedback(G,0.3);
step(gfeedback,'r');
hold on;

gfeedback = feedback(G,0.478);
step(gfeedback,'c');
hold on;

gfeedback = feedback(G,5);
step(gfeedback,'y');
hold on;

gfeedback = feedback(G,8);
step(gfeedback,'k');
hold on;

legend('k=0.1','k=0.2','k=0.3','k=0.478','k=5','k=8');
%--------------------------------------------------------
figure;
gfeedback = feedback(G,4);
step(gfeedback,'m');
legend('k=4');
%--------------------------------------------------------
figure;
gfeedback = feedback(G,0.2,+1);
subplot(1,2,1);
step(gfeedback,'m');
legend('k=0.2');

gfeedback = feedback(G,2,+1);
subplot(1,2,2);
step(gfeedback,'r');
legend('k=2');
%--------------------------------------------------------
figure;
rlocus(-G);
%--------------------------------------------------------
figure;
gfeedback = feedback(G,1,+1);
step(gfeedback,'y');
legend('k=1');
